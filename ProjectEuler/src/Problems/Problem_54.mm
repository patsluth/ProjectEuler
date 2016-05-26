// 
//  Problem_54.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





typedef NS_ENUM(NSInteger, PokerHandType) {
	PokerHandTypeHighCard = 1,
	PokerHandTypeOnePair = 10,
	PokerHandTypeTwoPair = 20,
	PokerHandTypeThreeOfAKind = 30,
	PokerHandTypeStraight = 40,
	PokerHandTypeFlush = 50,
	PokerHandTypeFullHouse = 60,
	PokerHandTypeFourOfAKind = 70,
	PokerHandTypeStraightFlush = 80,
	PokerHandTypeRoyalFlush = 90
};

struct Card
{
	NSInteger value;
	char type;
};
typedef struct Card Card;

struct Hand
{
	PokerHandType type;
	NSInteger value;
	Card highCard;
};
typedef struct Hand Hand;





@interface Problem_54 : ProblemBase
{
}

@property (readwrite, nonatomic) NSInteger playerOneWins;
@property (readwrite, nonatomic) NSInteger playerTwoWins;
@property (readwrite, nonatomic) NSInteger ties;

@end





@implementation Problem_54

- (id)solveProblem
{
	[self parsePokerHands];
	
	return @(self.playerOneWins);
}

- (void)parsePokerHands
{
	self.playerOneWins = 0;
	self.playerTwoWins = 0;
	self.ties = 0;
	
	NSString *data = [NSString stringWithContentsOfFile:@"p054_poker.txt" encoding:NSUTF8StringEncoding error:nil];
	NSArray *pokerHands = [data componentsSeparatedByString:@"\n"];
	
	for (NSString *pokerHand in pokerHands) {
		
		NSArray *cards = [pokerHand componentsSeparatedByString:@" "];
		
		if (cards.count == 10) { // 2 5-card hands
			
			NSRange playerOneCardRange = NSMakeRange(0, cards.count / 2);
			NSRange playerTwoCardRange = NSMakeRange(playerOneCardRange.length, playerOneCardRange.length);
			
			NSArray *playerOneHandData = [cards objectsAtIndexes:[NSIndexSet indexSetWithIndexesInRange:playerOneCardRange]];
			NSArray *playerTwoHandData = [cards objectsAtIndexes:[NSIndexSet indexSetWithIndexesInRange:playerTwoCardRange]];
			
			Hand playerOneHand = [self handForCards:&playerOneHandData];
			Hand playerTwoHand = [self handForCards:&playerTwoHandData];
			
			Hand *winningHand =[self winningHandForHand:&playerOneHand andHand:&playerTwoHand];
			
			if (winningHand == &playerOneHand) {
				self.playerOneWins += 1;
			} else if (winningHand == &playerTwoHand) {
				self.playerTwoWins += 1;
			} else {
				self.ties += 1;
			}
			
		}
		
	}
}

/**
 *  -1 = hand wins
 *  1 = andHand wins
 *  0 = tie
 *
 *  @param hand
 *  @param withHand
 *
 *  @return winner
 */
- (Hand *)winningHandForHand:(Hand *)hand andHand:(Hand *)andHand
{
	if (hand->type > andHand->type) {
		return hand;
	} else if (hand->type < andHand->type) {
		return andHand;
	} else {
		if (hand->value > andHand->value) {
			return hand;
		} else if (hand->value < andHand->value) {
			return andHand;
		}else {
			if (hand->highCard.value > andHand->highCard.value) {
				return hand;
			} else if (hand->highCard.value < andHand->highCard.value) {
				return andHand;
			} else {
				return nil;
			}
		}
	}
}

- (Card)cardForString:(NSString *)cardStr
{
	Card card;
	char value = cardStr.UTF8String[0];
	card.type = cardStr.UTF8String[1];
	
	if (value - 48 >= 1 && value - 48 <= 9) {
		card.value = value - 48;
	}
	if (value == 'T') {
		card.value = 10;
	}
	if (value == 'J') {
		card.value = 11;
	}
	if (value == 'Q') {
		card.value = 12;
	}
	if (value == 'K') {
		card.value = 13;
	}
	if (value == 'A') {
		card.value = 14;
	}
	
	return card;
}

- (void)sortHand:(NSArray **)hand
{
	*hand = [*hand sortedArrayUsingComparator:^NSComparisonResult(NSString *obj1, NSString *obj2) {
		
		Card card1 = [self cardForString:obj1];
		Card card2 = [self cardForString:obj2];
		
		if (card1.value > card2.value) {
			return NSOrderedDescending;
		} else if (card1.value < card2.value) {
			return NSOrderedAscending;
		} else {
			return NSOrderedSame;
		}
		
	}];
}

- (Hand)handForCards:(NSArray **)cards
{
	[self sortHand:&*cards];
	
	NSInteger pair1 = -1;
	NSInteger pair2 = -1;
	NSInteger threeOfAKind = -1;
	NSInteger fourOfAKind = -1;
	BOOL straight = YES;
	BOOL flush = YES;
	
	for (NSUInteger x = 0; x < 5; x++) {
		
		Card card = [self cardForString:(*cards)[x]];
		
		
		NSIndexSet *duplicateCards = [*cards indexesOfObjectsPassingTest:^BOOL(NSString *obj, NSUInteger idx, BOOL *stop) {
			
			Card objCard = [self cardForString:obj];
			
			if (objCard.value > card.value) {
				*stop = YES;
			} else if (objCard.value == card.value) {
				return YES;
			}
			
			return NO;
		}];
		
		
		if (duplicateCards.count == 2) {
			if (pair1 == -1) {
				pair1 = card.value;
			} else if (pair1 != card.value) {
				pair2 = card.value;
			}
		} else if (duplicateCards.count == 3) {
			threeOfAKind = card.value;
		} else if (duplicateCards.count == 4) {
			fourOfAKind = card.value;
		}
		
		
		if (x + 1 < 5) {
			
			Card nextCard = [self cardForString:(*cards)[x + 1]];
			
			if (straight && nextCard.value != card.value + 1) {
				straight = NO;
			}
			
			if (flush && nextCard.type != card.type) {
				flush = NO;
			}
			
		}
		
	}
	
	
	
	Card highestCard = [self cardForString:(*cards)[4]];
	Hand hand = { PokerHandTypeHighCard, highestCard.value, highestCard };
	
	if (straight && flush) {
		
		if (highestCard.value == 14) {
			hand.type = PokerHandTypeRoyalFlush;
		} else {
			hand.type = PokerHandTypeStraightFlush;
		}
		
	} else if (straight) {
		hand.type = PokerHandTypeStraight;
	} else if (flush) {
		hand.type = PokerHandTypeStraightFlush;
	} else {
		
		if (pair1 != -1 && pair2 != -1) {
			hand.type = PokerHandTypeTwoPair;
			hand.value = pair1 + pair2;
		} else if (pair1 != -1) {
			if (threeOfAKind != -1) {
				hand.type = PokerHandTypeFullHouse;
				hand.value = pair1 + threeOfAKind;
			} else {
				hand.type = PokerHandTypeOnePair;
				hand.value = pair1;
			}
		} else if (threeOfAKind != -1) {
			hand.type = PokerHandTypeThreeOfAKind;
			hand.value = threeOfAKind;
		} else if (fourOfAKind != -1) {
			hand.type = PokerHandTypeFourOfAKind;
			hand.value = fourOfAKind;
		}
		
	}
	
	return hand;
}

@end





