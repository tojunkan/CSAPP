#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int8_t int8 = ~0;
int16_t int16 = ~0;
int32_t int32 = ~0;
int64_t int64 = ~0;

int main()
{
	printf("int8 has size of %zu, value has been set to %"PRId8".\n", sizeof(int8_t), int8);
	printf("int16 has size of %zu, value has been set to %"PRId16".\n", sizeof(int16_t), int16);
	printf("int32 has size of %zu, value has been set to %"PRId32".\n", sizeof(int32_t), int32);
	printf("int64 has size of %zu, value has been set to %"PRId64".\n", sizeof(int64_t), int64);
	return 0;
}
