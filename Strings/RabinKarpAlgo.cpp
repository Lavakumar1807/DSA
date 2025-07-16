/*
  The Rabin Karp algorithm matches the hash value of the pattern with the hash value of the current substring of text, and if the hash values match then only it starts matching individual characters. 
  So Rabin Karp algorithm needs to calculate hash values for the following strings.
   -> Pattern itself
   -> All the substrings of the text of length m which is the size of pattern.

   The hash value is calculated using a rolling hash function, which allows you to update the hash value for a new substring by efficiently removing the contribution of the old character and adding the contribution of the new character. 
   This makes it possible to slide the pattern over the text and calculate the hash value for each substring without recalculating the entire hash from scratch.
*/