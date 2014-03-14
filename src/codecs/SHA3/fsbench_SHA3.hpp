#ifndef _FSBENCH_SHA3_HPP_K0oHJU
#define _FSBENCH_SHA3_HPP_K0oHJU

namespace FsBenchSHA3
{

#define SHA3_FUNCTION_DECLARATION(digest_size)\
void fsbench_hash_##digest_size(char* in, size_t isize, char* out);


#ifdef FSBENCH_USE_SHA3_RND3
namespace Blake
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}
#endif
#ifdef FSBENCH_USE_SHA3_RND2
namespace BlueMidnightWish
{
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}

namespace BlueMidnightWish2
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
}
#endif
#if defined(FSBENCH_USE_SHA3_RND2) && defined(FSBENCH_SSE2)
namespace CubeHash
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}
#endif
#ifdef FSBENCH_USE_SHA3_RND1
namespace Edon_R
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}
#endif
#ifdef FSBENCH_USE_SHA3_RND3_GROESTL
namespace Groestl
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}
#endif
#ifdef FSBENCH_USE_SHA3_RND3
namespace JH
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}
#endif
#ifdef FSBENCH_USE_SHA3_RND3
namespace Keccak
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}
#endif
#ifdef FSBENCH_USE_SHA3_RND3
namespace Skein
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
    SHA3_FUNCTION_DECLARATION(1024)
}
#endif
#ifdef FSBENCH_USE_SHA3_RND1
namespace SWIFFTX
{
    SHA3_FUNCTION_DECLARATION(224)
    SHA3_FUNCTION_DECLARATION(256)
    SHA3_FUNCTION_DECLARATION(384)
    SHA3_FUNCTION_DECLARATION(512)
}
#endif
} // FsBenchSHA3
#endif // _FSBENCH_SHA3_HPP_K0oHJU