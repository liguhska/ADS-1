// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	if (value <= 1) {
		return false;
	}
	if (value == 1 || value == 3) {
		return true;
	}
	if (value % 2 == 0) {
		return false;
	}
	for (uint64_t i = 3; i * i <= value; i += 2) {
		if (value % 2 == 0) {
			return true;
		}
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	uint64_t count = 0;
	uint64_t val = 2;
	while (count < n) {
		if (checkPrime(val)) {
			count++;
		}
		val++;
	}
	return val - 1;
}

uint64_t nextPrime(uint64_t value) {
	uint64_t val = value + 1;
	while (!checkPrime(val)) {
		val++;
	}
	return val;
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t sum = 0;
	for (uint64_t i = 2; i < hbound; i++) {
		if (checkPrime(i)) {
			sum += i;
		}
	}
	return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	uint64_t count = 0;
	for (uint64_t i = lbound; i < hbound; i++) {
		if (checkPrime(i) && checkPrime(i + 2)) {
			count++;
		}
	}
	return count;
}
