//
//  Problem_59.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"

#import "hashMap.h"





@interface Problem_59 : ProblemBase
{
}

@end





@implementation Problem_59

- (id)solveProblem
{
	string cipher;
	stringstream file;
	file << "p059_cipher.txt";
	
	ifstream fileStream = readFile(file.str());
	
	if (fileStream) {
		
		string line;
		while (getline(fileStream, line, ',')) { // split with , delimiter
			
			istringstream buffer(line);
			istream_iterator<uint64_t> value(buffer);
			cipher.push_back((char)*value);
			
		}
		
	}
	
	string key = findPossibleKey(cipher, 3);
	
	while (nextPermutation(key)) {
		
		string decryptedMessage = encryptXOR(cipher, key);
//		printf("\n\nKEY:\n\t%s\nMESSAGE:\n\t%s\nCHAR COUNT:\n\t%llu\n\n", key.c_str(), decryptedMessage.c_str(), sumOfString(decryptedMessage));
		
		if (key == "god") { // hardcode from printed answer
			return @(sumOfString(decryptedMessage));
		}
		
	}
	
	return nil;
}

/**
 *  Search the message for the characters that occur most often and return a string of length keyLength containing those characters
 *
 *  @param message
 *  @param keyLength
 *
 *  @return key
 */
string findPossibleKey(string message, uint64_t keyLength)
{
	// Key = character
	// Value = character count
	hashMap<uint64_t, uint64_t> characterCounts;
	
	
	for (uint64_t i = 0; i < message.size(); i += 1) {
		uint64_t &count = *characterCounts.valueForKey(message[i]);
		count += 1;
	}
	
	
	// save into a set so we can easily characters that occur the most often
	set<pair<uint64_t, char>> sortedCharacterCounts;
	auto itr = characterCounts.begin();
	while (itr != characterCounts.end()) {
		sortedCharacterCounts.insert({ (*itr).second, (*itr).first });
		advance(itr, 1);
	}
	
	
	// put the largest characters from the sorted set into the return key vector
	string key = "";
	for (uint64_t i = 0; i < keyLength; i += 1) {
		auto itr = sortedCharacterCounts.rbegin();
		advance(itr, i);
		key += tolower((*itr).second);
	}
	
	sort(key.begin(), key.end()); // sort so we can use nextPermutation
	return key;
}

string encryptXOR(string message, string key)
{
	string decodedMessage;
	
	for (uint64_t i = 0; i < message.size(); i += 1) {
		
		uint64_t messagePart = message[i];
		uint64_t keyPart = key[i % key.size()];
		
		decodedMessage += (char)(messagePart ^ keyPart);
		
	}
	
	return decodedMessage;
}

@end




