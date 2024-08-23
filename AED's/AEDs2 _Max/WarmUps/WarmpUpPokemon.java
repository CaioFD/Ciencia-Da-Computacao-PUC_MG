public class WarmpUpPokemon {
    private static void InsertionSort( String[] array )
    {
        for( int x = 1; x < array.length; x++ ) 
        {
            String temp = array[x];
            int y = x - 1;
            while( (y >= 0) && (array[x].compareTo(temp) > 0) )
            {
                array[y + 1] = array[y];
                y--;
            } 
            array[y + 1] = temp;
        } 
    } // função de ordenar

    public static void main(String[] args){
        int quant = 0;
        String[] PokemonsCapturados;
        int totalPokemons = 151;

        quant = MyIO.readInt();
        PokemonsCapturados = new String[quant];// ler a quantidade de pokemons

        for(int i = 0; i <= quant; i++ ){
            String NomeDoPokemon = MyIO.readLine();
            PokemonsCapturados[i] = NomeDoPokemon;
        }//ler o nome do pokemon e guardar ele 

        InsertionSort(PokemonsCapturados);//ordenar 

        for(int i = 1; i<= quant; i++){
            int y = i;
            while(y < quant && PokemonsCapturados[y].equals(PokemonsCapturados[y-1])){
                y++;
            }
            i = y;
            totalPokemons--;
        } // subtrair do total de pokemons se for igual, enquanto for igual nao subtraio

        MyIO.println("Faltam" + totalPokemons + "Pokemons.");
        }
}
