#ifndef VERITAWARE_TOOLKITS_CWEL_HASHING_
#define VERITAWARE_TOOLKITS_CWEL_HASHING_
#include <string>

#ifdef VERITAWARETOOLKITSCWEL_EXPORTS
#  define EXPORT __declspec(dllexport)
#else
#  define EXPORT __declspec(dllimport)
#endif

namespace veritaware
{
	namespace hashing {
		EXPORT int32_t GetHashCode(bool value);
		EXPORT int32_t GetHashCode(int8_t value);
		EXPORT int32_t GetHashCode(uint8_t value);
		EXPORT int32_t GetHashCode(int16_t value);
		EXPORT int32_t GetHashCode(uint16_t value);
		EXPORT int32_t GetHashCode(int32_t value);
		EXPORT int32_t GetHashCode(uint32_t value);
		EXPORT int32_t GetHashCode(int64_t value);
		EXPORT int32_t GetHashCode(uint64_t value);
		EXPORT int32_t GetHashCode(float value);
		EXPORT int32_t GetHashCode(double value);
		EXPORT int32_t GetHashCode(const char * value);
		EXPORT int32_t GetHashCode(std::string & value);
		EXPORT int32_t CombineHashCodes(int32_t hash1, int32_t hash2);
	}
}

#endif  //VERITAWARE_TOOLKITS_CWEL_HASHING_