# ---------------------------------------
# CNN para Classificação de Imagens - Gatos vs Cachorros
# Dataset: https://www.kaggle.com/datasets/shaunthesheep/microsoft-catsvsdogs-dataset
# ---------------------------------------

import os
os.environ['TF_ENABLE_ONEDNN_OPTS'] = '0'

import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix

import tensorflow as tf
from keras import layers, models
from keras.utils import load_img, img_to_array

# --- Configurações ---
verbose = True
img_size = (150, 150)
batch_size = 32
max_images_per_class = 500

# --- Diretórios ---
dir_cat = r"IA\LISTAS\Lista_12\PetImages\Cat"
dir_dog = r"IA\LISTAS\Lista_12\PetImages\Dog"

# --- Função para carregar imagens ---
def carregar_imagens(pasta, rotulo, limite=1000):
    imagens, rotulos = [], []
    for i, nome_arquivo in enumerate(os.listdir(pasta)):
        if i >= limite:
            break
        caminho = os.path.join(pasta, nome_arquivo)
        try:
            img = load_img(caminho, target_size=img_size)
            img = img_to_array(img) / 255.0
            imagens.append(img)
            rotulos.append(rotulo)
        except Exception as e:
            continue  # Ignora imagens corrompidas
    return imagens, rotulos

# --- Carregamento dos dados ---
cat_imgs, cat_labels = carregar_imagens(dir_cat, 0, max_images_per_class)
dog_imgs, dog_labels = carregar_imagens(dir_dog, 1, max_images_per_class)

if verbose:
    print(f"[INFO] Imagens carregadas - Gatos: {len(cat_imgs)}, Cachorros: {len(dog_imgs)}")

X = np.array(cat_imgs + dog_imgs)
y = np.array(cat_labels + dog_labels)

# --- Divisão dos dados ---
X_train, X_temp, y_train, y_temp = train_test_split(X, y, test_size=0.3, stratify=y, random_state=42)
X_val, X_test, y_val, y_test = train_test_split(X_temp, y_temp, test_size=0.5, stratify=y_temp, random_state=42)

if verbose:
    print(f"[INFO] Divisão dos dados - Treino: {len(X_train)}, Validação: {len(X_val)}, Teste: {len(X_test)}")

# --- Data Augmentation ---
train_aug = tf.keras.preprocessing.image.ImageDataGenerator(
    rotation_range=40,
    width_shift_range=0.2,
    height_shift_range=0.2,
    shear_range=0.2,
    zoom_range=0.2,
    horizontal_flip=True
)

val_aug = tf.keras.preprocessing.image.ImageDataGenerator()

# --- Geradores ---
train_gen = train_aug.flow(X_train, y_train, batch_size=batch_size)
val_gen = val_aug.flow(X_val, y_val, batch_size=batch_size)
test_gen = val_aug.flow(X_test, y_test, batch_size=batch_size, shuffle=False)

# ---------------------------------------
# Construção do Modelo
# ---------------------------------------

model = models.Sequential([
    layers.Input(shape=(150, 150, 3)),
    layers.Conv2D(32, (3, 3), activation='relu'),
    layers.MaxPooling2D(2, 2),

    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D(2, 2),

    layers.Conv2D(128, (3, 3), activation='relu'),
    layers.MaxPooling2D(2, 2),

    layers.Flatten(),
    layers.Dense(512, activation='relu'),
    layers.Dense(1, activation='sigmoid')
])

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

if verbose:
    print("[INFO] Arquitetura do modelo:")
    model.summary()

# --- Treinamento ---
history = model.fit(
    train_gen,
    epochs=10,
    validation_data=val_gen
)

# ---------------------------------------
# Avaliação
# ---------------------------------------

# --- Curvas de desempenho ---
plt.figure(figsize=(12, 5))

plt.subplot(1, 2, 1)
plt.plot(history.history['accuracy'], label='Treino')
plt.plot(history.history['val_accuracy'], label='Validação')
plt.title('Acurácia')
plt.xlabel('Época')
plt.ylabel('Acurácia')
plt.legend()

plt.subplot(1, 2, 2)
plt.plot(history.history['loss'], label='Treino')
plt.plot(history.history['val_loss'], label='Validação')
plt.title('Perda')
plt.xlabel('Época')
plt.ylabel('Loss')
plt.legend()

plt.tight_layout()
plt.show()

# --- Avaliação final ---
test_gen.reset()
preds = model.predict(test_gen)
y_pred = (preds > 0.5).astype(int).flatten()

if verbose:
    print("\n[RESULTADOS] Classificação:")
    print(classification_report(y_test, y_pred, target_names=["Cat", "Dog"]))
    print("\nMatriz de Confusão:")
    print(confusion_matrix(y_test, y_pred))
    print(f"\nAcurácia (manual): {np.mean(y_pred == y_test):.4f}")
    print(f"Acurácia (Keras): {model.evaluate(test_gen)[1]:.4f}")

# ---------------------------------------
# Teste com Imagens Novas
# ---------------------------------------

def testar_imagem(path):
    try:
        img = load_img(path, target_size=img_size)
        img_array = img_to_array(img) / 255.0
        img_array = np.expand_dims(img_array, axis=0)
        pred = model.predict(img_array)[0][0]
        classe = "Dog" if pred > 0.5 else "Cat"
        print(f"Imagem: {path} | Predição: {classe} ({pred:.2f})")
    except Exception as e:
        print(f"Erro ao processar {path}: {e}")

# --- Exemplos ---
testar_imagem(r"IA\LISTAS\Lista_12\PetImages\Cat\500.jpg")
testar_imagem(r"IA\LISTAS\Lista_12\PetImages\Dog\500.jpg")
