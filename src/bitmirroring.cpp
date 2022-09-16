
/// 
unsigned int BitMirror(unsigned int num, int firstBit, int numOfBits) {
	unsigned int result = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

	for (int i = 0; i < firstBit; i++)
	{
		result |= (num & mask);
		mask >>= 1;
	}
	mask >>= numOfBits - 1;

	for (int i = 0; i < numOfBits / 2; i++)
	{
		result |= (num & mask) << (numOfBits)-i - 1;
		mask <<= 1;
	}
	int shift = 0;
	if (numOfBits % 2 != 0) {
		result |= (num & mask);
		mask <<= 1;
		shift++;
	}
	for (int i = 0; i < numOfBits / 2; i++)
	{
		result |= (num & mask) >> shift + 1;
		mask <<= 1;
		shift++;
	}

	mask >>= numOfBits + 1;

	while (mask != 0) {
		result |= (num & mask);
		mask >>= 1;
	}
	return result;
}

float BitMirror(float num, int firstBit, int numOfBits) {
	unsigned int unsignedPres = *(unsigned int*)&num;
	unsigned int mirrored = BitMirror(unsignedPres, firstBit, numOfBits);
	float result = *(float*)&mirrored;
	return result;
}