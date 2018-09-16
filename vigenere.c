//IMPLEMENTATION OF THE VIGENERE CIPHER (WITH SLIGHT MODIFICATIONS)
//LE CHIFFRE INDECHEFFERABLE

/*
STEPS TO ENCIPHER
1. INPUT KEY
2. REMOVE DUPLICATE CHARACTERS AND SPACES FROM KEY
3. USE KEY TO BUILD THE ENTIRE VIGENERE KEYSPACE
4. INPUT THE ENTIRE MESSAGE TO BE ENCODED BUT DONT SAVE IT INTO ANY MEMORY - (THIS METHOD AIMS AT SAVING SPACE)
5. INSTEAD TAKE IN ONE CHARACTER FROM THE stdin BUFFER AND ENCODE IT AND OUTPUT IT.
6. THEN TAKE THE NEXT CHARACTER AND ENCODE THAT TOO
7. REPEAT UNTIL THE ENTIRE MESSAGE IS ENCODED

*/


#include<stdio.h>
#include<math.h>
#include<string.h>

//removeduplicates REMOVES ALL THE DUPLICATE LETTERS(THAT IS, IT REMOVES 2ND, 3RD ETC INSTANCES OF A LETTER FROM A STRING.)
//IT TAKES THE POINTER TO THE FIRST ELEMENT OF THE CHARACTER ARRAY AS INPUT.
void remove_duplicates(char *array_start)
{
        int i = 0;
        int alphabet_number;                                                    //This is a number b/w 0 and 25 inclusive. used as an index for alphabet_counter[]
        int alphabet_counter[26] = {0};
        char *array_cursor, *deletion_cursor;

        array_cursor = array_start+i;                                           // array_cursor initialisation.

        while(*(array_cursor) != '\0')                                          // as long as there are letters remaining in the key
        {
                array_cursor = array_start+i;
                alphabet_number = *(array_cursor) - 'A';
                alphabet_counter[alphabet_number] += 1;

                if(alphabet_counter[alphabet_number] > 1)
                {
                        //DELETE THAT ELEMENT - SINCE WE ARE USING POINTERS TO IDENTIFY THE ELEMENTS OF THE ARRAY,
                        //WE ARE GOING TO DO THIS - array_start+i points to that element. move all the elements to the left of it
                        //one place to the left. dont forget the '\0' character.
                        deletion_cursor = array_cursor;
                        while( *(deletion_cursor) != '\0' )
                        {
                                *(deletion_cursor) = *(deletion_cursor+1);
                                deletion_cursor += 1;
                        }
                        i--;                                                    //When an element is deleted from the key, the next letter is put in its place.
                }                                                               //then we should also check this new letter(which is in the place we just checked)
                i++;
        }
}

void build_keyspace(char *keyspace_start, char *key_start)
{
        //TO BUILD THE KEYSPACE - Take the cleankey and insert that key in the first n cells of first row of the keyspace. then fill in the remaining letters of that row
        //each row only gets one instance of any one letter. To do this maintain another instance of the alphabets_counter as used in remove_duplicates.
        const int number_of_rows = 26, number_of_columns = 26;
        int row_number = 0, column_number = 0;
        int alphabet_counter[26] = {0};
        int alphabet_number;
        int *array_cursor, *key_cursor;
        int char next_letter = 'A';

        //INNER LOOP - TO FILL IN ONE ROW

        while(*(key_cursor) != '\0')
        {
                arraycursor = keyspace_start + ((row_number) * number_of_columns) + (column_number);
                *(array_cursor) = *(key_cursor);                                //Load the letter of the key into the key_space matrix
                alphabet_number = *(array_cursor) - 'A';
                alphabet_counter[alphabet_number] = 1;                          //alphabet_number is index 0.
                key_cursor += 1;
                column_number += 1;
        }


        alphabet_number = 0;
        while(column_number < number_of_columns)
        {
                arraycursor = keyspace_start + ((row_number) * number_of_columns) + (column_number);
                if(alphabet_counter[alphabet_number] == 0)
                {
                        *(array_cursor) = next_letter;
                        alphabet_counter[alphabet_number] = 1;
                }
                column_number++;
                alphabet_number++;
                next_letter++;
        }


}


int main()
{
        char keyspace[26][26];
        char key[30];

        printf("Enter Key(maximum 30 digits) for encryption: ");
        scanf("%s", key);
        remove_duplicates(key);




        return 0;
}
