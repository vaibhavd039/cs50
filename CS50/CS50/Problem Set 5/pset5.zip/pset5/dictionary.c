/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/
 
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"
 
#define OFFSET 97
 
typedef struct node
{
    // flag to check if word exists or not
    bool is_word;
     
    // array for alphabets and special character
    struct node* children[27];
}
node;
 
// size of dictionary
unsigned int dictionarySize = 0;
 
// root node
struct node* root = NULL;  
 
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    unsigned int letter = '0';
    unsigned int index = 0;
    node* nextNode = root;
     
    // read a word 
    while(letter != '\0')
    {
        letter = word[index];
         
        // switch to lowercase
        if (letter <= 90 && letter >= 65) 
        {
            letter |= 32;
        }
         
        // allow alphabets or apostrophe
        if ((letter >= 97 && letter <= 122) || (letter == '\''))
        {
            // apostrophe is placed at the end of the alphabet
            if (letter == '\'')
            {
                letter = 26 + OFFSET;
            }
                 
            if (nextNode->children[letter - OFFSET] == NULL)
            {
                return false;
            }
            else
            {
                nextNode = nextNode->children[letter - OFFSET];
            }
        }
        index++;
    }
    return nextNode->is_word;
}
 
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary file in read mode
    FILE* fpr = fopen(dictionary, "r");
     
    if (fpr == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    root = (node*) malloc(sizeof(node));
     
    unsigned int letter = 0;
    node* nextNode = root;
     
    while (letter != EOF)
    {
        letter = fgetc(fpr);
        if (letter != '\n' && letter != EOF)
        {
            if (letter == '\'')
            {
                letter = 26 + OFFSET;
            }
                 
            if (nextNode->children[letter - OFFSET] == NULL)
            {
                nextNode->children[letter - OFFSET] 
                    = (node*) malloc(sizeof(node));
            }
            nextNode = nextNode->children[letter - OFFSET];
        }
        // Condition for new word
        else if (letter == '\n') 
        {
            nextNode->is_word = true;
            dictionarySize++;
            nextNode = root;
        }
    }
    fclose(fpr);
     
    return true;
}
 
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return dictinary size
    return dictionarySize;
}
 
/**
 * recursively removes each node from memory
 */
void unloadNode(node* nextNode)
{
    for (int i = 0; i < 26; i++)
    {
        if (nextNode->children[i] != NULL)
        {
            unloadNode(nextNode->children[i]);
        }
    }
     
    // free this node
    free(nextNode);
}
 
/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // pass root node to unload dictinary from memory
    unloadNode(root);
     
    return true;
}