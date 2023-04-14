#include <stdio.h>
#include <stdlib.h>

// RecordType
typedef struct RecordType {
  int id;
  char name;
  int order;
  struct RecordType *next; 
  
    // create a next pointer (for linkedlist structure)
} RecordType;

// Fill out this structure
typedef struct HashType {

  RecordType *pData; 
  int isOccupied; 

// create a pointer to a RecordType
} HashType;

// Compute the hash function
int hash(int x, int tableSize) {

  int value = x % tableSize; 
  
  return value; 
  // hash function is x % tableSize
}

// parses input file to an integer array
int parseData(char* inputFileName, RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (RecordType*) malloc(sizeof(RecordType) * dataSz);
		// Implement parse data block
  
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%05d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

// insert record into the hash table
// display records in the hash structure
// skip the indices which are free
// the output will be in the format:
// index x -> id, name, order -> id, name, order ....
void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{
	int i;

	for (i=0;i<hashSz;++i) {

    if(pHashArray[i].isOccupied == 1) {
      printf("index %d -> %d, %c, %d\n", i, pHashArray[i].pData->id, pHashArray[i].pData->name, pHashArray[i].pData->order);
    }

   
  }
		// if index is occupied with any records, print all
}

    // for each entry in the table
        // print the contents in that index
        // The output should look like this (for example): "Index 1 -> 21715, Q, 16 -> 28876, a, 26 -> NULL"


int main(void)
{
    RecordType *pRecords;
    int recordSz = 0;

    recordSz = parseData("input.txt", &pRecords);
    printRecords(pRecords, recordSz);

  int hashSize = recordSz; 
  HashType *hashTable = calloc(hashSize, sizeof(HashType));

  // for (int i = 0; i < hashSize; i++) {
  //   hashTable[i
  // }

  displayRecordsInHash(hashTable, hashSize); 

    // Initialize the hash table
    // create a variable hashTableSize and assign it a value
    // initialize a hashTable, use calloc (so everything is assigned to NULL)
    // for each record in pRecords, insert it into the hash table using the           insertRecord function
    // call the display records function
    // free all the allocated memory
    
  
  
  for (int i = 0; i < recordSz; ++i)
    {
        int index = hash(pRecords[i].id, recordSz);// Compute hash index
        while (hashTable[index].isOccupied == 1) // Linear probing to handle collisions
        {
            index = (index + 1) % hashSize; // Move to next index
        }
        hashTable[index].pData = &pRecords[i]; // Set pointer to record
        hashTable[index].isOccupied = 1; // Set occupied flag
    }
  displayRecordsInHash(hashTable, hashSize);

  free(pRecords); 
  free(hashTable); 

  return 0;
}
