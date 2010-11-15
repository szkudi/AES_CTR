/*
 * AES.h
 *
 *  Created on: 14-11-2010
 *      Author: szkudi
 */

#ifndef AES_CTR_H_
#define AES_CTR_H_

#include <stdint.h>
#include "matrices.h"
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void KeyExpansion();
void AddRoundKey(int round);
void SubBytes();
void ShiftRows();
void MixColumns();
void Cipher();

void InvSubBytes();
void InvShiftRows();
void InvMixColumns();
void InvCipher();

//	void Cipher_CTR(uint8_t* input, uint8_t* output);
//	void InvCipher_CTR(uint8_t* input, uint8_t* output);
uint8_t* Cipher_CTR(uint8_t* input);
uint8_t* InvCipher_CTR(uint8_t* input);


uint8_t getSBoxValue(int num);
uint8_t getSBoxInvert(int num);

void setNr(int Nr);
void setNk(int Nk);

void copyKey(uint8_t *key);
void copyInput(uint8_t* input, int cnt);

void printOutput();



void copyOutToIn();

/*
 * Nk - Number of 32 bit words in Key;
 * Nr - Number of rounds in cypher;
 * Nb - The number of columns comprising a state in AES;
 */
int Nb, Nr, Nk;

// in - it is the array that holds the plain text to be encrypted.
// out - it is the array that holds the output CipherText after encryption.
// state - the array that holds the intermediate results during encryption.
uint8_t in[16], out[16], state[4][4];

// The array that stores the round keys.
uint8_t RoundKey[240];

// The Key input to the AES Program
uint8_t Key[32];


#endif /* AES_CTR_H_ */







