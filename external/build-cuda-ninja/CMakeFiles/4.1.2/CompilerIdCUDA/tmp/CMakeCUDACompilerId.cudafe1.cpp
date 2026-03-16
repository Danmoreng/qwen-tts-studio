#pragma section("__nv_managed_data__")
static char __nv_inited_managed_rt = 0; static void **__nv_fatbinhandle_for_managed_rt; static void __nv_save_fatbinhandle_for_managed_rt(void **in){__nv_fatbinhandle_for_managed_rt = in;} static char __nv_init_managed_rt_with_module(void **); static inline void __nv_init_managed_rt(void) { __nv_inited_managed_rt = (__nv_inited_managed_rt ? __nv_inited_managed_rt                 : __nv_init_managed_rt_with_module(__nv_fatbinhandle_for_managed_rt));}
#line 1 "CMakeCUDACompilerId.cu"
#define __nv_is_extended_device_lambda_closure_type(X) false
#define __nv_is_extended_host_device_lambda_closure_type(X) false
#define __nv_is_extended_device_lambda_with_preserved_return_type(X) false
#if defined(__nv_is_extended_device_lambda_closure_type) && defined(__nv_is_extended_host_device_lambda_closure_type)&& defined(__nv_is_extended_device_lambda_with_preserved_return_type)
#endif

#line 1
#line 67 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
#pragma warning(push)
#pragma warning(disable: 4820)
#line 708 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\sal.h"
#pragma region Input Buffer SAL 1 compatibility macros
#line 1472
#pragma endregion Input Buffer SAL 1 compatibility macros
#line 2361 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\sal.h"
extern "C" {
#line 2971 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\sal.h"
}
#line 22 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\concurrencysal.h"
extern "C" {
#line 391 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\concurrencysal.h"
}
#line 15 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
#pragma pack ( push, 8 )
#line 47 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 51
extern "C" {
#line 61 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
typedef unsigned __int64 uintptr_t; 
#line 72 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
typedef char *va_list; 
#line 155 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
void __cdecl __va_start(va_list *, ...); 
#line 167 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
}
#line 171 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
extern "C++" {
#line 173
template< class _Ty> 
#line 174
struct __vcrt_va_list_is_reference { 
#line 176
enum: bool { __the_value}; 
#line 177
}; 
#line 179
template< class _Ty> 
#line 180
struct __vcrt_va_list_is_reference< _Ty &>  { 
#line 182
enum: bool { __the_value = '\001'}; 
#line 183
}; 
#line 185
template< class _Ty> 
#line 186
struct __vcrt_va_list_is_reference< _Ty &&>  { 
#line 188
enum: bool { __the_value = '\001'}; 
#line 189
}; 
#line 191
template< class _Ty> 
#line 192
struct __vcrt_assert_va_start_is_not_reference { 
#line 194
static_assert((!__vcrt_va_list_is_reference< _Ty> ::__the_value), "va_start argument must not have reference type and must not be parenthesized");
#line 196
}; 
#line 197
}
#line 207 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h"
#pragma warning(pop)
#pragma pack ( pop )
#line 60 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 96 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
__pragma( pack ( push, 8 )) extern "C" {
#line 188 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
typedef unsigned __int64 size_t; 
#if !defined(__CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__)
#define __CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__
#endif
#include "crt/host_runtime.h"
#line 189
typedef __int64 ptrdiff_t; 
#line 190
typedef __int64 intptr_t; 
#line 198 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
typedef bool __vcrt_bool; 
#line 245 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
extern "C++" {
#line 247
template< class _CountofType, size_t _SizeOfArray> char (*__countof_helper(__unaligned _CountofType (& _Array)[_SizeOfArray]))[_SizeOfArray]; 
#line 251
}
#line 390 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
void __cdecl __security_init_cookie(); 
#line 399 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
void __cdecl __security_check_cookie(uintptr_t _StackCookie); 
#line 400
__declspec(noreturn) void __cdecl __report_gsfailure(uintptr_t _StackCookie); 
#line 404 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
extern uintptr_t __security_cookie; 
#line 412 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h"
}__pragma( pack ( pop )) 
#line 414
#pragma warning(pop)
#line 121 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 125
__pragma( pack ( push, 8 )) extern "C" {
#line 254 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
extern "C++" {
#line 256
template< bool _Enable, class _Ty> struct _CrtEnableIf; 
#line 259
template< class _Ty> 
#line 260
struct _CrtEnableIf< true, _Ty>  { 
#line 262
typedef _Ty _Type; 
#line 263
}; 
#line 264
}
#line 268 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
typedef bool __crt_bool; 
#line 371 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
void __cdecl _invalid_parameter_noinfo(); 
#line 372
__declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(); 
#line 374
__declspec(noreturn) void __cdecl 
#line 375
_invoke_watson(const __wchar_t * _Expression, const __wchar_t * _FunctionName, const __wchar_t * _FileName, unsigned _LineNo, uintptr_t _Reserved); 
#line 604 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
typedef int errno_t; 
#line 605
typedef unsigned short wint_t; 
#line 606
typedef unsigned short wctype_t; 
#line 607
typedef long __time32_t; 
#line 608
typedef __int64 __time64_t; 
#line 615
typedef 
#line 610
struct __crt_locale_data_public { 
#line 612
const unsigned short *_locale_pctype; 
#line 613
int _locale_mb_cur_max; 
#line 614
unsigned _locale_lc_codepage; 
#line 615
} __crt_locale_data_public; 
#line 621
typedef 
#line 617
struct __crt_locale_pointers { 
#line 619
struct __crt_locale_data *locinfo; 
#line 620
struct __crt_multibyte_data *mbcinfo; 
#line 621
} __crt_locale_pointers; 
#line 623
typedef __crt_locale_pointers *_locale_t; 
#line 629
typedef 
#line 625
struct _Mbstatet { 
#line 627
unsigned long _Wchar; 
#line 628
unsigned short _Byte, _State; 
#line 629
} _Mbstatet; 
#line 631
typedef _Mbstatet mbstate_t; 
#line 645 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
typedef __time64_t time_t; 
#line 655 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
typedef size_t rsize_t; 
#line 2072 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt.h"
}__pragma( pack ( pop )) 
#line 2075
#pragma warning(pop)
#line 13 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wctype.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 35 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wctype.h"
const unsigned short *__cdecl __pctype_func(); 
#line 36
const wctype_t *__cdecl __pwctype_func(); 
#line 67 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wctype.h"
int __cdecl iswalnum(wint_t _C); 
#line 68
int __cdecl iswalpha(wint_t _C); 
#line 69
int __cdecl iswascii(wint_t _C); 
#line 70
int __cdecl iswblank(wint_t _C); 
#line 71
int __cdecl iswcntrl(wint_t _C); 
#line 74
int __cdecl iswdigit(wint_t _C); 
#line 76
int __cdecl iswgraph(wint_t _C); 
#line 77
int __cdecl iswlower(wint_t _C); 
#line 78
int __cdecl iswprint(wint_t _C); 
#line 79
int __cdecl iswpunct(wint_t _C); 
#line 80
int __cdecl iswspace(wint_t _C); 
#line 81
int __cdecl iswupper(wint_t _C); 
#line 82
int __cdecl iswxdigit(wint_t _C); 
#line 83
int __cdecl __iswcsymf(wint_t _C); 
#line 84
int __cdecl __iswcsym(wint_t _C); 
#line 86
int __cdecl _iswalnum_l(wint_t _C, _locale_t _Locale); 
#line 87
int __cdecl _iswalpha_l(wint_t _C, _locale_t _Locale); 
#line 88
int __cdecl _iswblank_l(wint_t _C, _locale_t _Locale); 
#line 89
int __cdecl _iswcntrl_l(wint_t _C, _locale_t _Locale); 
#line 90
int __cdecl _iswdigit_l(wint_t _C, _locale_t _Locale); 
#line 91
int __cdecl _iswgraph_l(wint_t _C, _locale_t _Locale); 
#line 92
int __cdecl _iswlower_l(wint_t _C, _locale_t _Locale); 
#line 93
int __cdecl _iswprint_l(wint_t _C, _locale_t _Locale); 
#line 94
int __cdecl _iswpunct_l(wint_t _C, _locale_t _Locale); 
#line 95
int __cdecl _iswspace_l(wint_t _C, _locale_t _Locale); 
#line 96
int __cdecl _iswupper_l(wint_t _C, _locale_t _Locale); 
#line 97
int __cdecl _iswxdigit_l(wint_t _C, _locale_t _Locale); 
#line 98
int __cdecl _iswcsymf_l(wint_t _C, _locale_t _Locale); 
#line 99
int __cdecl _iswcsym_l(wint_t _C, _locale_t _Locale); 
#line 102
wint_t __cdecl towupper(wint_t _C); 
#line 103
wint_t __cdecl towlower(wint_t _C); 
#line 104
int __cdecl iswctype(wint_t _C, wctype_t _Type); 
#line 106
wint_t __cdecl _towupper_l(wint_t _C, _locale_t _Locale); 
#line 107
wint_t __cdecl _towlower_l(wint_t _C, _locale_t _Locale); 
#line 108
int __cdecl _iswctype_l(wint_t _C, wctype_t _Type, _locale_t _Locale); 
#line 112
int __cdecl isleadbyte(int _C); 
#line 113
int __cdecl _isleadbyte_l(int _C, _locale_t _Locale); 
#line 115
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using iswctype instea" "d. See online help for details.")) int __cdecl is_wctype(wint_t _C, wctype_t _Type); 
#line 203 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wctype.h"
}__pragma( pack ( pop )) 
#line 205
#pragma warning(pop)
#line 15 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\ctype.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 19
__pragma( pack ( push, 8 )) extern "C" {
#line 29
int __cdecl _isctype(int _C, int _Type); 
#line 30
int __cdecl _isctype_l(int _C, int _Type, _locale_t _Locale); 
#line 31
int __cdecl isalpha(int _C); 
#line 32
int __cdecl _isalpha_l(int _C, _locale_t _Locale); 
#line 33
int __cdecl isupper(int _C); 
#line 34
int __cdecl _isupper_l(int _C, _locale_t _Locale); 
#line 35
int __cdecl islower(int _C); 
#line 36
int __cdecl _islower_l(int _C, _locale_t _Locale); 
#line 39
int __cdecl isdigit(int _C); 
#line 41
int __cdecl _isdigit_l(int _C, _locale_t _Locale); 
#line 42
int __cdecl isxdigit(int _C); 
#line 43
int __cdecl _isxdigit_l(int _C, _locale_t _Locale); 
#line 46
int __cdecl isspace(int _C); 
#line 48
int __cdecl _isspace_l(int _C, _locale_t _Locale); 
#line 49
int __cdecl ispunct(int _C); 
#line 50
int __cdecl _ispunct_l(int _C, _locale_t _Locale); 
#line 51
int __cdecl isblank(int _C); 
#line 52
int __cdecl _isblank_l(int _C, _locale_t _Locale); 
#line 53
int __cdecl isalnum(int _C); 
#line 54
int __cdecl _isalnum_l(int _C, _locale_t _Locale); 
#line 55
int __cdecl isprint(int _C); 
#line 56
int __cdecl _isprint_l(int _C, _locale_t _Locale); 
#line 57
int __cdecl isgraph(int _C); 
#line 58
int __cdecl _isgraph_l(int _C, _locale_t _Locale); 
#line 59
int __cdecl iscntrl(int _C); 
#line 60
int __cdecl _iscntrl_l(int _C, _locale_t _Locale); 
#line 63
int __cdecl toupper(int _C); 
#line 66
int __cdecl tolower(int _C); 
#line 68
int __cdecl _tolower(int _C); 
#line 69
int __cdecl _tolower_l(int _C, _locale_t _Locale); 
#line 70
int __cdecl _toupper(int _C); 
#line 71
int __cdecl _toupper_l(int _C, _locale_t _Locale); 
#line 73
int __cdecl __isascii(int _C); 
#line 74
int __cdecl __toascii(int _C); 
#line 75
int __cdecl __iscsymf(int _C); 
#line 76
int __cdecl __iscsym(int _C); 
#line 85
__inline int __cdecl __acrt_locale_get_ctype_array_value(const unsigned short *const 
#line 86
_Locale_pctype_array, const int 
#line 87
_Char_value, const int 
#line 88
_Mask) 
#line 90
{ 
#line 96
if ((_Char_value >= (-1)) && (_Char_value <= 255)) 
#line 97
{ 
#line 98
return (_Locale_pctype_array[_Char_value]) & _Mask; 
#line 99
}  
#line 101
return 0; 
#line 102
} 
#line 124 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\ctype.h"
int __cdecl ___mb_cur_max_func(); 
#line 126
int __cdecl ___mb_cur_max_l_func(_locale_t _Locale); 
#line 152 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\ctype.h"
__forceinline int __cdecl __ascii_tolower(const int _C) 
#line 153
{ 
#line 154
if ((_C >= ('A')) && (_C <= ('Z'))) 
#line 155
{ 
#line 156
return _C - (('A') - ('a')); 
#line 157
}  
#line 158
return _C; 
#line 159
} 
#line 161
__forceinline int __cdecl __ascii_toupper(const int _C) 
#line 162
{ 
#line 163
if ((_C >= ('a')) && (_C <= ('z'))) 
#line 164
{ 
#line 165
return _C - (('a') - ('A')); 
#line 166
}  
#line 167
return _C; 
#line 168
} 
#line 170
__forceinline int __cdecl __ascii_iswalpha(const int _C) 
#line 171
{ 
#line 172
return ((_C >= ('A')) && (_C <= ('Z'))) || ((_C >= ('a')) && (_C <= ('z'))); 
#line 173
} 
#line 175
__forceinline int __cdecl __ascii_iswdigit(const int _C) 
#line 176
{ 
#line 177
return (_C >= ('0')) && (_C <= ('9')); 
#line 178
} 
#line 180
__forceinline int __cdecl __ascii_towlower(const int _C) 
#line 181
{ 
#line 182
return __ascii_tolower(_C); 
#line 183
} 
#line 185
__forceinline int __cdecl __ascii_towupper(const int _C) 
#line 186
{ 
#line 187
return __ascii_toupper(_C); 
#line 188
} 
#line 208 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\ctype.h"
__inline __crt_locale_data_public *__cdecl __acrt_get_locale_data_prefix(const volatile void *const _LocalePointers) 
#line 209
{ 
#line 210
const _locale_t _TypedLocalePointers = (_locale_t)_LocalePointers; 
#line 211
return (__crt_locale_data_public *)(_TypedLocalePointers->locinfo); 
#line 212
} 
#line 218
__inline int __cdecl _chvalidchk_l(const int 
#line 219
_C, const int 
#line 220
_Mask, const _locale_t 
#line 221
_Locale) 
#line 223
{ 
#line 227
if (!_Locale) 
#line 228
{ 
#line 229
return __acrt_locale_get_ctype_array_value(__pctype_func(), _C, _Mask); 
#line 230
}  
#line 232
return __acrt_locale_get_ctype_array_value(__acrt_get_locale_data_prefix(_Locale)->_locale_pctype, _C, _Mask); 
#line 234 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\ctype.h"
} 
#line 239
__inline int __cdecl _ischartype_l(const int 
#line 240
_C, const int 
#line 241
_Mask, const _locale_t 
#line 242
_Locale) 
#line 244
{ 
#line 245
if (!_Locale) 
#line 246
{ 
#line 247
return _chvalidchk_l(_C, _Mask, 0); 
#line 248
}  
#line 250
if ((_C >= (-1)) && (_C <= 255)) 
#line 251
{ 
#line 252
return ((__acrt_get_locale_data_prefix(_Locale)->_locale_pctype)[_C]) & _Mask; 
#line 253
}  
#line 255
if ((__acrt_get_locale_data_prefix(_Locale)->_locale_mb_cur_max) > 1) 
#line 256
{ 
#line 257
return _isctype_l(_C, _Mask, _Locale); 
#line 258
}  
#line 260
return 0; 
#line 261
} 
#line 307 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\ctype.h"
}__pragma( pack ( pop )) 
#line 309
#pragma warning(pop)
#line 68 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_types.h"
#if 0
#line 68
enum cudaRoundMode { 
#line 70
cudaRoundNearest, 
#line 71
cudaRoundZero, 
#line 72
cudaRoundPosInf, 
#line 73
cudaRoundMinInf
#line 74
}; 
#endif
#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 175
struct char1 { 
#line 177
signed char x; 
#line 178
}; 
#endif
#line 180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 180
struct uchar1 { 
#line 182
unsigned char x; 
#line 183
}; 
#endif
#line 186 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 186
struct __declspec(align(2)) char2 { 
#line 188
signed char x, y; 
#line 189
}; 
#endif
#line 191 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 191
struct __declspec(align(2)) uchar2 { 
#line 193
unsigned char x, y; 
#line 194
}; 
#endif
#line 196 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 196
struct char3 { 
#line 198
signed char x, y, z; 
#line 199
}; 
#endif
#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 201
struct uchar3 { 
#line 203
unsigned char x, y, z; 
#line 204
}; 
#endif
#line 206 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 206
struct __declspec(align(4)) char4 { 
#line 208
signed char x, y, z, w; 
#line 209
}; 
#endif
#line 211 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 211
struct __declspec(align(4)) uchar4 { 
#line 213
unsigned char x, y, z, w; 
#line 214
}; 
#endif
#line 216 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 216
struct short1 { 
#line 218
short x; 
#line 219
}; 
#endif
#line 221 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 221
struct ushort1 { 
#line 223
unsigned short x; 
#line 224
}; 
#endif
#line 226 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 226
struct __declspec(align(4)) short2 { 
#line 228
short x, y; 
#line 229
}; 
#endif
#line 231 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 231
struct __declspec(align(4)) ushort2 { 
#line 233
unsigned short x, y; 
#line 234
}; 
#endif
#line 236 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 236
struct short3 { 
#line 238
short x, y, z; 
#line 239
}; 
#endif
#line 241 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 241
struct ushort3 { 
#line 243
unsigned short x, y, z; 
#line 244
}; 
#endif
#line 246 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 246
struct __declspec(align(8)) short4 { short x; short y; short z; short w; }; 
#endif
#line 247 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 247
struct __declspec(align(8)) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; }; 
#endif
#line 249 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 249
struct int1 { 
#line 251
int x; 
#line 252
}; 
#endif
#line 254 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 254
struct uint1 { 
#line 256
unsigned x; 
#line 257
}; 
#endif
#line 259 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 259
struct __declspec(align(8)) int2 { int x; int y; }; 
#endif
#line 260 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 260
struct __declspec(align(8)) uint2 { unsigned x; unsigned y; }; 
#endif
#line 262 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 262
struct int3 { 
#line 264
int x, y, z; 
#line 265
}; 
#endif
#line 267 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 267
struct uint3 { 
#line 269
unsigned x, y, z; 
#line 270
}; 
#endif
#line 272 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 272
struct __declspec(align(16)) int4 { 
#line 274
int x, y, z, w; 
#line 275
}; 
#endif
#line 277 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 277
struct __declspec(align(16)) uint4 { 
#line 279
unsigned x, y, z, w; 
#line 280
}; 
#endif
#line 282 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 282
struct long1 { 
#line 284
long x; 
#line 285
}; 
#endif
#line 287 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 287
struct ulong1 { 
#line 289
unsigned long x; 
#line 290
}; 
#endif
#line 293 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 293
struct __declspec(align(8)) long2 { long x; long y; }; 
#endif
#line 294 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 294
struct __declspec(align(8)) ulong2 { unsigned long x; unsigned long y; }; 
#endif
#line 309 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 309
struct long3 { 
#line 311
long x, y, z; 
#line 312
}; 
#endif
#line 314 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 314
struct ulong3 { 
#line 316
unsigned long x, y, z; 
#line 317
}; 
#endif
#line 320 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 320
struct
#line 319
 __declspec(deprecated("use long4_16a or long4_32a"))
#line 320
 __declspec(align(16)) long4 { 
#line 322
long x, y, z, w; 
#line 323
}; 
#endif
#line 326 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 326
struct
#line 325
 __declspec(deprecated("use ulong4_16a or ulong4_32a"))
#line 326
 __declspec(align(16)) ulong4 { 
#line 328
unsigned long x, y, z, w; 
#line 329
}; 
#endif
#line 331 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 331
struct __declspec(align(16)) long4_16a { 
#line 333
long x, y, z, w; 
#line 334
}; 
#endif
#line 336 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 336
struct __declspec(align(16)) ulong4_16a { 
#line 338
unsigned long x, y, z, w; 
#line 339
}; 
#endif
#line 342 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#pragma warning(push)
#pragma warning(disable: 4324)
#line 345 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 345
struct __declspec(align(32)) long4_32a { 
#line 347
long x, y, z, w; 
#line 348
}; 
#endif
#line 350 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 350
struct __declspec(align(32)) ulong4_32a { 
#line 352
unsigned long x, y, z, w; 
#line 353
}; 
#endif
#line 355 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#pragma warning(pop)
#line 358 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 358
struct float1 { 
#line 360
float x; 
#line 361
}; 
#endif
#line 380 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 380
struct __declspec(align(8)) float2 { float x; float y; }; 
#endif
#line 385 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 385
struct float3 { 
#line 387
float x, y, z; 
#line 388
}; 
#endif
#line 390 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 390
struct __declspec(align(16)) float4 { 
#line 392
float x, y, z, w; 
#line 393
}; 
#endif
#line 395 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 395
struct longlong1 { 
#line 397
__int64 x; 
#line 398
}; 
#endif
#line 400 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 400
struct ulonglong1 { 
#line 402
unsigned __int64 x; 
#line 403
}; 
#endif
#line 405 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 405
struct __declspec(align(16)) longlong2 { 
#line 407
__int64 x, y; 
#line 408
}; 
#endif
#line 410 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 410
struct __declspec(align(16)) ulonglong2 { 
#line 412
unsigned __int64 x, y; 
#line 413
}; 
#endif
#line 415 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 415
struct longlong3 { 
#line 417
__int64 x, y, z; 
#line 418
}; 
#endif
#line 420 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 420
struct ulonglong3 { 
#line 422
unsigned __int64 x, y, z; 
#line 423
}; 
#endif
#line 426 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 426
struct
#line 425
 __declspec(deprecated("use longlong4_16a or longlong4_32a"))
#line 426
 __declspec(align(16)) longlong4 { 
#line 428
__int64 x, y, z, w; 
#line 429
}; 
#endif
#line 431 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 431
struct __declspec(align(16)) longlong4_16a { 
#line 433
__int64 x, y, z, w; 
#line 434
}; 
#endif
#line 436 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 436
struct __declspec(align(32)) longlong4_32a { 
#line 438
__int64 x, y, z, w; 
#line 439
}; 
#endif
#line 442 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 442
struct
#line 441
 __declspec(deprecated("use ulonglong4_16a or ulonglong4_32a"))
#line 442
 __declspec(align(16)) ulonglong4 { 
#line 444
unsigned __int64 x, y, z, w; 
#line 445
}; 
#endif
#line 447 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 447
struct __declspec(align(16)) ulonglong4_16a { 
#line 449
unsigned __int64 x, y, z, w; 
#line 450
}; 
#endif
#line 452 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 452
struct __declspec(align(32)) ulonglong4_32a { 
#line 454
unsigned __int64 x, y, z, w; 
#line 455
}; 
#endif
#line 458 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 458
struct double1 { 
#line 460
double x; 
#line 461
}; 
#endif
#line 463 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 463
struct __declspec(align(16)) double2 { 
#line 465
double x, y; 
#line 466
}; 
#endif
#line 468 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 468
struct double3 { 
#line 470
double x, y, z; 
#line 471
}; 
#endif
#line 474 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 474
struct
#line 473
 __declspec(deprecated("use double4_16a or double4_32a"))
#line 474
 __declspec(align(16)) double4 { 
#line 476
double x, y, z, w; 
#line 477
}; 
#endif
#line 479 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 479
struct __declspec(align(16)) double4_16a { 
#line 481
double x, y, z, w; 
#line 482
}; 
#endif
#line 484 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 484
struct __declspec(align(32)) double4_32a { 
#line 486
double x, y, z, w; 
#line 487
}; 
#endif
#line 501 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef char1 
#line 501
char1; 
#endif
#line 502 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uchar1 
#line 502
uchar1; 
#endif
#line 503 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef char2 
#line 503
char2; 
#endif
#line 504 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uchar2 
#line 504
uchar2; 
#endif
#line 505 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef char3 
#line 505
char3; 
#endif
#line 506 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uchar3 
#line 506
uchar3; 
#endif
#line 507 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef char4 
#line 507
char4; 
#endif
#line 508 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uchar4 
#line 508
uchar4; 
#endif
#line 509 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef short1 
#line 509
short1; 
#endif
#line 510 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ushort1 
#line 510
ushort1; 
#endif
#line 511 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef short2 
#line 511
short2; 
#endif
#line 512 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ushort2 
#line 512
ushort2; 
#endif
#line 513 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef short3 
#line 513
short3; 
#endif
#line 514 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ushort3 
#line 514
ushort3; 
#endif
#line 515 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef short4 
#line 515
short4; 
#endif
#line 516 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ushort4 
#line 516
ushort4; 
#endif
#line 517 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef int1 
#line 517
int1; 
#endif
#line 518 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uint1 
#line 518
uint1; 
#endif
#line 519 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef int2 
#line 519
int2; 
#endif
#line 520 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uint2 
#line 520
uint2; 
#endif
#line 521 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef int3 
#line 521
int3; 
#endif
#line 522 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uint3 
#line 522
uint3; 
#endif
#line 523 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef int4 
#line 523
int4; 
#endif
#line 524 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef uint4 
#line 524
uint4; 
#endif
#line 525 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef long1 
#line 525
long1; 
#endif
#line 526 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulong1 
#line 526
ulong1; 
#endif
#line 527 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef long2 
#line 527
long2; 
#endif
#line 528 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulong2 
#line 528
ulong2; 
#endif
#line 529 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef long3 
#line 529
long3; 
#endif
#line 530 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulong3 
#line 530
ulong3; 
#endif
#line 531 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#if 0
#line 532
__declspec(deprecated("use long4_16a or long4_32a")) typedef long4 long4; 
#endif
#line 533 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 533
__declspec(deprecated("use ulong4_16a or ulong4_32a")) typedef ulong4 ulong4; 
#endif
#line 534 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
__pragma( warning(pop)) 
#if 0
typedef long4_16a 
#line 535
long4_16a; 
#endif
#line 536 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulong4_16a 
#line 536
ulong4_16a; 
#endif
#line 537 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef long4_32a 
#line 537
long4_32a; 
#endif
#line 538 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulong4_32a 
#line 538
ulong4_32a; 
#endif
#line 539 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef float1 
#line 539
float1; 
#endif
#line 540 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef float2 
#line 540
float2; 
#endif
#line 541 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef float3 
#line 541
float3; 
#endif
#line 542 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef float4 
#line 542
float4; 
#endif
#line 543 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef longlong1 
#line 543
longlong1; 
#endif
#line 544 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulonglong1 
#line 544
ulonglong1; 
#endif
#line 545 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef longlong2 
#line 545
longlong2; 
#endif
#line 546 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulonglong2 
#line 546
ulonglong2; 
#endif
#line 547 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef longlong3 
#line 547
longlong3; 
#endif
#line 548 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulonglong3 
#line 548
ulonglong3; 
#endif
#line 549 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#if 0
#line 550
__declspec(deprecated("use longlong4_16a or longlong4_32a")) typedef longlong4 longlong4; 
#endif
#line 551 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 551
__declspec(deprecated("use ulonglong4_16a or ulonglong4_32a")) typedef ulonglong4 ulonglong4; 
#endif
#line 552 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
__pragma( warning(pop)) 
#if 0
typedef longlong4_16a 
#line 553
longlong4_16a; 
#endif
#line 554 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulonglong4_16a 
#line 554
ulonglong4_16a; 
#endif
#line 555 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef longlong4_32a 
#line 555
longlong4_32a; 
#endif
#line 556 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef ulonglong4_32a 
#line 556
ulonglong4_32a; 
#endif
#line 557 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef double1 
#line 557
double1; 
#endif
#line 558 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef double2 
#line 558
double2; 
#endif
#line 559 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef double3 
#line 559
double3; 
#endif
#line 560 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#if 0
#line 561
__declspec(deprecated("use double4_16a or double4_32a")) typedef double4 double4; 
#endif
#line 562 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
__pragma( warning(pop)) 
#if 0
typedef double4_16a 
#line 563
double4_16a; 
#endif
#line 564 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef double4_32a 
#line 564
double4_32a; 
#endif
#line 576 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
#line 576
struct dim3 { 
#line 578
unsigned x, y, z; 
#line 593 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
}; 
#endif
#line 595 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_types.h"
#if 0
typedef dim3 
#line 595
dim3; 
#endif
#line 13 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\limits.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 16
__pragma( pack ( push, 8 )) extern "C" {
#line 74 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\limits.h"
}__pragma( pack ( pop )) 
#line 76
#pragma warning(pop)
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stddef.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 23
namespace std { 
#line 25
typedef decltype(nullptr) nullptr_t; 
#line 26
}
#line 28
using std::nullptr_t;
#line 35 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stddef.h"
int *__cdecl _errno(); 
#line 38
errno_t __cdecl _set_errno(int _Value); 
#line 39
errno_t __cdecl _get_errno(int * _Value); 
#line 55 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stddef.h"
extern unsigned long __cdecl __threadid(); 
#line 57
extern uintptr_t __cdecl __threadhandle(); 
#line 61
}__pragma( pack ( pop )) 
#line 63
#pragma warning(pop)
#line 192 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 192
enum cudaError { 
#line 199
cudaSuccess, 
#line 205
cudaErrorInvalidValue, 
#line 211
cudaErrorMemoryAllocation, 
#line 217
cudaErrorInitializationError, 
#line 224
cudaErrorCudartUnloading, 
#line 231
cudaErrorProfilerDisabled, 
#line 239
cudaErrorProfilerNotInitialized, 
#line 246
cudaErrorProfilerAlreadyStarted, 
#line 253
cudaErrorProfilerAlreadyStopped, 
#line 261
cudaErrorInvalidConfiguration, 
#line 267
cudaErrorInvalidPitchValue = 12, 
#line 273
cudaErrorInvalidSymbol, 
#line 281
cudaErrorInvalidHostPointer = 16, 
#line 289
cudaErrorInvalidDevicePointer, 
#line 294
cudaErrorInvalidTexture, 
#line 300
cudaErrorInvalidTextureBinding, 
#line 307
cudaErrorInvalidChannelDescriptor, 
#line 313
cudaErrorInvalidMemcpyDirection, 
#line 323
cudaErrorAddressOfConstant, 
#line 332
cudaErrorTextureFetchFailed, 
#line 341
cudaErrorTextureNotBound, 
#line 350
cudaErrorSynchronizationError, 
#line 355
cudaErrorInvalidFilterSetting, 
#line 361
cudaErrorInvalidNormSetting, 
#line 369
cudaErrorMixedDeviceExecution, 
#line 377
cudaErrorNotYetImplemented = 31, 
#line 386
cudaErrorMemoryValueTooLarge, 
#line 392
cudaErrorStubLibrary = 34, 
#line 399
cudaErrorInsufficientDriver, 
#line 406
cudaErrorCallRequiresNewerDriver, 
#line 412
cudaErrorInvalidSurface, 
#line 418
cudaErrorDuplicateVariableName = 43, 
#line 424
cudaErrorDuplicateTextureName, 
#line 430
cudaErrorDuplicateSurfaceName, 
#line 440
cudaErrorDevicesUnavailable, 
#line 453
cudaErrorIncompatibleDriverContext = 49, 
#line 459
cudaErrorMissingConfiguration = 52, 
#line 468
cudaErrorPriorLaunchFailure, 
#line 474
cudaErrorLaunchMaxDepthExceeded = 65, 
#line 482
cudaErrorLaunchFileScopedTex, 
#line 490
cudaErrorLaunchFileScopedSurf, 
#line 506
cudaErrorSyncDepthExceeded, 
#line 518
cudaErrorLaunchPendingCountExceeded, 
#line 524
cudaErrorInvalidDeviceFunction = 98, 
#line 530
cudaErrorNoDevice = 100, 
#line 537
cudaErrorInvalidDevice, 
#line 542
cudaErrorDeviceNotLicensed, 
#line 551
cudaErrorSoftwareValidityNotEstablished, 
#line 556
cudaErrorStartupFailure = 127, 
#line 561
cudaErrorInvalidKernelImage = 200, 
#line 571
cudaErrorDeviceUninitialized, 
#line 576
cudaErrorMapBufferObjectFailed = 205, 
#line 581
cudaErrorUnmapBufferObjectFailed, 
#line 587
cudaErrorArrayIsMapped, 
#line 592
cudaErrorAlreadyMapped, 
#line 600
cudaErrorNoKernelImageForDevice, 
#line 605
cudaErrorAlreadyAcquired, 
#line 610
cudaErrorNotMapped, 
#line 616
cudaErrorNotMappedAsArray, 
#line 622
cudaErrorNotMappedAsPointer, 
#line 628
cudaErrorECCUncorrectable, 
#line 634
cudaErrorUnsupportedLimit, 
#line 640
cudaErrorDeviceAlreadyInUse, 
#line 646
cudaErrorPeerAccessUnsupported, 
#line 652
cudaErrorInvalidPtx, 
#line 657
cudaErrorInvalidGraphicsContext, 
#line 663
cudaErrorNvlinkUncorrectable, 
#line 670
cudaErrorJitCompilerNotFound, 
#line 677
cudaErrorUnsupportedPtxVersion, 
#line 684
cudaErrorJitCompilationDisabled, 
#line 689
cudaErrorUnsupportedExecAffinity, 
#line 695
cudaErrorUnsupportedDevSideSync, 
#line 706
cudaErrorContained, 
#line 711
cudaErrorInvalidSource = 300, 
#line 716
cudaErrorFileNotFound, 
#line 721
cudaErrorSharedObjectSymbolNotFound, 
#line 726
cudaErrorSharedObjectInitFailed, 
#line 731
cudaErrorOperatingSystem, 
#line 738
cudaErrorInvalidResourceHandle = 400, 
#line 744
cudaErrorIllegalState, 
#line 752
cudaErrorLossyQuery, 
#line 759
cudaErrorSymbolNotFound = 500, 
#line 767
cudaErrorNotReady = 600, 
#line 775
cudaErrorIllegalAddress = 700, 
#line 784
cudaErrorLaunchOutOfResources, 
#line 795
cudaErrorLaunchTimeout, 
#line 801
cudaErrorLaunchIncompatibleTexturing, 
#line 808
cudaErrorPeerAccessAlreadyEnabled, 
#line 815
cudaErrorPeerAccessNotEnabled, 
#line 828
cudaErrorSetOnActiveProcess = 708, 
#line 835
cudaErrorContextIsDestroyed, 
#line 842
cudaErrorAssert, 
#line 849
cudaErrorTooManyPeers, 
#line 855
cudaErrorHostMemoryAlreadyRegistered, 
#line 861
cudaErrorHostMemoryNotRegistered, 
#line 870
cudaErrorHardwareStackError, 
#line 878
cudaErrorIllegalInstruction, 
#line 887
cudaErrorMisalignedAddress, 
#line 898
cudaErrorInvalidAddressSpace, 
#line 906
cudaErrorInvalidPc, 
#line 917
cudaErrorLaunchFailure, 
#line 926
cudaErrorCooperativeLaunchTooLarge, 
#line 934
cudaErrorTensorMemoryLeak, 
#line 939
cudaErrorNotPermitted = 800, 
#line 945
cudaErrorNotSupported, 
#line 954
cudaErrorSystemNotReady, 
#line 961
cudaErrorSystemDriverMismatch, 
#line 970
cudaErrorCompatNotSupportedOnDevice, 
#line 975
cudaErrorMpsConnectionFailed, 
#line 980
cudaErrorMpsRpcFailure, 
#line 986
cudaErrorMpsServerNotReady, 
#line 991
cudaErrorMpsMaxClientsReached, 
#line 996
cudaErrorMpsMaxConnectionsReached, 
#line 1001
cudaErrorMpsClientTerminated, 
#line 1006
cudaErrorCdpNotSupported, 
#line 1011
cudaErrorCdpVersionMismatch, 
#line 1016
cudaErrorStreamCaptureUnsupported = 900, 
#line 1022
cudaErrorStreamCaptureInvalidated, 
#line 1028
cudaErrorStreamCaptureMerge, 
#line 1033
cudaErrorStreamCaptureUnmatched, 
#line 1039
cudaErrorStreamCaptureUnjoined, 
#line 1046
cudaErrorStreamCaptureIsolation, 
#line 1052
cudaErrorStreamCaptureImplicit, 
#line 1058
cudaErrorCapturedEvent, 
#line 1065
cudaErrorStreamCaptureWrongThread, 
#line 1070
cudaErrorTimeout, 
#line 1076
cudaErrorGraphExecUpdateFailure, 
#line 1086
cudaErrorExternalDevice, 
#line 1092
cudaErrorInvalidClusterSize, 
#line 1098
cudaErrorFunctionNotLoaded, 
#line 1104
cudaErrorInvalidResourceType, 
#line 1110
cudaErrorInvalidResourceConfiguration, 
#line 1115
cudaErrorUnknown = 999, 
#line 1123
cudaErrorApiFailureBase = 10000
#line 1124
}; 
#endif
#line 1129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1129
enum cudaChannelFormatKind { 
#line 1131
cudaChannelFormatKindSigned, 
#line 1132
cudaChannelFormatKindUnsigned, 
#line 1133
cudaChannelFormatKindFloat, 
#line 1134
cudaChannelFormatKindNone, 
#line 1135
cudaChannelFormatKindNV12, 
#line 1136
cudaChannelFormatKindUnsignedNormalized8X1, 
#line 1137
cudaChannelFormatKindUnsignedNormalized8X2, 
#line 1138
cudaChannelFormatKindUnsignedNormalized8X4, 
#line 1139
cudaChannelFormatKindUnsignedNormalized16X1, 
#line 1140
cudaChannelFormatKindUnsignedNormalized16X2, 
#line 1141
cudaChannelFormatKindUnsignedNormalized16X4, 
#line 1142
cudaChannelFormatKindSignedNormalized8X1, 
#line 1143
cudaChannelFormatKindSignedNormalized8X2, 
#line 1144
cudaChannelFormatKindSignedNormalized8X4, 
#line 1145
cudaChannelFormatKindSignedNormalized16X1, 
#line 1146
cudaChannelFormatKindSignedNormalized16X2, 
#line 1147
cudaChannelFormatKindSignedNormalized16X4, 
#line 1148
cudaChannelFormatKindUnsignedBlockCompressed1, 
#line 1149
cudaChannelFormatKindUnsignedBlockCompressed1SRGB, 
#line 1150
cudaChannelFormatKindUnsignedBlockCompressed2, 
#line 1151
cudaChannelFormatKindUnsignedBlockCompressed2SRGB, 
#line 1152
cudaChannelFormatKindUnsignedBlockCompressed3, 
#line 1153
cudaChannelFormatKindUnsignedBlockCompressed3SRGB, 
#line 1154
cudaChannelFormatKindUnsignedBlockCompressed4, 
#line 1155
cudaChannelFormatKindSignedBlockCompressed4, 
#line 1156
cudaChannelFormatKindUnsignedBlockCompressed5, 
#line 1157
cudaChannelFormatKindSignedBlockCompressed5, 
#line 1158
cudaChannelFormatKindUnsignedBlockCompressed6H, 
#line 1159
cudaChannelFormatKindSignedBlockCompressed6H, 
#line 1160
cudaChannelFormatKindUnsignedBlockCompressed7, 
#line 1161
cudaChannelFormatKindUnsignedBlockCompressed7SRGB, 
#line 1162
cudaChannelFormatKindUnsignedNormalized1010102
#line 1164
}; 
#endif
#line 1169 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1169
struct cudaChannelFormatDesc { 
#line 1171
int x; 
#line 1172
int y; 
#line 1173
int z; 
#line 1174
int w; 
#line 1175
cudaChannelFormatKind f; 
#line 1176
}; 
#endif
#line 1181 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
typedef struct cudaArray *cudaArray_t; 
#line 1186
typedef const cudaArray *cudaArray_const_t; 
#line 1188
struct cudaArray; 
#line 1193
typedef struct cudaMipmappedArray *cudaMipmappedArray_t; 
#line 1198
typedef const cudaMipmappedArray *cudaMipmappedArray_const_t; 
#line 1200
struct cudaMipmappedArray; 
#line 1210
#if 0
#line 1210
struct cudaArraySparseProperties { 
#line 1211
struct { 
#line 1212
unsigned width; 
#line 1213
unsigned height; 
#line 1214
unsigned depth; 
#line 1215
} tileExtent; 
#line 1216
unsigned miptailFirstLevel; 
#line 1217
unsigned __int64 miptailSize; 
#line 1218
unsigned flags; 
#line 1219
unsigned reserved[4]; 
#line 1220
}; 
#endif
#line 1225 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1225
struct cudaArrayMemoryRequirements { 
#line 1226
size_t size; 
#line 1227
size_t alignment; 
#line 1228
unsigned reserved[4]; 
#line 1229
}; 
#endif
#line 1234 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1234
enum cudaMemoryType { 
#line 1236
cudaMemoryTypeUnregistered, 
#line 1237
cudaMemoryTypeHost, 
#line 1238
cudaMemoryTypeDevice, 
#line 1239
cudaMemoryTypeManaged
#line 1240
}; 
#endif
#line 1245 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1245
enum cudaMemcpyKind { 
#line 1247
cudaMemcpyHostToHost, 
#line 1248
cudaMemcpyHostToDevice, 
#line 1249
cudaMemcpyDeviceToHost, 
#line 1250
cudaMemcpyDeviceToDevice, 
#line 1251
cudaMemcpyDefault
#line 1252
}; 
#endif
#line 1259 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1259
struct cudaPitchedPtr { 
#line 1261
void *ptr; 
#line 1262
size_t pitch; 
#line 1263
size_t xsize; 
#line 1264
size_t ysize; 
#line 1265
}; 
#endif
#line 1272 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1272
struct cudaExtent { 
#line 1274
size_t width; 
#line 1275
size_t height; 
#line 1276
size_t depth; 
#line 1277
}; 
#endif
#line 1284 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1284
struct cudaPos { 
#line 1286
size_t x; 
#line 1287
size_t y; 
#line 1288
size_t z; 
#line 1289
}; 
#endif
#line 1294 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1294
struct cudaMemcpy3DParms { 
#line 1296
cudaArray_t srcArray; 
#line 1297
cudaPos srcPos; 
#line 1298
cudaPitchedPtr srcPtr; 
#line 1300
cudaArray_t dstArray; 
#line 1301
cudaPos dstPos; 
#line 1302
cudaPitchedPtr dstPtr; 
#line 1304
cudaExtent extent; 
#line 1305
cudaMemcpyKind kind; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 1306
}; 
#endif
#line 1311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1311
struct cudaMemcpyNodeParams { 
#line 1312
int flags; 
#line 1313
int reserved[3]; 
#line 1314
cudaMemcpy3DParms copyParams; 
#line 1315
}; 
#endif
#line 1320 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1320
struct cudaMemcpy3DPeerParms { 
#line 1322
cudaArray_t srcArray; 
#line 1323
cudaPos srcPos; 
#line 1324
cudaPitchedPtr srcPtr; 
#line 1325
int srcDevice; 
#line 1327
cudaArray_t dstArray; 
#line 1328
cudaPos dstPos; 
#line 1329
cudaPitchedPtr dstPtr; 
#line 1330
int dstDevice; 
#line 1332
cudaExtent extent; 
#line 1333
}; 
#endif
#line 1338 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1338
struct cudaMemsetParams { 
#line 1339
void *dst; 
#line 1340
size_t pitch; 
#line 1341
unsigned value; 
#line 1342
unsigned elementSize; 
#line 1343
size_t width; 
#line 1344
size_t height; 
#line 1345
}; 
#endif
#line 1350 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1350
struct cudaMemsetParamsV2 { 
#line 1351
void *dst; 
#line 1352
size_t pitch; 
#line 1353
unsigned value; 
#line 1354
unsigned elementSize; 
#line 1355
size_t width; 
#line 1356
size_t height; 
#line 1357
}; 
#endif
#line 1362 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1362
enum cudaAccessProperty { 
#line 1363
cudaAccessPropertyNormal, 
#line 1364
cudaAccessPropertyStreaming, 
#line 1365
cudaAccessPropertyPersisting
#line 1366
}; 
#endif
#line 1379 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1379
struct cudaAccessPolicyWindow { 
#line 1380
void *base_ptr; 
#line 1381
size_t num_bytes; 
#line 1382
float hitRatio; 
#line 1383
cudaAccessProperty hitProp; 
#line 1384
cudaAccessProperty missProp; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 1385
}; 
#endif
#line 1397 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
typedef void (__stdcall *cudaHostFn_t)(void * userData); 
#line 1402
#if 0
#line 1402
struct cudaHostNodeParams { 
#line 1403
cudaHostFn_t fn; 
#line 1404
void *userData; 
#line 1405
}; 
#endif
#line 1410 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1410
struct cudaHostNodeParamsV2 { 
#line 1411
cudaHostFn_t fn; 
#line 1412
void *userData; 
#line 1413
}; 
#endif
#line 1418 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1418
enum cudaStreamCaptureStatus { 
#line 1419
cudaStreamCaptureStatusNone, 
#line 1420
cudaStreamCaptureStatusActive, 
#line 1421
cudaStreamCaptureStatusInvalidated
#line 1423
}; 
#endif
#line 1429 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1429
enum cudaStreamCaptureMode { 
#line 1430
cudaStreamCaptureModeGlobal, 
#line 1431
cudaStreamCaptureModeThreadLocal, 
#line 1432
cudaStreamCaptureModeRelaxed
#line 1433
}; 
#endif
#line 1435 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1435
enum cudaSynchronizationPolicy { 
#line 1436
cudaSyncPolicyAuto = 1, 
#line 1437
cudaSyncPolicySpin, 
#line 1438
cudaSyncPolicyYield, 
#line 1439
cudaSyncPolicyBlockingSync
#line 1440
}; 
#endif
#line 1445 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1445
enum cudaClusterSchedulingPolicy { 
#line 1446
cudaClusterSchedulingPolicyDefault, 
#line 1447
cudaClusterSchedulingPolicySpread, 
#line 1448
cudaClusterSchedulingPolicyLoadBalancing
#line 1449
}; 
#endif
#line 1454 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1454
enum cudaStreamUpdateCaptureDependenciesFlags { 
#line 1455
cudaStreamAddCaptureDependencies, 
#line 1456
cudaStreamSetCaptureDependencies
#line 1457
}; 
#endif
#line 1462 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1462
enum cudaUserObjectFlags { 
#line 1463
cudaUserObjectNoDestructorSync = 1
#line 1464
}; 
#endif
#line 1469 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1469
enum cudaUserObjectRetainFlags { 
#line 1470
cudaGraphUserObjectMove = 1
#line 1471
}; 
#endif
#line 1476 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
struct cudaGraphicsResource; 
#line 1481
#if 0
#line 1481
enum cudaGraphicsRegisterFlags { 
#line 1483
cudaGraphicsRegisterFlagsNone, 
#line 1484
cudaGraphicsRegisterFlagsReadOnly, 
#line 1485
cudaGraphicsRegisterFlagsWriteDiscard, 
#line 1486
cudaGraphicsRegisterFlagsSurfaceLoadStore = 4, 
#line 1487
cudaGraphicsRegisterFlagsTextureGather = 8
#line 1488
}; 
#endif
#line 1493 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1493
enum cudaGraphicsMapFlags { 
#line 1495
cudaGraphicsMapFlagsNone, 
#line 1496
cudaGraphicsMapFlagsReadOnly, 
#line 1497
cudaGraphicsMapFlagsWriteDiscard
#line 1498
}; 
#endif
#line 1503 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1503
enum cudaGraphicsCubeFace { 
#line 1505
cudaGraphicsCubeFacePositiveX, 
#line 1506
cudaGraphicsCubeFaceNegativeX, 
#line 1507
cudaGraphicsCubeFacePositiveY, 
#line 1508
cudaGraphicsCubeFaceNegativeY, 
#line 1509
cudaGraphicsCubeFacePositiveZ, 
#line 1510
cudaGraphicsCubeFaceNegativeZ
#line 1511
}; 
#endif
#line 1516 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1516
enum cudaResourceType { 
#line 1518
cudaResourceTypeArray, 
#line 1519
cudaResourceTypeMipmappedArray, 
#line 1520
cudaResourceTypeLinear, 
#line 1521
cudaResourceTypePitch2D
#line 1522
}; 
#endif
#line 1527 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1527
enum cudaResourceViewFormat { 
#line 1529
cudaResViewFormatNone, 
#line 1530
cudaResViewFormatUnsignedChar1, 
#line 1531
cudaResViewFormatUnsignedChar2, 
#line 1532
cudaResViewFormatUnsignedChar4, 
#line 1533
cudaResViewFormatSignedChar1, 
#line 1534
cudaResViewFormatSignedChar2, 
#line 1535
cudaResViewFormatSignedChar4, 
#line 1536
cudaResViewFormatUnsignedShort1, 
#line 1537
cudaResViewFormatUnsignedShort2, 
#line 1538
cudaResViewFormatUnsignedShort4, 
#line 1539
cudaResViewFormatSignedShort1, 
#line 1540
cudaResViewFormatSignedShort2, 
#line 1541
cudaResViewFormatSignedShort4, 
#line 1542
cudaResViewFormatUnsignedInt1, 
#line 1543
cudaResViewFormatUnsignedInt2, 
#line 1544
cudaResViewFormatUnsignedInt4, 
#line 1545
cudaResViewFormatSignedInt1, 
#line 1546
cudaResViewFormatSignedInt2, 
#line 1547
cudaResViewFormatSignedInt4, 
#line 1548
cudaResViewFormatHalf1, 
#line 1549
cudaResViewFormatHalf2, 
#line 1550
cudaResViewFormatHalf4, 
#line 1551
cudaResViewFormatFloat1, 
#line 1552
cudaResViewFormatFloat2, 
#line 1553
cudaResViewFormatFloat4, 
#line 1554
cudaResViewFormatUnsignedBlockCompressed1, 
#line 1555
cudaResViewFormatUnsignedBlockCompressed2, 
#line 1556
cudaResViewFormatUnsignedBlockCompressed3, 
#line 1557
cudaResViewFormatUnsignedBlockCompressed4, 
#line 1558
cudaResViewFormatSignedBlockCompressed4, 
#line 1559
cudaResViewFormatUnsignedBlockCompressed5, 
#line 1560
cudaResViewFormatSignedBlockCompressed5, 
#line 1561
cudaResViewFormatUnsignedBlockCompressed6H, 
#line 1562
cudaResViewFormatSignedBlockCompressed6H, 
#line 1563
cudaResViewFormatUnsignedBlockCompressed7
#line 1564
}; 
#endif
#line 1569 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1569
struct cudaResourceDesc { 
#line 1570
cudaResourceType resType; 
#line 1572
union { 
#line 1573
struct { 
#line 1574
cudaArray_t array; 
#line 1575
} array; 
#line 1576
struct { 
#line 1577
cudaMipmappedArray_t mipmap; 
#line 1578
} mipmap; 
#line 1579
struct { 
#line 1580
void *devPtr; 
#line 1581
cudaChannelFormatDesc desc; 
#line 1582
size_t sizeInBytes; 
#line 1583
} linear; 
#line 1584
struct { 
#line 1585
void *devPtr; 
#line 1586
cudaChannelFormatDesc desc; 
#line 1587
size_t width; 
#line 1588
size_t height; 
#line 1589
size_t pitchInBytes; 
#line 1590
} pitch2D; 
#line 1591
struct { 
#line 1592
int reserved[32]; 
#line 1593
} reserved; 
#line 1594
} res; 
#line 1596
unsigned flags; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 1597
}; 
#endif
#line 1602 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1602
struct cudaResourceViewDesc { 
#line 1604
cudaResourceViewFormat format; 
#line 1605
size_t width; 
#line 1606
size_t height; 
#line 1607
size_t depth; 
#line 1608
unsigned firstMipmapLevel; 
#line 1609
unsigned lastMipmapLevel; 
#line 1610
unsigned firstLayer; 
#line 1611
unsigned lastLayer; 
#line 1612
unsigned reserved[16]; 
#line 1613
}; 
#endif
#line 1618 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1618
struct cudaPointerAttributes { 
#line 1624
cudaMemoryType type; 
#line 1635
int device; 
#line 1641
void *devicePointer; 
#line 1650
void *hostPointer; 
#line 1655
long reserved[8]; 
#line 1656
}; 
#endif
#line 1661 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1661
struct cudaFuncAttributes { 
#line 1668
size_t sharedSizeBytes; 
#line 1674
size_t constSizeBytes; 
#line 1679
size_t localSizeBytes; 
#line 1686
int maxThreadsPerBlock; 
#line 1691
int numRegs; 
#line 1698
int ptxVersion; 
#line 1705
int binaryVersion; 
#line 1711
int cacheModeCA; 
#line 1718
int maxDynamicSharedSizeBytes; 
#line 1727
int preferredShmemCarveout; 
#line 1733
int clusterDimMustBeSet; 
#line 1744
int requiredClusterWidth; 
#line 1745
int requiredClusterHeight; 
#line 1746
int requiredClusterDepth; 
#line 1752
int clusterSchedulingPolicyPreference; 
#line 1774
int nonPortableClusterSizeAllowed; 
#line 1779
int reserved[16]; 
#line 1780
}; 
#endif
#line 1785 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1785
enum cudaFuncAttribute { 
#line 1787
cudaFuncAttributeMaxDynamicSharedMemorySize = 8, 
#line 1788
cudaFuncAttributePreferredSharedMemoryCarveout, 
#line 1789
cudaFuncAttributeClusterDimMustBeSet, 
#line 1790
cudaFuncAttributeRequiredClusterWidth, 
#line 1791
cudaFuncAttributeRequiredClusterHeight, 
#line 1792
cudaFuncAttributeRequiredClusterDepth, 
#line 1793
cudaFuncAttributeNonPortableClusterSizeAllowed, 
#line 1794
cudaFuncAttributeClusterSchedulingPolicyPreference, 
#line 1795
cudaFuncAttributeMax
#line 1796
}; 
#endif
#line 1801 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1801
enum cudaFuncCache { 
#line 1803
cudaFuncCachePreferNone, 
#line 1804
cudaFuncCachePreferShared, 
#line 1805
cudaFuncCachePreferL1, 
#line 1806
cudaFuncCachePreferEqual
#line 1807
}; 
#endif
#line 1813 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1813
enum cudaSharedMemConfig { 
#line 1815
cudaSharedMemBankSizeDefault, 
#line 1816
cudaSharedMemBankSizeFourByte, 
#line 1817
cudaSharedMemBankSizeEightByte
#line 1818
}; 
#endif
#line 1823 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1823
enum cudaSharedCarveout { 
#line 1824
cudaSharedmemCarveoutDefault = (-1), 
#line 1825
cudaSharedmemCarveoutMaxShared = 100, 
#line 1826
cudaSharedmemCarveoutMaxL1 = 0
#line 1827
}; 
#endif
#line 1832 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1832
enum cudaComputeMode { 
#line 1834
cudaComputeModeDefault, 
#line 1835
cudaComputeModeExclusive, 
#line 1836
cudaComputeModeProhibited, 
#line 1837
cudaComputeModeExclusiveProcess
#line 1838
}; 
#endif
#line 1843 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1843
enum cudaLimit { 
#line 1845
cudaLimitStackSize, 
#line 1846
cudaLimitPrintfFifoSize, 
#line 1847
cudaLimitMallocHeapSize, 
#line 1848
cudaLimitDevRuntimeSyncDepth, 
#line 1849
cudaLimitDevRuntimePendingLaunchCount, 
#line 1850
cudaLimitMaxL2FetchGranularity, 
#line 1851
cudaLimitPersistingL2CacheSize
#line 1852
}; 
#endif
#line 1857 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1857
enum cudaMemoryAdvise { 
#line 1859
cudaMemAdviseSetReadMostly = 1, 
#line 1860
cudaMemAdviseUnsetReadMostly, 
#line 1861
cudaMemAdviseSetPreferredLocation, 
#line 1862
cudaMemAdviseUnsetPreferredLocation, 
#line 1863
cudaMemAdviseSetAccessedBy, 
#line 1864
cudaMemAdviseUnsetAccessedBy
#line 1865
}; 
#endif
#line 1870 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1870
enum cudaMemRangeAttribute { 
#line 1872
cudaMemRangeAttributeReadMostly = 1, 
#line 1873
cudaMemRangeAttributePreferredLocation, 
#line 1874
cudaMemRangeAttributeAccessedBy, 
#line 1875
cudaMemRangeAttributeLastPrefetchLocation, 
#line 1876
cudaMemRangeAttributePreferredLocationType, 
#line 1877
cudaMemRangeAttributePreferredLocationId, 
#line 1878
cudaMemRangeAttributeLastPrefetchLocationType, 
#line 1879
cudaMemRangeAttributeLastPrefetchLocationId
#line 1880
}; 
#endif
#line 1885 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1885
enum cudaFlushGPUDirectRDMAWritesOptions { 
#line 1886
cudaFlushGPUDirectRDMAWritesOptionHost = (1 << 0), 
#line 1887
cudaFlushGPUDirectRDMAWritesOptionMemOps
#line 1888
}; 
#endif
#line 1893 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1893
enum cudaGPUDirectRDMAWritesOrdering { 
#line 1894
cudaGPUDirectRDMAWritesOrderingNone, 
#line 1895
cudaGPUDirectRDMAWritesOrderingOwner = 100, 
#line 1896
cudaGPUDirectRDMAWritesOrderingAllDevices = 200
#line 1897
}; 
#endif
#line 1902 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1902
enum cudaFlushGPUDirectRDMAWritesScope { 
#line 1903
cudaFlushGPUDirectRDMAWritesToOwner = 100, 
#line 1904
cudaFlushGPUDirectRDMAWritesToAllDevices = 200
#line 1905
}; 
#endif
#line 1910 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1910
enum cudaFlushGPUDirectRDMAWritesTarget { 
#line 1911
cudaFlushGPUDirectRDMAWritesTargetCurrentDevice
#line 1912
}; 
#endif
#line 1918 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 1918
enum cudaDeviceAttr { 
#line 1920
cudaDevAttrMaxThreadsPerBlock = 1, 
#line 1921
cudaDevAttrMaxBlockDimX, 
#line 1922
cudaDevAttrMaxBlockDimY, 
#line 1923
cudaDevAttrMaxBlockDimZ, 
#line 1924
cudaDevAttrMaxGridDimX, 
#line 1925
cudaDevAttrMaxGridDimY, 
#line 1926
cudaDevAttrMaxGridDimZ, 
#line 1927
cudaDevAttrMaxSharedMemoryPerBlock, 
#line 1928
cudaDevAttrTotalConstantMemory, 
#line 1929
cudaDevAttrWarpSize, 
#line 1930
cudaDevAttrMaxPitch, 
#line 1931
cudaDevAttrMaxRegistersPerBlock, 
#line 1932
cudaDevAttrClockRate, 
#line 1933
cudaDevAttrTextureAlignment, 
#line 1934
cudaDevAttrGpuOverlap, 
#line 1935
cudaDevAttrMultiProcessorCount, 
#line 1936
cudaDevAttrKernelExecTimeout, 
#line 1937
cudaDevAttrIntegrated, 
#line 1938
cudaDevAttrCanMapHostMemory, 
#line 1939
cudaDevAttrComputeMode, 
#line 1940
cudaDevAttrMaxTexture1DWidth, 
#line 1941
cudaDevAttrMaxTexture2DWidth, 
#line 1942
cudaDevAttrMaxTexture2DHeight, 
#line 1943
cudaDevAttrMaxTexture3DWidth, 
#line 1944
cudaDevAttrMaxTexture3DHeight, 
#line 1945
cudaDevAttrMaxTexture3DDepth, 
#line 1946
cudaDevAttrMaxTexture2DLayeredWidth, 
#line 1947
cudaDevAttrMaxTexture2DLayeredHeight, 
#line 1948
cudaDevAttrMaxTexture2DLayeredLayers, 
#line 1949
cudaDevAttrSurfaceAlignment, 
#line 1950
cudaDevAttrConcurrentKernels, 
#line 1951
cudaDevAttrEccEnabled, 
#line 1952
cudaDevAttrPciBusId, 
#line 1953
cudaDevAttrPciDeviceId, 
#line 1954
cudaDevAttrTccDriver, 
#line 1955
cudaDevAttrMemoryClockRate, 
#line 1956
cudaDevAttrGlobalMemoryBusWidth, 
#line 1957
cudaDevAttrL2CacheSize, 
#line 1958
cudaDevAttrMaxThreadsPerMultiProcessor, 
#line 1959
cudaDevAttrAsyncEngineCount, 
#line 1960
cudaDevAttrUnifiedAddressing, 
#line 1961
cudaDevAttrMaxTexture1DLayeredWidth, 
#line 1962
cudaDevAttrMaxTexture1DLayeredLayers, 
#line 1963
cudaDevAttrMaxTexture2DGatherWidth = 45, 
#line 1964
cudaDevAttrMaxTexture2DGatherHeight, 
#line 1965
cudaDevAttrMaxTexture3DWidthAlt, 
#line 1966
cudaDevAttrMaxTexture3DHeightAlt, 
#line 1967
cudaDevAttrMaxTexture3DDepthAlt, 
#line 1968
cudaDevAttrPciDomainId, 
#line 1969
cudaDevAttrTexturePitchAlignment, 
#line 1970
cudaDevAttrMaxTextureCubemapWidth, 
#line 1971
cudaDevAttrMaxTextureCubemapLayeredWidth, 
#line 1972
cudaDevAttrMaxTextureCubemapLayeredLayers, 
#line 1973
cudaDevAttrMaxSurface1DWidth, 
#line 1974
cudaDevAttrMaxSurface2DWidth, 
#line 1975
cudaDevAttrMaxSurface2DHeight, 
#line 1976
cudaDevAttrMaxSurface3DWidth, 
#line 1977
cudaDevAttrMaxSurface3DHeight, 
#line 1978
cudaDevAttrMaxSurface3DDepth, 
#line 1979
cudaDevAttrMaxSurface1DLayeredWidth, 
#line 1980
cudaDevAttrMaxSurface1DLayeredLayers, 
#line 1981
cudaDevAttrMaxSurface2DLayeredWidth, 
#line 1982
cudaDevAttrMaxSurface2DLayeredHeight, 
#line 1983
cudaDevAttrMaxSurface2DLayeredLayers, 
#line 1984
cudaDevAttrMaxSurfaceCubemapWidth, 
#line 1985
cudaDevAttrMaxSurfaceCubemapLayeredWidth, 
#line 1986
cudaDevAttrMaxSurfaceCubemapLayeredLayers, 
#line 1987
cudaDevAttrMaxTexture1DLinearWidth, 
#line 1988
cudaDevAttrMaxTexture2DLinearWidth, 
#line 1989
cudaDevAttrMaxTexture2DLinearHeight, 
#line 1990
cudaDevAttrMaxTexture2DLinearPitch, 
#line 1991
cudaDevAttrMaxTexture2DMipmappedWidth, 
#line 1992
cudaDevAttrMaxTexture2DMipmappedHeight, 
#line 1993
cudaDevAttrComputeCapabilityMajor, 
#line 1994
cudaDevAttrComputeCapabilityMinor, 
#line 1995
cudaDevAttrMaxTexture1DMipmappedWidth, 
#line 1996
cudaDevAttrStreamPrioritiesSupported, 
#line 1997
cudaDevAttrGlobalL1CacheSupported, 
#line 1998
cudaDevAttrLocalL1CacheSupported, 
#line 1999
cudaDevAttrMaxSharedMemoryPerMultiprocessor, 
#line 2000
cudaDevAttrMaxRegistersPerMultiprocessor, 
#line 2001
cudaDevAttrManagedMemory, 
#line 2002
cudaDevAttrIsMultiGpuBoard, 
#line 2003
cudaDevAttrMultiGpuBoardGroupID, 
#line 2004
cudaDevAttrHostNativeAtomicSupported, 
#line 2005
cudaDevAttrSingleToDoublePrecisionPerfRatio, 
#line 2006
cudaDevAttrPageableMemoryAccess, 
#line 2007
cudaDevAttrConcurrentManagedAccess, 
#line 2008
cudaDevAttrComputePreemptionSupported, 
#line 2009
cudaDevAttrCanUseHostPointerForRegisteredMem, 
#line 2010
cudaDevAttrReserved92, 
#line 2011
cudaDevAttrReserved93, 
#line 2012
cudaDevAttrReserved94, 
#line 2013
cudaDevAttrCooperativeLaunch, 
#line 2014
cudaDevAttrReserved96, 
#line 2015
cudaDevAttrMaxSharedMemoryPerBlockOptin, 
#line 2016
cudaDevAttrCanFlushRemoteWrites, 
#line 2017
cudaDevAttrHostRegisterSupported, 
#line 2018
cudaDevAttrPageableMemoryAccessUsesHostPageTables, 
#line 2019
cudaDevAttrDirectManagedMemAccessFromHost, 
#line 2020
cudaDevAttrMaxBlocksPerMultiprocessor = 106, 
#line 2021
cudaDevAttrMaxPersistingL2CacheSize = 108, 
#line 2022
cudaDevAttrMaxAccessPolicyWindowSize, 
#line 2023
cudaDevAttrReservedSharedMemoryPerBlock = 111, 
#line 2024
cudaDevAttrSparseCudaArraySupported, 
#line 2025
cudaDevAttrHostRegisterReadOnlySupported, 
#line 2026
cudaDevAttrTimelineSemaphoreInteropSupported, 
#line 2027
cudaDevAttrMemoryPoolsSupported, 
#line 2028
cudaDevAttrGPUDirectRDMASupported, 
#line 2029
cudaDevAttrGPUDirectRDMAFlushWritesOptions, 
#line 2030
cudaDevAttrGPUDirectRDMAWritesOrdering, 
#line 2031
cudaDevAttrMemoryPoolSupportedHandleTypes, 
#line 2032
cudaDevAttrClusterLaunch, 
#line 2033
cudaDevAttrDeferredMappingCudaArraySupported, 
#line 2034
cudaDevAttrReserved122, 
#line 2035
cudaDevAttrReserved123, 
#line 2036
cudaDevAttrReserved124, 
#line 2037
cudaDevAttrIpcEventSupport, 
#line 2038
cudaDevAttrMemSyncDomainCount, 
#line 2039
cudaDevAttrReserved127, 
#line 2040
cudaDevAttrReserved128, 
#line 2041
cudaDevAttrReserved129, 
#line 2042
cudaDevAttrNumaConfig, 
#line 2043
cudaDevAttrNumaId, 
#line 2044
cudaDevAttrReserved132, 
#line 2045
cudaDevAttrMpsEnabled, 
#line 2046
cudaDevAttrHostNumaId, 
#line 2047
cudaDevAttrD3D12CigSupported, 
#line 2048
cudaDevAttrVulkanCigSupported = 138, 
#line 2049
cudaDevAttrGpuPciDeviceId, 
#line 2050
cudaDevAttrGpuPciSubsystemId, 
#line 2051
cudaDevAttrReserved141, 
#line 2052
cudaDevAttrHostNumaMemoryPoolsSupported, 
#line 2053
cudaDevAttrHostNumaMultinodeIpcSupported, 
#line 2054
cudaDevAttrHostMemoryPoolsSupported, 
#line 2055
cudaDevAttrReserved145, 
#line 2056
cudaDevAttrOnlyPartialHostNativeAtomicSupported = 147, 
#line 2058
cudaDevAttrMax
#line 2059
}; 
#endif
#line 2064 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2064
enum cudaMemPoolAttr { 
#line 2074
cudaMemPoolReuseFollowEventDependencies = 1, 
#line 2081
cudaMemPoolReuseAllowOpportunistic, 
#line 2089
cudaMemPoolReuseAllowInternalDependencies, 
#line 2100
cudaMemPoolAttrReleaseThreshold, 
#line 2106
cudaMemPoolAttrReservedMemCurrent, 
#line 2113
cudaMemPoolAttrReservedMemHigh, 
#line 2119
cudaMemPoolAttrUsedMemCurrent, 
#line 2126
cudaMemPoolAttrUsedMemHigh
#line 2127
}; 
#endif
#line 2132 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2132
enum cudaMemLocationType { 
#line 2133
cudaMemLocationTypeInvalid, 
#line 2134
cudaMemLocationTypeNone = 0, 
#line 2135
cudaMemLocationTypeDevice, 
#line 2136
cudaMemLocationTypeHost, 
#line 2137
cudaMemLocationTypeHostNuma, 
#line 2138
cudaMemLocationTypeHostNumaCurrent
#line 2139
}; 
#endif
#line 2147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2147
struct cudaMemLocation { 
#line 2148
cudaMemLocationType type; 
#line 2149
int id; 
#line 2150
}; 
#endif
#line 2155 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2155
enum cudaMemAccessFlags { 
#line 2156
cudaMemAccessFlagsProtNone, 
#line 2157
cudaMemAccessFlagsProtRead, 
#line 2158
cudaMemAccessFlagsProtReadWrite = 3
#line 2159
}; 
#endif
#line 2164 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2164
struct cudaMemAccessDesc { 
#line 2165
cudaMemLocation location; 
#line 2166
cudaMemAccessFlags flags; 
#line 2167
}; 
#endif
#line 2172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2172
enum cudaMemAllocationType { 
#line 2173
cudaMemAllocationTypeInvalid, 
#line 2177
cudaMemAllocationTypePinned, 
#line 2180
cudaMemAllocationTypeManaged, 
#line 2181
cudaMemAllocationTypeMax = 2147483647
#line 2182
}; 
#endif
#line 2187 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2187
enum cudaMemAllocationHandleType { 
#line 2188
cudaMemHandleTypeNone, 
#line 2189
cudaMemHandleTypePosixFileDescriptor, 
#line 2190
cudaMemHandleTypeWin32, 
#line 2191
cudaMemHandleTypeWin32Kmt = 4, 
#line 2192
cudaMemHandleTypeFabric = 8
#line 2193
}; 
#endif
#line 2204 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2204
struct cudaMemPoolProps { 
#line 2205
cudaMemAllocationType allocType; 
#line 2206
cudaMemAllocationHandleType handleTypes; 
#line 2207
cudaMemLocation location; 
#line 2214
void *win32SecurityAttributes; 
#line 2215
size_t maxSize; 
#line 2216
unsigned short usage; 
#line 2217
unsigned char reserved[54]; 
#line 2218
}; 
#endif
#line 2223 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2223
struct cudaMemPoolPtrExportData { 
#line 2224
unsigned char reserved[64]; 
#line 2225
}; 
#endif
#line 2230 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2230
struct cudaMemAllocNodeParams { 
#line 2235
cudaMemPoolProps poolProps; 
#line 2236
const cudaMemAccessDesc *accessDescs; 
#line 2237
size_t accessDescCount; 
#line 2238
size_t bytesize; 
#line 2239
void *dptr; 
#line 2240
}; 
#endif
#line 2245 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2245
struct cudaMemAllocNodeParamsV2 { 
#line 2250
cudaMemPoolProps poolProps; 
#line 2251
const cudaMemAccessDesc *accessDescs; 
#line 2252
size_t accessDescCount; 
#line 2253
size_t bytesize; 
#line 2254
void *dptr; 
#line 2255
}; 
#endif
#line 2260 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2260
struct cudaMemFreeNodeParams { 
#line 2261
void *dptr; 
#line 2262
}; 
#endif
#line 2267 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2267
enum cudaGraphMemAttributeType { 
#line 2272
cudaGraphMemAttrUsedMemCurrent, 
#line 2279
cudaGraphMemAttrUsedMemHigh, 
#line 2286
cudaGraphMemAttrReservedMemCurrent, 
#line 2293
cudaGraphMemAttrReservedMemHigh
#line 2294
}; 
#endif
#line 2299 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2299
enum cudaMemcpyFlags { 
#line 2300
cudaMemcpyFlagDefault, 
#line 2305
cudaMemcpyFlagPreferOverlapWithCompute
#line 2306
}; 
#endif
#line 2308 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2308
enum cudaMemcpySrcAccessOrder { 
#line 2312
cudaMemcpySrcAccessOrderInvalid, 
#line 2317
cudaMemcpySrcAccessOrderStream, 
#line 2328
cudaMemcpySrcAccessOrderDuringApiCall, 
#line 2337
cudaMemcpySrcAccessOrderAny, 
#line 2339
cudaMemcpySrcAccessOrderMax = 2147483647
#line 2340
}; 
#endif
#line 2345 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2345
struct cudaMemcpyAttributes { 
#line 2346
cudaMemcpySrcAccessOrder srcAccessOrder; 
#line 2347
cudaMemLocation srcLocHint; 
#line 2348
cudaMemLocation dstLocHint; 
#line 2349
unsigned flags; 
#line 2350
}; 
#endif
#line 2355 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2355
enum cudaMemcpy3DOperandType { 
#line 2356
cudaMemcpyOperandTypePointer = 1, 
#line 2357
cudaMemcpyOperandTypeArray, 
#line 2358
cudaMemcpyOperandTypeMax = 2147483647
#line 2359
}; 
#endif
#line 2364 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2364
struct cudaOffset3D { 
#line 2365
size_t x; 
#line 2366
size_t y; 
#line 2367
size_t z; 
#line 2368
}; 
#endif
#line 2373 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2373
struct cudaMemcpy3DOperand { 
#line 2374
cudaMemcpy3DOperandType type; 
#line 2375
union { 
#line 2379
struct { 
#line 2380
void *ptr; 
#line 2381
size_t rowLength; 
#line 2382
size_t layerHeight; 
#line 2383
cudaMemLocation locHint; 
#line 2384
} ptr; 
#line 2389
struct { 
#line 2390
cudaArray_t array; 
#line 2391
cudaOffset3D offset; 
#line 2392
} array; 
#line 2393
} op; 
#line 2394
}; 
#endif
#line 2396 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2396
struct cudaMemcpy3DBatchOp { 
#line 2397
cudaMemcpy3DOperand src; 
#line 2398
cudaMemcpy3DOperand dst; 
#line 2399
cudaExtent extent; 
#line 2400
cudaMemcpySrcAccessOrder srcAccessOrder; 
#line 2401
unsigned flags; 
#line 2402
}; 
#endif
#line 2408 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2408
enum cudaDeviceP2PAttr { 
#line 2409
cudaDevP2PAttrPerformanceRank = 1, 
#line 2410
cudaDevP2PAttrAccessSupported, 
#line 2411
cudaDevP2PAttrNativeAtomicSupported, 
#line 2412
cudaDevP2PAttrCudaArrayAccessSupported, 
#line 2414
cudaDevP2PAttrOnlyPartialNativeAtomicSupported
#line 2416
}; 
#endif
#line 2421 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2421
enum cudaAtomicOperation { 
#line 2422
cudaAtomicOperationIntegerAdd, 
#line 2423
cudaAtomicOperationIntegerMin, 
#line 2424
cudaAtomicOperationIntegerMax, 
#line 2425
cudaAtomicOperationIntegerIncrement, 
#line 2426
cudaAtomicOperationIntegerDecrement, 
#line 2427
cudaAtomicOperationAnd, 
#line 2428
cudaAtomicOperationOr, 
#line 2429
cudaAtomicOperationXOR, 
#line 2430
cudaAtomicOperationExchange, 
#line 2431
cudaAtomicOperationCAS, 
#line 2432
cudaAtomicOperationFloatAdd, 
#line 2433
cudaAtomicOperationFloatMin, 
#line 2434
cudaAtomicOperationFloatMax
#line 2435
}; 
#endif
#line 2440 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2440
enum cudaAtomicOperationCapability { 
#line 2441
cudaAtomicCapabilitySigned = (1U << 0), 
#line 2442
cudaAtomicCapabilityUnsigned, 
#line 2443
cudaAtomicCapabilityReduction = (1U << 2), 
#line 2444
cudaAtomicCapabilityScalar32 = (1U << 3), 
#line 2445
cudaAtomicCapabilityScalar64 = (1U << 4), 
#line 2446
cudaAtomicCapabilityScalar128 = (1U << 5), 
#line 2447
cudaAtomicCapabilityVector32x4 = (1U << 6)
#line 2448
}; 
#endif
#line 2457 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2457
struct CUuuid_st { 
#line 2458
char bytes[16]; 
#line 2459
}; 
#endif
#line 2460 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef CUuuid_st 
#line 2460
CUuuid; 
#endif
#line 2462 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef CUuuid_st 
#line 2462
cudaUUID_t; 
#endif
#line 2467 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2467
struct cudaDeviceProp { 
#line 2469
char name[256]; 
#line 2470
cudaUUID_t uuid; 
#line 2471
char luid[8]; 
#line 2472
unsigned luidDeviceNodeMask; 
#line 2473
size_t totalGlobalMem; 
#line 2474
size_t sharedMemPerBlock; 
#line 2475
int regsPerBlock; 
#line 2476
int warpSize; 
#line 2477
size_t memPitch; 
#line 2478
int maxThreadsPerBlock; 
#line 2479
int maxThreadsDim[3]; 
#line 2480
int maxGridSize[3]; 
#line 2481
size_t totalConstMem; 
#line 2482
int major; 
#line 2483
int minor; 
#line 2484
size_t textureAlignment; 
#line 2485
size_t texturePitchAlignment; 
#line 2486
int multiProcessorCount; 
#line 2487
int integrated; 
#line 2488
int canMapHostMemory; 
#line 2489
int maxTexture1D; 
#line 2490
int maxTexture1DMipmap; 
#line 2491
int maxTexture2D[2]; 
#line 2492
int maxTexture2DMipmap[2]; 
#line 2493
int maxTexture2DLinear[3]; 
#line 2494
int maxTexture2DGather[2]; 
#line 2495
int maxTexture3D[3]; 
#line 2496
int maxTexture3DAlt[3]; 
#line 2497
int maxTextureCubemap; 
#line 2498
int maxTexture1DLayered[2]; 
#line 2499
int maxTexture2DLayered[3]; 
#line 2500
int maxTextureCubemapLayered[2]; 
#line 2501
int maxSurface1D; 
#line 2502
int maxSurface2D[2]; 
#line 2503
int maxSurface3D[3]; 
#line 2504
int maxSurface1DLayered[2]; 
#line 2505
int maxSurface2DLayered[3]; 
#line 2506
int maxSurfaceCubemap; 
#line 2507
int maxSurfaceCubemapLayered[2]; 
#line 2508
size_t surfaceAlignment; 
#line 2509
int concurrentKernels; 
#line 2510
int ECCEnabled; 
#line 2511
int pciBusID; 
#line 2512
int pciDeviceID; 
#line 2513
int pciDomainID; 
#line 2514
int tccDriver; 
#line 2515
int asyncEngineCount; 
#line 2516
int unifiedAddressing; 
#line 2517
int memoryBusWidth; 
#line 2518
int l2CacheSize; 
#line 2519
int persistingL2CacheMaxSize; 
#line 2520
int maxThreadsPerMultiProcessor; 
#line 2521
int streamPrioritiesSupported; 
#line 2522
int globalL1CacheSupported; 
#line 2523
int localL1CacheSupported; 
#line 2524
size_t sharedMemPerMultiprocessor; 
#line 2525
int regsPerMultiprocessor; 
#line 2526
int managedMemory; 
#line 2527
int isMultiGpuBoard; 
#line 2528
int multiGpuBoardGroupID; 
#line 2529
int hostNativeAtomicSupported; 
#line 2530
int pageableMemoryAccess; 
#line 2531
int concurrentManagedAccess; 
#line 2532
int computePreemptionSupported; 
#line 2533
int canUseHostPointerForRegisteredMem; 
#line 2534
int cooperativeLaunch; 
#line 2535
size_t sharedMemPerBlockOptin; 
#line 2536
int pageableMemoryAccessUsesHostPageTables; 
#line 2537
int directManagedMemAccessFromHost; 
#line 2538
int maxBlocksPerMultiProcessor; 
#line 2539
int accessPolicyMaxWindowSize; 
#line 2540
size_t reservedSharedMemPerBlock; 
#line 2541
int hostRegisterSupported; 
#line 2542
int sparseCudaArraySupported; 
#line 2543
int hostRegisterReadOnlySupported; 
#line 2544
int timelineSemaphoreInteropSupported; 
#line 2545
int memoryPoolsSupported; 
#line 2546
int gpuDirectRDMASupported; 
#line 2547
unsigned gpuDirectRDMAFlushWritesOptions; 
#line 2548
int gpuDirectRDMAWritesOrdering; 
#line 2549
unsigned memoryPoolSupportedHandleTypes; 
#line 2550
int deferredMappingCudaArraySupported; 
#line 2551
int ipcEventSupported; 
#line 2552
int clusterLaunch; 
#line 2553
int unifiedFunctionPointers; 
#line 2554
int deviceNumaConfig; 
#line 2555
int deviceNumaId; 
#line 2556
int mpsEnabled; 
#line 2557
int hostNumaId; 
#line 2558
unsigned gpuPciDeviceID; 
#line 2559
unsigned gpuPciSubsystemID; 
#line 2560
int hostNumaMultinodeIpcSupported; 
#line 2561
int reserved[56]; 
#line 2562
}; 
#endif
#line 2575 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 2572
struct cudaIpcEventHandle_st { 
#line 2574
char reserved[64]; 
#line 2575
} cudaIpcEventHandle_t; 
#endif
#line 2583 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 2580
struct cudaIpcMemHandle_st { 
#line 2582
char reserved[64]; 
#line 2583
} cudaIpcMemHandle_t; 
#endif
#line 2591 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 2588
struct cudaMemFabricHandle_st { 
#line 2590
char reserved[64]; 
#line 2591
} cudaMemFabricHandle_t; 
#endif
#line 2596 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2596
enum cudaExternalMemoryHandleType { 
#line 2600
cudaExternalMemoryHandleTypeOpaqueFd = 1, 
#line 2604
cudaExternalMemoryHandleTypeOpaqueWin32, 
#line 2608
cudaExternalMemoryHandleTypeOpaqueWin32Kmt, 
#line 2612
cudaExternalMemoryHandleTypeD3D12Heap, 
#line 2616
cudaExternalMemoryHandleTypeD3D12Resource, 
#line 2620
cudaExternalMemoryHandleTypeD3D11Resource, 
#line 2624
cudaExternalMemoryHandleTypeD3D11ResourceKmt, 
#line 2628
cudaExternalMemoryHandleTypeNvSciBuf
#line 2629
}; 
#endif
#line 2671 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2671
struct cudaExternalMemoryHandleDesc { 
#line 2675
cudaExternalMemoryHandleType type; 
#line 2676
union { 
#line 2682
int fd; 
#line 2698
struct { 
#line 2702
void *handle; 
#line 2707
const void *name; 
#line 2708
} win32; 
#line 2713
const void *nvSciBufObject; 
#line 2714
} handle; 
#line 2718
unsigned __int64 size; 
#line 2722
unsigned flags; 
#line 2726
unsigned reserved[16]; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 2727
}; 
#endif
#line 2732 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2732
struct cudaExternalMemoryBufferDesc { 
#line 2736
unsigned __int64 offset; 
#line 2740
unsigned __int64 size; 
#line 2744
unsigned flags; 
#line 2748
unsigned reserved[16]; 
#line 2749
}; 
#endif
#line 2754 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2754
struct cudaExternalMemoryMipmappedArrayDesc { 
#line 2759
unsigned __int64 offset; 
#line 2763
cudaChannelFormatDesc formatDesc; 
#line 2767
cudaExtent extent; 
#line 2772
unsigned flags; 
#line 2776
unsigned numLevels; 
#line 2780
unsigned reserved[16]; 
#line 2781
}; 
#endif
#line 2786 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2786
enum cudaExternalSemaphoreHandleType { 
#line 2790
cudaExternalSemaphoreHandleTypeOpaqueFd = 1, 
#line 2794
cudaExternalSemaphoreHandleTypeOpaqueWin32, 
#line 2798
cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt, 
#line 2802
cudaExternalSemaphoreHandleTypeD3D12Fence, 
#line 2806
cudaExternalSemaphoreHandleTypeD3D11Fence, 
#line 2810
cudaExternalSemaphoreHandleTypeNvSciSync, 
#line 2814
cudaExternalSemaphoreHandleTypeKeyedMutex, 
#line 2818
cudaExternalSemaphoreHandleTypeKeyedMutexKmt, 
#line 2822
cudaExternalSemaphoreHandleTypeTimelineSemaphoreFd, 
#line 2826
cudaExternalSemaphoreHandleTypeTimelineSemaphoreWin32
#line 2827
}; 
#endif
#line 2832 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2832
struct cudaExternalSemaphoreHandleDesc { 
#line 2836
cudaExternalSemaphoreHandleType type; 
#line 2837
union { 
#line 2844
int fd; 
#line 2860
struct { 
#line 2864
void *handle; 
#line 2869
const void *name; 
#line 2870
} win32; 
#line 2874
const void *nvSciSyncObj; 
#line 2875
} handle; 
#line 2879
unsigned flags; 
#line 2883
unsigned reserved[16]; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 2884
}; 
#endif
#line 2889 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2889
struct cudaExternalSemaphoreSignalParams { 
#line 2890
struct { 
#line 2894
struct { 
#line 2898
unsigned __int64 value; 
#line 2899
} fence; 
#line 2900
union { 
#line 2905
void *fence; 
#line 2906
unsigned __int64 reserved; 
#line 2907
} nvSciSync; 
#line 2911
struct { 
#line 2915
unsigned __int64 key; 
#line 2916
} keyedMutex; 
#line 2917
unsigned reserved[12]; 
#line 2918
} params; 
#line 2929
unsigned flags; 
#line 2930
unsigned reserved[16]; 
#line 2931
}; 
#endif
#line 2936 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 2936
struct cudaExternalSemaphoreWaitParams { 
#line 2937
struct { 
#line 2941
struct { 
#line 2945
unsigned __int64 value; 
#line 2946
} fence; 
#line 2947
union { 
#line 2952
void *fence; 
#line 2953
unsigned __int64 reserved; 
#line 2954
} nvSciSync; 
#line 2958
struct { 
#line 2962
unsigned __int64 key; 
#line 2966
unsigned timeoutMs; 
#line 2967
} keyedMutex; 
#line 2968
unsigned reserved[10]; 
#line 2969
} params; 
#line 2980
unsigned flags; 
#line 2981
unsigned reserved[16]; 
#line 2982
}; 
#endif
#line 2993 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef cudaError 
#line 2993
cudaError_t; 
#endif
#line 2998 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUstream_st *
#line 2998
cudaStream_t; 
#endif
#line 3003 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUevent_st *
#line 3003
cudaEvent_t; 
#endif
#line 3008 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef cudaGraphicsResource *
#line 3008
cudaGraphicsResource_t; 
#endif
#line 3013 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUexternalMemory_st *
#line 3013
cudaExternalMemory_t; 
#endif
#line 3018 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUexternalSemaphore_st *
#line 3018
cudaExternalSemaphore_t; 
#endif
#line 3023 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUgraph_st *
#line 3023
cudaGraph_t; 
#endif
#line 3028 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUgraphNode_st *
#line 3028
cudaGraphNode_t; 
#endif
#line 3033 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUuserObject_st *
#line 3033
cudaUserObject_t; 
#endif
#line 3038 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef unsigned __int64 
#line 3038
cudaGraphConditionalHandle; 
#endif
#line 3043 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUfunc_st *
#line 3043
cudaFunction_t; 
#endif
#line 3048 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUkern_st *
#line 3048
cudaKernel_t; 
#endif
#line 3053 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3053
enum cudaJitOption { 
#line 3060
cudaJitMaxRegisters, 
#line 3074
cudaJitThreadsPerBlock, 
#line 3082
cudaJitWallTime, 
#line 3091
cudaJitInfoLogBuffer, 
#line 3100
cudaJitInfoLogBufferSizeBytes, 
#line 3109
cudaJitErrorLogBuffer, 
#line 3118
cudaJitErrorLogBufferSizeBytes, 
#line 3126
cudaJitOptimizationLevel, 
#line 3134
cudaJitFallbackStrategy = 10, 
#line 3142
cudaJitGenerateDebugInfo, 
#line 3149
cudaJitLogVerbose, 
#line 3156
cudaJitGenerateLineInfo, 
#line 3164
cudaJitCacheMode, 
#line 3171
cudaJitPositionIndependentCode = 30, 
#line 3184
cudaJitMinCtaPerSm, 
#line 3197
cudaJitMaxThreadsPerBlock, 
#line 3207
cudaJitOverrideDirectiveValues
#line 3208
}; 
#endif
#line 3214 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3214
enum cudaLibraryOption { 
#line 3216
cudaLibraryHostUniversalFunctionAndDataTable, 
#line 3227
cudaLibraryBinaryIsPreserved
#line 3228
}; 
#endif
#line 3230 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3230
struct cudalibraryHostUniversalFunctionAndDataTable { 
#line 3232
void *functionTable; 
#line 3233
size_t functionWindowSize; 
#line 3234
void *dataTable; 
#line 3235
size_t dataWindowSize; 
#line 3236
}; 
#endif
#line 3241 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3241
enum cudaJit_CacheMode { 
#line 3243
cudaJitCacheOptionNone, 
#line 3244
cudaJitCacheOptionCG, 
#line 3245
cudaJitCacheOptionCA
#line 3246
}; 
#endif
#line 3251 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3251
enum cudaJit_Fallback { 
#line 3253
cudaPreferPtx, 
#line 3255
cudaPreferBinary
#line 3256
}; 
#endif
#line 3261 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUlib_st *
#line 3261
cudaLibrary_t; 
#endif
#line 3266 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUmemPoolHandle_st *
#line 3266
cudaMemPool_t; 
#endif
#line 3271 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3271
enum cudaCGScope { 
#line 3272
cudaCGScopeInvalid, 
#line 3273
cudaCGScopeGrid, 
#line 3274
cudaCGScopeReserved
#line 3275
}; 
#endif
#line 3280 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3280
struct cudaKernelNodeParams { 
#line 3281
void *func; 
#line 3282
dim3 gridDim; 
#line 3283
dim3 blockDim; 
#line 3284
unsigned sharedMemBytes; 
#line 3285
void **kernelParams; 
#line 3286
void **extra; 
#line 3287
}; 
#endif
#line 3292 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3292
struct cudaKernelNodeParamsV2 { 
#line 3293
void *func; 
#line 3299 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
uint3 gridDim; 
#line 3300
uint3 blockDim; 
#line 3302 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
unsigned sharedMemBytes; 
#line 3303
void **kernelParams; 
#line 3304
void **extra; 
#line 3305
}; 
#endif
#line 3310 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3310
struct cudaExternalSemaphoreSignalNodeParams { 
#line 3311
cudaExternalSemaphore_t *extSemArray; 
#line 3312
const cudaExternalSemaphoreSignalParams *paramsArray; 
#line 3313
unsigned numExtSems; 
#line 3314
}; 
#endif
#line 3319 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3319
struct cudaExternalSemaphoreSignalNodeParamsV2 { 
#line 3320
cudaExternalSemaphore_t *extSemArray; 
#line 3321
const cudaExternalSemaphoreSignalParams *paramsArray; 
#line 3322
unsigned numExtSems; 
#line 3323
}; 
#endif
#line 3328 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3328
struct cudaExternalSemaphoreWaitNodeParams { 
#line 3329
cudaExternalSemaphore_t *extSemArray; 
#line 3330
const cudaExternalSemaphoreWaitParams *paramsArray; 
#line 3331
unsigned numExtSems; 
#line 3332
}; 
#endif
#line 3337 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3337
struct cudaExternalSemaphoreWaitNodeParamsV2 { 
#line 3338
cudaExternalSemaphore_t *extSemArray; 
#line 3339
const cudaExternalSemaphoreWaitParams *paramsArray; 
#line 3340
unsigned numExtSems; 
#line 3341
}; 
#endif
#line 3343 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3343
enum cudaGraphConditionalHandleFlags { 
#line 3344
cudaGraphCondAssignDefault = 1
#line 3345
}; 
#endif
#line 3350 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3350
enum cudaGraphConditionalNodeType { 
#line 3351
cudaGraphCondTypeIf, 
#line 3352
cudaGraphCondTypeWhile, 
#line 3353
cudaGraphCondTypeSwitch
#line 3354
}; 
#endif
#line 3359 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3359
struct cudaConditionalNodeParams { 
#line 3360
cudaGraphConditionalHandle handle; 
#line 3363
cudaGraphConditionalNodeType type; 
#line 3364
unsigned size; 
#line 3366
cudaGraph_t *phGraph_out; 
#line 3385
}; 
#endif
#line 3390 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3390
enum cudaGraphNodeType { 
#line 3391
cudaGraphNodeTypeKernel, 
#line 3392
cudaGraphNodeTypeMemcpy, 
#line 3393
cudaGraphNodeTypeMemset, 
#line 3394
cudaGraphNodeTypeHost, 
#line 3395
cudaGraphNodeTypeGraph, 
#line 3396
cudaGraphNodeTypeEmpty, 
#line 3397
cudaGraphNodeTypeWaitEvent, 
#line 3398
cudaGraphNodeTypeEventRecord, 
#line 3399
cudaGraphNodeTypeExtSemaphoreSignal, 
#line 3400
cudaGraphNodeTypeExtSemaphoreWait, 
#line 3401
cudaGraphNodeTypeMemAlloc, 
#line 3402
cudaGraphNodeTypeMemFree, 
#line 3403
cudaGraphNodeTypeConditional = 13, 
#line 3420
cudaGraphNodeTypeCount
#line 3421
}; 
#endif
#line 3426 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3426
enum cudaGraphChildGraphNodeOwnership { 
#line 3427
cudaGraphChildGraphOwnershipClone, 
#line 3430
cudaGraphChildGraphOwnershipMove
#line 3439
}; 
#endif
#line 3444 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3444
struct cudaChildGraphNodeParams { 
#line 3445
cudaGraph_t graph; 
#line 3451
cudaGraphChildGraphNodeOwnership ownership; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 3452
}; 
#endif
#line 3457 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3457
struct cudaEventRecordNodeParams { 
#line 3458
cudaEvent_t event; 
#line 3459
}; 
#endif
#line 3464 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3464
struct cudaEventWaitNodeParams { 
#line 3465
cudaEvent_t event; 
#line 3466
}; 
#endif
#line 3471 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3471
struct cudaGraphNodeParams { 
#line 3472
cudaGraphNodeType type; 
#line 3473
int reserved0[3]; 
#line 3475
union { 
#line 3476
__int64 reserved1[29]; 
#line 3477
cudaKernelNodeParamsV2 kernel; 
#line 3478
cudaMemcpyNodeParams memcpy; 
#line 3479
cudaMemsetParamsV2 memset; 
#line 3480
cudaHostNodeParamsV2 host; 
#line 3481
cudaChildGraphNodeParams graph; 
#line 3482
cudaEventWaitNodeParams eventWait; 
#line 3483
cudaEventRecordNodeParams eventRecord; 
#line 3484
cudaExternalSemaphoreSignalNodeParamsV2 extSemSignal; 
#line 3485
cudaExternalSemaphoreWaitNodeParamsV2 extSemWait; 
#line 3486
cudaMemAllocNodeParamsV2 alloc; 
#line 3487
cudaMemFreeNodeParams free; 
#line 3488
cudaConditionalNodeParams conditional; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 3489
}; 
#line 3491
__int64 reserved2; 
#line 3492
}; 
#endif
#line 3504 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3497
enum cudaGraphDependencyType_enum { 
#line 3498
cudaGraphDependencyTypeDefault, 
#line 3499
cudaGraphDependencyTypeProgrammatic
#line 3504
} cudaGraphDependencyType; 
#endif
#line 3534 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3511
struct cudaGraphEdgeData_st { 
#line 3512
unsigned char from_port; 
#line 3522
unsigned char to_port; 
#line 3529
unsigned char type; 
#line 3532
unsigned char reserved[5]; 
#line 3534
} cudaGraphEdgeData; 
#endif
#line 3555 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
typedef struct CUgraphExec_st *cudaGraphExec_t; 
#line 3560
#if 0
#line 3560
enum cudaGraphExecUpdateResult { 
#line 3561
cudaGraphExecUpdateSuccess, 
#line 3562
cudaGraphExecUpdateError, 
#line 3563
cudaGraphExecUpdateErrorTopologyChanged, 
#line 3564
cudaGraphExecUpdateErrorNodeTypeChanged, 
#line 3565
cudaGraphExecUpdateErrorFunctionChanged, 
#line 3566
cudaGraphExecUpdateErrorParametersChanged, 
#line 3567
cudaGraphExecUpdateErrorNotSupported, 
#line 3568
cudaGraphExecUpdateErrorUnsupportedFunctionChange, 
#line 3569
cudaGraphExecUpdateErrorAttributesChanged
#line 3570
}; 
#endif
#line 3582 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3575
enum cudaGraphInstantiateResult { 
#line 3576
cudaGraphInstantiateSuccess, 
#line 3577
cudaGraphInstantiateError, 
#line 3578
cudaGraphInstantiateInvalidStructure, 
#line 3579
cudaGraphInstantiateNodeOperationNotSupported, 
#line 3580
cudaGraphInstantiateMultipleDevicesNotSupported, 
#line 3581
cudaGraphInstantiateConditionalHandleUnused
#line 3582
} cudaGraphInstantiateResult; 
#endif
#line 3593 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3587
struct cudaGraphInstantiateParams_st { 
#line 3589
unsigned __int64 flags; 
#line 3590
cudaStream_t uploadStream; 
#line 3591
cudaGraphNode_t errNode_out; 
#line 3592
cudaGraphInstantiateResult result_out; 
#line 3593
} cudaGraphInstantiateParams; 
#endif
#line 3615 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3598
struct cudaGraphExecUpdateResultInfo_st { 
#line 3602
cudaGraphExecUpdateResult result; 
#line 3609
cudaGraphNode_t errorNode; 
#line 3614
cudaGraphNode_t errorFromNode; 
#line 3615
} cudaGraphExecUpdateResultInfo; 
#endif
#line 3620 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
typedef struct CUgraphDeviceUpdatableNode_st *cudaGraphDeviceNode_t; 
#line 3625
#if 0
#line 3625
enum cudaGraphKernelNodeField { 
#line 3627
cudaGraphKernelNodeFieldInvalid, 
#line 3628
cudaGraphKernelNodeFieldGridDim, 
#line 3629
cudaGraphKernelNodeFieldParam, 
#line 3630
cudaGraphKernelNodeFieldEnabled
#line 3631
}; 
#endif
#line 3636 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3636
struct cudaGraphKernelNodeUpdate { 
#line 3637
cudaGraphDeviceNode_t node; 
#line 3638
cudaGraphKernelNodeField field; 
#line 3639
union { 
#line 3644 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
uint3 gridDim; 
#line 3646 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
struct { 
#line 3647
const void *pValue; 
#line 3648
size_t offset; 
#line 3649
size_t size; 
#line 3650
} param; 
#line 3651
unsigned isEnabled; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 3652
} updateData; 
#line 3653
}; 
#endif
#line 3659 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3659
enum cudaGetDriverEntryPointFlags { 
#line 3660
cudaEnableDefault, 
#line 3661
cudaEnableLegacyStream, 
#line 3662
cudaEnablePerThreadDefaultStream
#line 3663
}; 
#endif
#line 3668 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3668
enum cudaDriverEntryPointQueryResult { 
#line 3669
cudaDriverEntryPointSuccess, 
#line 3670
cudaDriverEntryPointSymbolNotFound, 
#line 3671
cudaDriverEntryPointVersionNotSufficent
#line 3672
}; 
#endif
#line 3677 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3677
enum cudaGraphDebugDotFlags { 
#line 3678
cudaGraphDebugDotFlagsVerbose = (1 << 0), 
#line 3679
cudaGraphDebugDotFlagsKernelNodeParams = (1 << 2), 
#line 3680
cudaGraphDebugDotFlagsMemcpyNodeParams = (1 << 3), 
#line 3681
cudaGraphDebugDotFlagsMemsetNodeParams = (1 << 4), 
#line 3682
cudaGraphDebugDotFlagsHostNodeParams = (1 << 5), 
#line 3683
cudaGraphDebugDotFlagsEventNodeParams = (1 << 6), 
#line 3684
cudaGraphDebugDotFlagsExtSemasSignalNodeParams = (1 << 7), 
#line 3685
cudaGraphDebugDotFlagsExtSemasWaitNodeParams = (1 << 8), 
#line 3686
cudaGraphDebugDotFlagsKernelNodeAttributes = (1 << 9), 
#line 3687
cudaGraphDebugDotFlagsHandles = (1 << 10), 
#line 3688
cudaGraphDebugDotFlagsConditionalNodeParams = (1 << 15)
#line 3689
}; 
#endif
#line 3694 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 3694
enum cudaGraphInstantiateFlags { 
#line 3695
cudaGraphInstantiateFlagAutoFreeOnLaunch = 1, 
#line 3696
cudaGraphInstantiateFlagUpload, 
#line 3699
cudaGraphInstantiateFlagDeviceLaunch = 4, 
#line 3702
cudaGraphInstantiateFlagUseNodePriority = 8
#line 3704
}; 
#endif
#line 3725 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3722
enum cudaLaunchMemSyncDomain { 
#line 3723
cudaLaunchMemSyncDomainDefault, 
#line 3724
cudaLaunchMemSyncDomainRemote
#line 3725
} cudaLaunchMemSyncDomain; 
#endif
#line 3741 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3738
struct cudaLaunchMemSyncDomainMap_st { 
#line 3739
unsigned char default_; 
#line 3740
unsigned char remote; 
#line 3741
} cudaLaunchMemSyncDomainMap; 
#endif
#line 3906 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3746
enum cudaLaunchAttributeID { 
#line 3747
cudaLaunchAttributeIgnore, 
#line 3748
cudaLaunchAttributeAccessPolicyWindow, 
#line 3750
cudaLaunchAttributeCooperative, 
#line 3752
cudaLaunchAttributeSynchronizationPolicy, 
#line 3753
cudaLaunchAttributeClusterDimension, 
#line 3755
cudaLaunchAttributeClusterSchedulingPolicyPreference, 
#line 3757
cudaLaunchAttributeProgrammaticStreamSerialization, 
#line 3768
cudaLaunchAttributeProgrammaticEvent, 
#line 3794
cudaLaunchAttributePriority, 
#line 3796
cudaLaunchAttributeMemSyncDomainMap, 
#line 3798
cudaLaunchAttributeMemSyncDomain, 
#line 3800
cudaLaunchAttributePreferredClusterDimension, 
#line 3836
cudaLaunchAttributeLaunchCompletionEvent, 
#line 3858
cudaLaunchAttributeDeviceUpdatableKernelNode, 
#line 3886
cudaLaunchAttributePreferredSharedMemoryCarveout, 
#line 3893
cudaLaunchAttributeNvlinkUtilCentricScheduling = 16
#line 3906
} cudaLaunchAttributeID; 
#endif
#line 4004 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 3911
union cudaLaunchAttributeValue { 
#line 3912
char pad[64]; 
#line 3913
cudaAccessPolicyWindow accessPolicyWindow; 
#line 3914
int cooperative; 
#line 3916
cudaSynchronizationPolicy syncPolicy; 
#line 3930
struct { 
#line 3931
unsigned x; 
#line 3932
unsigned y; 
#line 3933
unsigned z; 
#line 3934
} clusterDim; 
#line 3935
cudaClusterSchedulingPolicy clusterSchedulingPolicyPreference; 
#line 3938
int programmaticStreamSerializationAllowed; 
#line 3949
struct { 
#line 3950
cudaEvent_t event; 
#line 3951
int flags; 
#line 3952
int triggerAtBlockStart; 
#line 3953
} programmaticEvent; 
#line 3954
int priority; 
#line 3955
cudaLaunchMemSyncDomainMap memSyncDomainMap; 
#line 3958
cudaLaunchMemSyncDomain memSyncDomain; 
#line 3973
struct { 
#line 3974
unsigned x; 
#line 3975
unsigned y; 
#line 3976
unsigned z; 
#line 3977
} preferredClusterDim; 
#line 3986
struct { 
#line 3987
cudaEvent_t event; 
#line 3988
int flags; 
#line 3989
} launchCompletionEvent; 
#line 3997
struct { 
#line 3998
int deviceUpdatable; 
#line 3999
cudaGraphDeviceNode_t devNode; 
#line 4000
} deviceUpdatableKernelNode; 
#line 4001
unsigned sharedMemCarveout; 
#line 4002
unsigned nvlinkUtilCentricScheduling; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 4004
} cudaLaunchAttributeValue; 
#endif
#line 4013 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 4009
struct cudaLaunchAttribute_st { 
#line 4010
cudaLaunchAttributeID id; 
#line 4011
char pad[(8) - sizeof(cudaLaunchAttributeID)]; 
#line 4012
cudaLaunchAttributeValue val; 
#line 4013
} cudaLaunchAttribute; 
#endif
#line 4025 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 4018
struct cudaLaunchConfig_st { 
#line 4019
dim3 gridDim; 
#line 4020
dim3 blockDim; 
#line 4021
size_t dynamicSmemBytes; 
#line 4022
cudaStream_t stream; 
#line 4023
cudaLaunchAttribute *attrs; 
#line 4024
unsigned numAttrs; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 4025
} cudaLaunchConfig_t; 
#endif
#line 4054 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
#line 4054
enum cudaDeviceNumaConfig { 
#line 4055
cudaDeviceNumaConfigNone, 
#line 4056
cudaDeviceNumaConfigNumaNode
#line 4057
}; 
#endif
#line 4062 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
typedef struct cudaAsyncCallbackEntry *cudaAsyncCallbackHandle_t; 
#line 4064
struct cudaAsyncCallbackEntry; 
#line 4071
#if 0
typedef 
#line 4069
enum cudaAsyncNotificationType_enum { 
#line 4070
cudaAsyncNotificationTypeOverBudget = 1
#line 4071
} cudaAsyncNotificationType; 
#endif
#line 4084 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef 
#line 4076
struct cudaAsyncNotificationInfo { 
#line 4078
cudaAsyncNotificationType type; 
#line 4079
union { 
#line 4080
struct { 
#line 4081
unsigned __int64 bytesOverBudget; 
#line 4082
} overBudget; 
#line 4083
} info; 
#line 4084
} cudaAsyncNotificationInfo_t; 
#endif
#line 4086 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
typedef void (*cudaAsyncCallback)(cudaAsyncNotificationInfo_t *, void *, cudaAsyncCallbackHandle_t); 
#line 4091
#if 0
typedef 
#line 4088
enum CUDAlogLevel_enum { 
#line 4089
cudaLogLevelError, 
#line 4090
cudaLogLevelWarning
#line 4091
} cudaLogLevel; 
#endif
#line 4093 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef struct CUlogsCallbackEntry_st *
#line 4093
cudaLogsCallbackHandle; 
#endif
#line 4094 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_types.h"
#if 0
typedef unsigned 
#line 4094
cudaLogIterator; 
#endif
#line 86 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_types.h"
#if 0
#line 86
enum cudaSurfaceBoundaryMode { 
#line 88
cudaBoundaryModeZero, 
#line 89
cudaBoundaryModeClamp, 
#line 90
cudaBoundaryModeTrap
#line 91
}; 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_types.h"
#if 0
#line 96
enum cudaSurfaceFormatMode { 
#line 98
cudaFormatModeForced, 
#line 99
cudaFormatModeAuto
#line 100
}; 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_types.h"
#if 0
typedef unsigned __int64 
#line 105
cudaSurfaceObject_t; 
#endif
#line 86 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_types.h"
#if 0
#line 86
enum cudaTextureAddressMode { 
#line 88
cudaAddressModeWrap, 
#line 89
cudaAddressModeClamp, 
#line 90
cudaAddressModeMirror, 
#line 91
cudaAddressModeBorder
#line 92
}; 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_types.h"
#if 0
#line 97
enum cudaTextureFilterMode { 
#line 99
cudaFilterModePoint, 
#line 100
cudaFilterModeLinear
#line 101
}; 
#endif
#line 106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_types.h"
#if 0
#line 106
enum cudaTextureReadMode { 
#line 108
cudaReadModeElementType, 
#line 109
cudaReadModeNormalizedFloat
#line 110
}; 
#endif
#line 115 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_types.h"
#if 0
#line 115
struct cudaTextureDesc { 
#line 120
cudaTextureAddressMode addressMode[3]; 
#line 124
cudaTextureFilterMode filterMode; 
#line 128
cudaTextureReadMode readMode; 
#line 132
int sRGB; 
#line 136
float borderColor[4]; 
#line 140
int normalizedCoords; 
#line 144
unsigned maxAnisotropy; 
#line 148
cudaTextureFilterMode mipmapFilterMode; 
#line 152
float mipmapLevelBias; 
#line 156
float minMipmapLevelClamp; 
#line 160
float maxMipmapLevelClamp; 
#line 164
int disableTrilinearOptimization; 
#line 168
int seamlessCubemap; 
#line 169
}; 
#endif
#line 174 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_types.h"
#if 0
typedef unsigned __int64 
#line 174
cudaTextureObject_t; 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\library_types.h"
typedef 
#line 57
enum cudaDataType_t { 
#line 59
CUDA_R_16F = 2, 
#line 60
CUDA_C_16F = 6, 
#line 61
CUDA_R_16BF = 14, 
#line 62
CUDA_C_16BF, 
#line 63
CUDA_R_32F = 0, 
#line 64
CUDA_C_32F = 4, 
#line 65
CUDA_R_64F = 1, 
#line 66
CUDA_C_64F = 5, 
#line 67
CUDA_R_4I = 16, 
#line 68
CUDA_C_4I, 
#line 69
CUDA_R_4U, 
#line 70
CUDA_C_4U, 
#line 71
CUDA_R_8I = 3, 
#line 72
CUDA_C_8I = 7, 
#line 73
CUDA_R_8U, 
#line 74
CUDA_C_8U, 
#line 75
CUDA_R_16I = 20, 
#line 76
CUDA_C_16I, 
#line 77
CUDA_R_16U, 
#line 78
CUDA_C_16U, 
#line 79
CUDA_R_32I = 10, 
#line 80
CUDA_C_32I, 
#line 81
CUDA_R_32U, 
#line 82
CUDA_C_32U, 
#line 83
CUDA_R_64I = 24, 
#line 84
CUDA_C_64I, 
#line 85
CUDA_R_64U, 
#line 86
CUDA_C_64U, 
#line 87
CUDA_R_8F_E4M3, 
#line 88
CUDA_R_8F_UE4M3 = CUDA_R_8F_E4M3, 
#line 89
CUDA_R_8F_E5M2, 
#line 90
CUDA_R_8F_UE8M0, 
#line 91
CUDA_R_6F_E2M3, 
#line 92
CUDA_R_6F_E3M2, 
#line 93
CUDA_R_4F_E2M1
#line 94
} cudaDataType; 
#line 115
typedef 
#line 98
enum cudaEmulationStrategy_t { 
#line 104
CUDA_EMULATION_STRATEGY_DEFAULT, 
#line 109
CUDA_EMULATION_STRATEGY_PERFORMANT, 
#line 114
CUDA_EMULATION_STRATEGY_EAGER
#line 115
} cudaEmulationStrategy; 
#line 131
typedef 
#line 120
enum cudaEmulationMantissaControl_t { 
#line 126
CUDA_EMULATION_MANTISSA_CONTROL_DYNAMIC, 
#line 130
CUDA_EMULATION_MANTISSA_CONTROL_FIXED
#line 131
} cudaEmulationMantissaControl; 
#line 156
typedef 
#line 136
enum cudaEmulationSpecialValuesSupport_t { 
#line 141
CUDA_EMULATION_SPECIAL_VALUES_SUPPORT_DEFAULT = 65535, 
#line 146
CUDA_EMULATION_SPECIAL_VALUES_SUPPORT_NONE = 0, 
#line 151
CUDA_EMULATION_SPECIAL_VALUES_SUPPORT_INFINITY, 
#line 155
CUDA_EMULATION_SPECIAL_VALUES_SUPPORT_NAN
#line 156
} cudaEmulationSpecialValuesSupport; 
#line 163
typedef 
#line 158
enum libraryPropertyType_t { 
#line 160
MAJOR_VERSION, 
#line 161
MINOR_VERSION, 
#line 162
PATCH_LEVEL
#line 163
} libraryPropertyType; 
#line 13 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_malloc.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 58 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_malloc.h"
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 59
_calloc_base(size_t _Count, size_t _Size); 
#line 65
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 66
calloc(size_t _Count, size_t _Size); 
#line 72
int __cdecl _callnewh(size_t _Size); 
#line 77
__declspec(allocator) void *__cdecl 
#line 78
_expand(void * _Block, size_t _Size); 
#line 84
void __cdecl _free_base(void * _Block); 
#line 89
void __cdecl free(void * _Block); 
#line 94
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 95
_malloc_base(size_t _Size); 
#line 100
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 101
malloc(size_t _Size); 
#line 107
size_t __cdecl _msize_base(void * _Block) noexcept; 
#line 113
size_t __cdecl _msize(void * _Block); 
#line 118
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 119
_realloc_base(void * _Block, size_t _Size); 
#line 125
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 126
realloc(void * _Block, size_t _Size); 
#line 132
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 133
_recalloc_base(void * _Block, size_t _Count, size_t _Size); 
#line 140
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 141
_recalloc(void * _Block, size_t _Count, size_t _Size); 
#line 148
void __cdecl _aligned_free(void * _Block); 
#line 153
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 154
_aligned_malloc(size_t _Size, size_t _Alignment); 
#line 160
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 161
_aligned_offset_malloc(size_t _Size, size_t _Alignment, size_t _Offset); 
#line 169
size_t __cdecl _aligned_msize(void * _Block, size_t _Alignment, size_t _Offset); 
#line 176
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 177
_aligned_offset_realloc(void * _Block, size_t _Size, size_t _Alignment, size_t _Offset); 
#line 185
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 186
_aligned_offset_recalloc(void * _Block, size_t _Count, size_t _Size, size_t _Alignment, size_t _Offset); 
#line 195
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 196
_aligned_realloc(void * _Block, size_t _Size, size_t _Alignment); 
#line 203
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 204
_aligned_recalloc(void * _Block, size_t _Count, size_t _Size, size_t _Alignment); 
#line 232 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_malloc.h"
}__pragma( pack ( pop )) 
#line 234
#pragma warning(pop)
#line 16 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_search.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 20
__pragma( pack ( push, 8 )) extern "C" {
#line 23
typedef int (__cdecl *_CoreCrtSecureSearchSortCompareFunction)(void *, const void *, const void *); 
#line 24
typedef int (__cdecl *_CoreCrtNonSecureSearchSortCompareFunction)(const void *, const void *); 
#line 30
void *__cdecl bsearch_s(const void * _Key, const void * _Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 39
void __cdecl qsort_s(void * _Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 52 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_search.h"
void *__cdecl bsearch(const void * _Key, const void * _Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 60
void __cdecl qsort(void * _Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 68
void *__cdecl _lfind_s(const void * _Key, const void * _Base, unsigned * _NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 78
void *__cdecl _lfind(const void * _Key, const void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 87
void *__cdecl _lsearch_s(const void * _Key, void * _Base, unsigned * _NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 97
void *__cdecl _lsearch(const void * _Key, void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 195 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_search.h"
void *__cdecl lfind(const void * _Key, const void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 204
void *__cdecl lsearch(const void * _Key, void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 216 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_search.h"
}__pragma( pack ( pop )) 
#line 218
#pragma warning(pop)
#line 13 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 54
errno_t __cdecl _itow_s(int _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 61
extern "C++" {template < size_t _Size > inline errno_t __cdecl _itow_s ( int _Value, wchar_t ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _itow_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 68 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
__wchar_t *__cdecl _itow(int _Value, __wchar_t * _Buffer, int _Radix); 
#line 77 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
errno_t __cdecl _ltow_s(long _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 84
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ltow_s ( long _Value, wchar_t ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ltow_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 91 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
__wchar_t *__cdecl _ltow(long _Value, __wchar_t * _Buffer, int _Radix); 
#line 99 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
errno_t __cdecl _ultow_s(unsigned long _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 106
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ultow_s ( unsigned long _Value, wchar_t ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ultow_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 113 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
__wchar_t *__cdecl _ultow(unsigned long _Value, __wchar_t * _Buffer, int _Radix); 
#line 121 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
double __cdecl wcstod(const __wchar_t * _String, __wchar_t ** _EndPtr); 
#line 127
double __cdecl _wcstod_l(const __wchar_t * _String, __wchar_t ** _EndPtr, _locale_t _Locale); 
#line 134
long __cdecl wcstol(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 141
long __cdecl _wcstol_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 149
__int64 __cdecl wcstoll(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 156
__int64 __cdecl _wcstoll_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 164
unsigned long __cdecl wcstoul(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 171
unsigned long __cdecl _wcstoul_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 179
unsigned __int64 __cdecl wcstoull(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 186
unsigned __int64 __cdecl _wcstoull_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 194
long double __cdecl wcstold(const __wchar_t * _String, __wchar_t ** _EndPtr); 
#line 200
long double __cdecl _wcstold_l(const __wchar_t * _String, __wchar_t ** _EndPtr, _locale_t _Locale); 
#line 207
float __cdecl wcstof(const __wchar_t * _String, __wchar_t ** _EndPtr); 
#line 213
float __cdecl _wcstof_l(const __wchar_t * _String, __wchar_t ** _EndPtr, _locale_t _Locale); 
#line 220
double __cdecl _wtof(const __wchar_t * _String); 
#line 225
double __cdecl _wtof_l(const __wchar_t * _String, _locale_t _Locale); 
#line 231
int __cdecl _wtoi(const __wchar_t * _String); 
#line 236
int __cdecl _wtoi_l(const __wchar_t * _String, _locale_t _Locale); 
#line 242
long __cdecl _wtol(const __wchar_t * _String); 
#line 247
long __cdecl _wtol_l(const __wchar_t * _String, _locale_t _Locale); 
#line 253
__int64 __cdecl _wtoll(const __wchar_t * _String); 
#line 258
__int64 __cdecl _wtoll_l(const __wchar_t * _String, _locale_t _Locale); 
#line 264
errno_t __cdecl _i64tow_s(__int64 _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 272
__wchar_t *__cdecl _i64tow(__int64 _Value, __wchar_t * _Buffer, int _Radix); 
#line 279
errno_t __cdecl _ui64tow_s(unsigned __int64 _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 287
__wchar_t *__cdecl _ui64tow(unsigned __int64 _Value, __wchar_t * _Buffer, int _Radix); 
#line 294
__int64 __cdecl _wtoi64(const __wchar_t * _String); 
#line 299
__int64 __cdecl _wtoi64_l(const __wchar_t * _String, _locale_t _Locale); 
#line 305
__int64 __cdecl _wcstoi64(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 312
__int64 __cdecl _wcstoi64_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 320
unsigned __int64 __cdecl _wcstoui64(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 327
unsigned __int64 __cdecl _wcstoui64_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 339
__declspec(allocator) __wchar_t *__cdecl _wfullpath(__wchar_t * _Buffer, const __wchar_t * _Path, size_t _BufferCount); 
#line 348
errno_t __cdecl _wmakepath_s(__wchar_t * _Buffer, size_t _BufferCount, const __wchar_t * _Drive, const __wchar_t * _Dir, const __wchar_t * _Filename, const __wchar_t * _Ext); 
#line 357
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wmakepath_s ( wchar_t ( & _Buffer ) [ _Size ], wchar_t const * _Drive, wchar_t const * _Dir, wchar_t const * _Filename, wchar_t const * _Ext ) throw ( ) { return _wmakepath_s ( _Buffer, _Size, _Drive, _Dir, _Filename, _Ext ); }}
#line 366 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
void __cdecl _wmakepath(__wchar_t * _Buffer, const __wchar_t * _Drive, const __wchar_t * _Dir, const __wchar_t * _Filename, const __wchar_t * _Ext); 
#line 375 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
void __cdecl _wperror(const __wchar_t * _ErrorMessage); 
#line 380
void __cdecl _wsplitpath(const __wchar_t * _FullPath, __wchar_t * _Drive, __wchar_t * _Dir, __wchar_t * _Filename, __wchar_t * _Ext); 
#line 388
errno_t __cdecl _wsplitpath_s(const __wchar_t * _FullPath, __wchar_t * _Drive, size_t _DriveCount, __wchar_t * _Dir, size_t _DirCount, __wchar_t * _Filename, size_t _FilenameCount, __wchar_t * _Ext, size_t _ExtCount); 
#line 400
extern "C++" {template < size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize > inline errno_t __cdecl _wsplitpath_s ( wchar_t const * _Path, wchar_t ( & _Drive ) [ _DriveSize ], wchar_t ( & _Dir ) [ _DirSize ], wchar_t ( & _Name ) [ _NameSize ], wchar_t ( & _Ext ) [ _ExtSize ] ) throw ( ) { return _wsplitpath_s ( _Path, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize ); }}
#line 409 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
errno_t __cdecl _wdupenv_s(__wchar_t ** _Buffer, size_t * _BufferCount, const __wchar_t * _VarName); 
#line 418
__wchar_t *__cdecl _wgetenv(const __wchar_t * _VarName); 
#line 424
errno_t __cdecl _wgetenv_s(size_t * _RequiredCount, __wchar_t * _Buffer, size_t _BufferCount, const __wchar_t * _VarName); 
#line 431
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wgetenv_s ( size_t * _RequiredCount, wchar_t ( & _Buffer ) [ _Size ], wchar_t const * _VarName ) throw ( ) { return _wgetenv_s ( _RequiredCount, _Buffer, _Size, _VarName ); }}
#line 440 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
int __cdecl _wputenv(const __wchar_t * _EnvString); 
#line 445
errno_t __cdecl _wputenv_s(const __wchar_t * _Name, const __wchar_t * _Value); 
#line 450
errno_t __cdecl _wsearchenv_s(const __wchar_t * _Filename, const __wchar_t * _VarName, __wchar_t * _Buffer, size_t _BufferCount); 
#line 457
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wsearchenv_s ( wchar_t const * _Filename, wchar_t const * _VarName, wchar_t ( & _ResultPath ) [ _Size ] ) throw ( ) { return _wsearchenv_s ( _Filename, _VarName, _ResultPath, _Size ); }}
#line 464 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
void __cdecl _wsearchenv(const __wchar_t * _Filename, const __wchar_t * _VarName, __wchar_t * _ResultPath); 
#line 471 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
int __cdecl _wsystem(const __wchar_t * _Command); 
#line 479 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstdlib.h"
}__pragma( pack ( pop )) 
#line 481
#pragma warning(pop)
#line 18 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 22
__pragma( pack ( push, 8 )) extern "C" {
#line 38 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
void __cdecl _swab(char * _Buf1, char * _Buf2, int _SizeInBytes); 
#line 56
__declspec(noreturn) void __cdecl exit(int _Code); 
#line 57
__declspec(noreturn) void __cdecl _exit(int _Code); 
#line 58
__declspec(noreturn) void __cdecl _Exit(int _Code); 
#line 59
__declspec(noreturn) void __cdecl quick_exit(int _Code); 
#line 60
__declspec(noreturn) void __cdecl abort(); 
#line 67 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
unsigned __cdecl _set_abort_behavior(unsigned _Flags, unsigned _Mask); 
#line 77
typedef int (__cdecl *_onexit_t)(void); 
#line 144 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
int __cdecl atexit(void (__cdecl *)(void)); 
#line 145
_onexit_t __cdecl _onexit(_onexit_t _Func); 
#line 148 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
int __cdecl at_quick_exit(void (__cdecl *)(void)); 
#line 159
typedef void (__cdecl *_purecall_handler)(void); 
#line 162
typedef void (__cdecl *_invalid_parameter_handler)(const __wchar_t *, const __wchar_t *, const __wchar_t *, unsigned, uintptr_t); 
#line 171
_purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler); 
#line 175
_purecall_handler __cdecl _get_purecall_handler(); 
#line 178
_invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler); 
#line 182
_invalid_parameter_handler __cdecl _get_invalid_parameter_handler(); 
#line 184
_invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(_invalid_parameter_handler _Handler); 
#line 188
_invalid_parameter_handler __cdecl _get_thread_local_invalid_parameter_handler(); 
#line 212 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
int __cdecl _set_error_mode(int _Mode); 
#line 217
int *__cdecl _errno(); 
#line 220
errno_t __cdecl _set_errno(int _Value); 
#line 221
errno_t __cdecl _get_errno(int * _Value); 
#line 223
unsigned long *__cdecl __doserrno(); 
#line 226
errno_t __cdecl _set_doserrno(unsigned long _Value); 
#line 227
errno_t __cdecl _get_doserrno(unsigned long * _Value); 
#line 230
char **__cdecl __sys_errlist(); 
#line 233
int *__cdecl __sys_nerr(); 
#line 236
void __cdecl perror(const char * _ErrMsg); 
#line 242 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char **__cdecl __p__pgmptr(); 
#line 243
__wchar_t **__cdecl __p__wpgmptr(); 
#line 244
int *__cdecl __p__fmode(); 
#line 259 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _get_pgmptr(char ** _Value); 
#line 262
errno_t __cdecl _get_wpgmptr(__wchar_t ** _Value); 
#line 264
errno_t __cdecl _set_fmode(int _Mode); 
#line 266
errno_t __cdecl _get_fmode(int * _PMode); 
#line 279
typedef 
#line 275
struct _div_t { 
#line 277
int quot; 
#line 278
int rem; 
#line 279
} div_t; 
#line 285
typedef 
#line 281
struct _ldiv_t { 
#line 283
long quot; 
#line 284
long rem; 
#line 285
} ldiv_t; 
#line 291
typedef 
#line 287
struct _lldiv_t { 
#line 289
__int64 quot; 
#line 290
__int64 rem; 
#line 291
} lldiv_t; 
#line 293
int __cdecl abs(int _Number); 
#line 294
long __cdecl labs(long _Number); 
#line 295
__int64 __cdecl llabs(__int64 _Number); 
#line 296
__int64 __cdecl _abs64(__int64 _Number); 
#line 298
unsigned short __cdecl _byteswap_ushort(unsigned short _Number); 
#line 299
unsigned long __cdecl _byteswap_ulong(unsigned long _Number); 
#line 300
unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Number); 
#line 302
div_t __cdecl div(int _Numerator, int _Denominator); 
#line 303
ldiv_t __cdecl ldiv(long _Numerator, long _Denominator); 
#line 304
lldiv_t __cdecl lldiv(__int64 _Numerator, __int64 _Denominator); 
#line 308
#pragma warning(push)
#pragma warning(disable: 6540)
#line 311
unsigned __cdecl _rotl(unsigned _Value, int _Shift); 
#line 317
unsigned long __cdecl _lrotl(unsigned long _Value, int _Shift); 
#line 322
unsigned __int64 __cdecl _rotl64(unsigned __int64 _Value, int _Shift); 
#line 327
unsigned __cdecl _rotr(unsigned _Value, int _Shift); 
#line 333
unsigned long __cdecl _lrotr(unsigned long _Value, int _Shift); 
#line 338
unsigned __int64 __cdecl _rotr64(unsigned __int64 _Value, int _Shift); 
#line 343
#pragma warning(pop)
#line 350
void __cdecl srand(unsigned _Seed); 
#line 352
int __cdecl rand(); 
#line 361 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
extern "C++" {
#line 363
inline long abs(const long _X) throw() 
#line 364
{ 
#line 365
return labs(_X); 
#line 366
} 
#line 368
inline __int64 abs(const __int64 _X) throw() 
#line 369
{ 
#line 370
return llabs(_X); 
#line 371
} 
#line 373
inline ldiv_t div(const long _A1, const long _A2) throw() 
#line 374
{ 
#line 375
return ldiv(_A1, _A2); 
#line 376
} 
#line 378
inline lldiv_t div(const __int64 _A1, const __int64 _A2) throw() 
#line 379
{ 
#line 380
return lldiv(_A1, _A2); 
#line 381
} 
#line 382
}
#line 394 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
#pragma pack ( push, 4 )
#line 398
typedef 
#line 396
struct { 
#line 397
unsigned char ld[10]; 
#line 398
} _LDOUBLE; 
#pragma pack ( pop )
#line 418 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
typedef 
#line 416
struct { 
#line 417
double x; 
#line 418
} _CRT_DOUBLE; 
#line 423
typedef 
#line 421
struct { 
#line 422
float f; 
#line 423
} _CRT_FLOAT; 
#line 432
typedef 
#line 430
struct { 
#line 431
long double x; 
#line 432
} _LONGDOUBLE; 
#line 436
#pragma pack ( push, 4 )
#line 440
typedef 
#line 438
struct { 
#line 439
unsigned char ld12[12]; 
#line 440
} _LDBL12; 
#pragma pack ( pop )
#line 450
double __cdecl atof(const char * _String); 
#line 451
int __cdecl atoi(const char * _String); 
#line 452
long __cdecl atol(const char * _String); 
#line 453
__int64 __cdecl atoll(const char * _String); 
#line 454
__int64 __cdecl _atoi64(const char * _String); 
#line 456
double __cdecl _atof_l(const char * _String, _locale_t _Locale); 
#line 457
int __cdecl _atoi_l(const char * _String, _locale_t _Locale); 
#line 458
long __cdecl _atol_l(const char * _String, _locale_t _Locale); 
#line 459
__int64 __cdecl _atoll_l(const char * _String, _locale_t _Locale); 
#line 460
__int64 __cdecl _atoi64_l(const char * _String, _locale_t _Locale); 
#line 462
int __cdecl _atoflt(_CRT_FLOAT * _Result, const char * _String); 
#line 463
int __cdecl _atodbl(_CRT_DOUBLE * _Result, char * _String); 
#line 464
int __cdecl _atoldbl(_LDOUBLE * _Result, char * _String); 
#line 467
int __cdecl _atoflt_l(_CRT_FLOAT * _Result, const char * _String, _locale_t _Locale); 
#line 474
int __cdecl _atodbl_l(_CRT_DOUBLE * _Result, char * _String, _locale_t _Locale); 
#line 482
int __cdecl _atoldbl_l(_LDOUBLE * _Result, char * _String, _locale_t _Locale); 
#line 489
float __cdecl strtof(const char * _String, char ** _EndPtr); 
#line 495
float __cdecl _strtof_l(const char * _String, char ** _EndPtr, _locale_t _Locale); 
#line 502
double __cdecl strtod(const char * _String, char ** _EndPtr); 
#line 508
double __cdecl _strtod_l(const char * _String, char ** _EndPtr, _locale_t _Locale); 
#line 515
long double __cdecl strtold(const char * _String, char ** _EndPtr); 
#line 521
long double __cdecl _strtold_l(const char * _String, char ** _EndPtr, _locale_t _Locale); 
#line 528
long __cdecl strtol(const char * _String, char ** _EndPtr, int _Radix); 
#line 535
long __cdecl _strtol_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 543
__int64 __cdecl strtoll(const char * _String, char ** _EndPtr, int _Radix); 
#line 550
__int64 __cdecl _strtoll_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 558
unsigned long __cdecl strtoul(const char * _String, char ** _EndPtr, int _Radix); 
#line 565
unsigned long __cdecl _strtoul_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 573
unsigned __int64 __cdecl strtoull(const char * _String, char ** _EndPtr, int _Radix); 
#line 580
unsigned __int64 __cdecl _strtoull_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 588
__int64 __cdecl _strtoi64(const char * _String, char ** _EndPtr, int _Radix); 
#line 595
__int64 __cdecl _strtoi64_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 603
unsigned __int64 __cdecl _strtoui64(const char * _String, char ** _EndPtr, int _Radix); 
#line 610
unsigned __int64 __cdecl _strtoui64_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 626
errno_t __cdecl _itoa_s(int _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 633
extern "C++" {template < size_t _Size > inline errno_t __cdecl _itoa_s ( int _Value, char ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _itoa_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 641 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char *__cdecl _itoa(int _Value, char * _Buffer, int _Radix); 
#line 650 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _ltoa_s(long _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 657
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ltoa_s ( long _Value, char ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ltoa_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 664 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char *__cdecl _ltoa(long _Value, char * _Buffer, int _Radix); 
#line 673 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _ultoa_s(unsigned long _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 680
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ultoa_s ( unsigned long _Value, char ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ultoa_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 687 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char *__cdecl _ultoa(unsigned long _Value, char * _Buffer, int _Radix); 
#line 696 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _i64toa_s(__int64 _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 705
char *__cdecl _i64toa(__int64 _Value, char * _Buffer, int _Radix); 
#line 713
errno_t __cdecl _ui64toa_s(unsigned __int64 _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 721
char *__cdecl _ui64toa(unsigned __int64 _Value, char * _Buffer, int _Radix); 
#line 741
errno_t __cdecl _ecvt_s(char * _Buffer, size_t _BufferCount, double _Value, int _DigitCount, int * _PtDec, int * _PtSign); 
#line 750
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ecvt_s ( char ( & _Buffer ) [ _Size ], double _Value, int _DigitCount, int * _PtDec, int * _PtSign ) throw ( ) { return _ecvt_s ( _Buffer, _Size, _Value, _DigitCount, _PtDec, _PtSign ); }}
#line 760 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char *__cdecl _ecvt(double _Value, int _DigitCount, int * _PtDec, int * _PtSign); 
#line 769
errno_t __cdecl _fcvt_s(char * _Buffer, size_t _BufferCount, double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign); 
#line 778
extern "C++" {template < size_t _Size > inline errno_t __cdecl _fcvt_s ( char ( & _Buffer ) [ _Size ], double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign ) throw ( ) { return _fcvt_s ( _Buffer, _Size, _Value, _FractionalDigitCount, _PtDec, _PtSign ); }}
#line 790 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char *__cdecl _fcvt(double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign); 
#line 798
errno_t __cdecl _gcvt_s(char * _Buffer, size_t _BufferCount, double _Value, int _DigitCount); 
#line 805
extern "C++" {template < size_t _Size > inline errno_t __cdecl _gcvt_s ( char ( & _Buffer ) [ _Size ], double _Value, int _DigitCount ) throw ( ) { return _gcvt_s ( _Buffer, _Size, _Value, _DigitCount ); }}
#line 814 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char *__cdecl _gcvt(double _Value, int _DigitCount, char * _Buffer); 
#line 852
int __cdecl mblen(const char * _Ch, size_t _MaxCount); 
#line 858
int __cdecl _mblen_l(const char * _Ch, size_t _MaxCount, _locale_t _Locale); 
#line 866
size_t __cdecl _mbstrlen(const char * _String); 
#line 872
size_t __cdecl _mbstrlen_l(const char * _String, _locale_t _Locale); 
#line 879
size_t __cdecl _mbstrnlen(const char * _String, size_t _MaxCount); 
#line 886
size_t __cdecl _mbstrnlen_l(const char * _String, size_t _MaxCount, _locale_t _Locale); 
#line 893
int __cdecl mbtowc(__wchar_t * _DstCh, const char * _SrcCh, size_t _SrcSizeInBytes); 
#line 900
int __cdecl _mbtowc_l(__wchar_t * _DstCh, const char * _SrcCh, size_t _SrcSizeInBytes, _locale_t _Locale); 
#line 908
errno_t __cdecl mbstowcs_s(size_t * _PtNumOfCharConverted, __wchar_t * _DstBuf, size_t _SizeInWords, const char * _SrcBuf, size_t _MaxCount); 
#line 916
extern "C++" {template < size_t _Size > inline errno_t __cdecl mbstowcs_s ( size_t * _PtNumOfCharConverted, wchar_t ( & _Dest ) [ _Size ], char const * _Source, size_t _MaxCount ) throw ( ) { return mbstowcs_s ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount ); }}
#line 924 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
size_t __cdecl mbstowcs(__wchar_t * _Dest, const char * _Source, size_t _MaxCount); 
#line 932 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _mbstowcs_s_l(size_t * _PtNumOfCharConverted, __wchar_t * _DstBuf, size_t _SizeInWords, const char * _SrcBuf, size_t _MaxCount, _locale_t _Locale); 
#line 941
extern "C++" {template < size_t _Size > inline errno_t __cdecl _mbstowcs_s_l ( size_t * _PtNumOfCharConverted, wchar_t ( & _Dest ) [ _Size ], char const * _Source, size_t _MaxCount, _locale_t _Locale ) throw ( ) { return _mbstowcs_s_l ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale ); }}
#line 950 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
size_t __cdecl _mbstowcs_l(__wchar_t * _Dest, const char * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 963 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
int __cdecl wctomb(char * _MbCh, __wchar_t _WCh); 
#line 969
int __cdecl _wctomb_l(char * _MbCh, __wchar_t _WCh, _locale_t _Locale); 
#line 978
errno_t __cdecl wctomb_s(int * _SizeConverted, char * _MbCh, rsize_t _SizeInBytes, __wchar_t _WCh); 
#line 988 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _wctomb_s_l(int * _SizeConverted, char * _MbCh, size_t _SizeInBytes, __wchar_t _WCh, _locale_t _Locale); 
#line 996
errno_t __cdecl wcstombs_s(size_t * _PtNumOfCharConverted, char * _Dst, size_t _DstSizeInBytes, const __wchar_t * _Src, size_t _MaxCountInBytes); 
#line 1004
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcstombs_s ( size_t * _PtNumOfCharConverted, char ( & _Dest ) [ _Size ], wchar_t const * _Source, size_t _MaxCount ) throw ( ) { return wcstombs_s ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount ); }}
#line 1012 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
size_t __cdecl wcstombs(char * _Dest, const __wchar_t * _Source, size_t _MaxCount); 
#line 1020 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _wcstombs_s_l(size_t * _PtNumOfCharConverted, char * _Dst, size_t _DstSizeInBytes, const __wchar_t * _Src, size_t _MaxCountInBytes, _locale_t _Locale); 
#line 1029
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcstombs_s_l ( size_t * _PtNumOfCharConverted, char ( & _Dest ) [ _Size ], wchar_t const * _Source, size_t _MaxCount, _locale_t _Locale ) throw ( ) { return _wcstombs_s_l ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale ); }}
#line 1038 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
size_t __cdecl _wcstombs_l(char * _Dest, const __wchar_t * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 1068 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
__declspec(allocator) char *__cdecl _fullpath(char * _Buffer, const char * _Path, size_t _BufferCount); 
#line 1077
errno_t __cdecl _makepath_s(char * _Buffer, size_t _BufferCount, const char * _Drive, const char * _Dir, const char * _Filename, const char * _Ext); 
#line 1086
extern "C++" {template < size_t _Size > inline errno_t __cdecl _makepath_s ( char ( & _Buffer ) [ _Size ], char const * _Drive, char const * _Dir, char const * _Filename, char const * _Ext ) throw ( ) { return _makepath_s ( _Buffer, _Size, _Drive, _Dir, _Filename, _Ext ); }}
#line 1095 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
void __cdecl _makepath(char * _Buffer, const char * _Drive, const char * _Dir, const char * _Filename, const char * _Ext); 
#line 1105 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
void __cdecl _splitpath(const char * _FullPath, char * _Drive, char * _Dir, char * _Filename, char * _Ext); 
#line 1114
errno_t __cdecl _splitpath_s(const char * _FullPath, char * _Drive, size_t _DriveCount, char * _Dir, size_t _DirCount, char * _Filename, size_t _FilenameCount, char * _Ext, size_t _ExtCount); 
#line 1126
extern "C++" {template < size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize > inline errno_t __cdecl _splitpath_s ( char const * _Dest, char ( & _Drive ) [ _DriveSize ], char ( & _Dir ) [ _DirSize ], char ( & _Name ) [ _NameSize ], char ( & _Ext ) [ _ExtSize ] ) throw ( ) { return _splitpath_s ( _Dest, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize ); }}
#line 1132
errno_t __cdecl getenv_s(size_t * _RequiredCount, char * _Buffer, rsize_t _BufferCount, const char * _VarName); 
#line 1144 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
int *__cdecl __p___argc(); 
#line 1145
char ***__cdecl __p___argv(); 
#line 1146
__wchar_t ***__cdecl __p___wargv(); 
#line 1158 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char ***__cdecl __p__environ(); 
#line 1159
__wchar_t ***__cdecl __p__wenviron(); 
#line 1184 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
char *__cdecl getenv(const char * _VarName); 
#line 1188
extern "C++" {template < size_t _Size > inline errno_t __cdecl getenv_s ( size_t * _RequiredCount, char ( & _Buffer ) [ _Size ], char const * _VarName ) throw ( ) { return getenv_s ( _RequiredCount, _Buffer, _Size, _VarName ); }}
#line 1201 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
errno_t __cdecl _dupenv_s(char ** _Buffer, size_t * _BufferCount, const char * _VarName); 
#line 1211 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
int __cdecl system(const char * _Command); 
#line 1217
#pragma warning(push)
#pragma warning(disable: 6540)
#line 1221
int __cdecl _putenv(const char * _EnvString); 
#line 1226
errno_t __cdecl _putenv_s(const char * _Name, const char * _Value); 
#line 1231
#pragma warning(pop)
#line 1233
errno_t __cdecl _searchenv_s(const char * _Filename, const char * _VarName, char * _Buffer, size_t _BufferCount); 
#line 1240
extern "C++" {template < size_t _Size > inline errno_t __cdecl _searchenv_s ( char const * _Filename, char const * _VarName, char ( & _Buffer ) [ _Size ] ) throw ( ) { return _searchenv_s ( _Filename, _VarName, _Buffer, _Size ); }}
#line 1247 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
void __cdecl _searchenv(const char * _Filename, const char * _VarName, char * _Buffer); 
#line 1255 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetErrorMode in" "stead. See online help for details.")) void __cdecl 
#line 1256
_seterrormode(int _Mode); 
#line 1260
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Beep instead. S" "ee online help for details.")) void __cdecl 
#line 1261
_beep(unsigned _Frequency, unsigned _Duration); 
#line 1266
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Sleep instead. " "See online help for details.")) void __cdecl 
#line 1267
_sleep(unsigned long _Duration); 
#line 1289 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
#pragma warning(push)
#pragma warning(disable: 4141)
#line 1293
char *__cdecl ecvt(double _Value, int _DigitCount, int * _PtDec, int * _PtSign); 
#line 1301
char *__cdecl fcvt(double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign); 
#line 1309
char *__cdecl gcvt(double _Value, int _DigitCount, char * _DstBuf); 
#line 1316
char *__cdecl itoa(int _Value, char * _Buffer, int _Radix); 
#line 1323
char *__cdecl ltoa(long _Value, char * _Buffer, int _Radix); 
#line 1331
void __cdecl swab(char * _Buf1, char * _Buf2, int _SizeInBytes); 
#line 1338
char *__cdecl ultoa(unsigned long _Value, char * _Buffer, int _Radix); 
#line 1347
int __cdecl putenv(const char * _EnvString); 
#line 1351
#pragma warning(pop)
#line 1353
_onexit_t __cdecl onexit(_onexit_t _Func); 
#line 1359 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\stdlib.h"
}__pragma( pack ( pop )) 
#line 1361
#pragma warning(pop)
#line 184 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
extern "C" {
#line 191
extern cudaError_t __stdcall __cudaDeviceSynchronizeDeprecationAvoidance(); 
#line 244
extern cudaError_t __stdcall __cudaCDP2DeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
#line 245
extern cudaError_t __stdcall __cudaCDP2DeviceGetLimit(size_t * pValue, cudaLimit limit); 
#line 246
extern cudaError_t __stdcall __cudaCDP2DeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
#line 247
extern cudaError_t __stdcall __cudaCDP2DeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
#line 248
extern cudaError_t __stdcall __cudaCDP2GetLastError(); 
#line 249
extern cudaError_t __stdcall __cudaCDP2PeekAtLastError(); 
#line 250
extern const char *__stdcall __cudaCDP2GetErrorString(cudaError_t error); 
#line 251
extern const char *__stdcall __cudaCDP2GetErrorName(cudaError_t error); 
#line 252
extern cudaError_t __stdcall __cudaCDP2GetDeviceCount(int * count); 
#line 253
extern cudaError_t __stdcall __cudaCDP2GetDevice(int * device); 
#line 254
extern cudaError_t __stdcall __cudaCDP2StreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
#line 255
extern cudaError_t __stdcall __cudaCDP2StreamDestroy(cudaStream_t stream); 
#line 256
extern cudaError_t __stdcall __cudaCDP2StreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
#line 257
extern cudaError_t __stdcall __cudaCDP2StreamWaitEvent_ptsz(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
#line 258
extern cudaError_t __stdcall __cudaCDP2EventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
#line 259
extern cudaError_t __stdcall __cudaCDP2EventRecord(cudaEvent_t event, cudaStream_t stream); 
#line 260
extern cudaError_t __stdcall __cudaCDP2EventRecord_ptsz(cudaEvent_t event, cudaStream_t stream); 
#line 261
extern cudaError_t __stdcall __cudaCDP2EventRecordWithFlags(cudaEvent_t event, cudaStream_t stream, unsigned flags); 
#line 262
extern cudaError_t __stdcall __cudaCDP2EventRecordWithFlags_ptsz(cudaEvent_t event, cudaStream_t stream, unsigned flags); 
#line 263
extern cudaError_t __stdcall __cudaCDP2EventDestroy(cudaEvent_t event); 
#line 264
extern cudaError_t __stdcall __cudaCDP2FuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
#line 265
extern cudaError_t __stdcall __cudaCDP2Free(void * devPtr); 
#line 266
extern cudaError_t __stdcall __cudaCDP2Malloc(void ** devPtr, size_t size); 
#line 267
extern cudaError_t __stdcall __cudaCDP2MemcpyAsync(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
#line 268
extern cudaError_t __stdcall __cudaCDP2MemcpyAsync_ptsz(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
#line 269
extern cudaError_t __stdcall __cudaCDP2Memcpy2DAsync(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
#line 270
extern cudaError_t __stdcall __cudaCDP2Memcpy2DAsync_ptsz(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
#line 271
extern cudaError_t __stdcall __cudaCDP2Memcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream); 
#line 272
extern cudaError_t __stdcall __cudaCDP2Memcpy3DAsync_ptsz(const cudaMemcpy3DParms * p, cudaStream_t stream); 
#line 273
extern cudaError_t __stdcall __cudaCDP2MemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream); 
#line 274
extern cudaError_t __stdcall __cudaCDP2MemsetAsync_ptsz(void * devPtr, int value, size_t count, cudaStream_t stream); 
#line 275
extern cudaError_t __stdcall __cudaCDP2Memset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream); 
#line 276
extern cudaError_t __stdcall __cudaCDP2Memset2DAsync_ptsz(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream); 
#line 277
extern cudaError_t __stdcall __cudaCDP2Memset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
#line 278
extern cudaError_t __stdcall __cudaCDP2Memset3DAsync_ptsz(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
#line 279
extern cudaError_t __stdcall __cudaCDP2RuntimeGetVersion(int * runtimeVersion); 
#line 280
extern void *__stdcall __cudaCDP2GetParameterBuffer(size_t alignment, size_t size); 
#line 281
extern void *__stdcall __cudaCDP2GetParameterBufferV2(void * func, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize); 
#line 282
extern cudaError_t __stdcall __cudaCDP2LaunchDevice_ptsz(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
#line 283
extern cudaError_t __stdcall __cudaCDP2LaunchDeviceV2_ptsz(void * parameterBuffer, cudaStream_t stream); 
#line 284
extern cudaError_t __stdcall __cudaCDP2LaunchDevice(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
#line 285
extern cudaError_t __stdcall __cudaCDP2LaunchDeviceV2(void * parameterBuffer, cudaStream_t stream); 
#line 286
extern cudaError_t __stdcall __cudaCDP2OccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, size_t dynamicSmemSize); 
#line 287
extern cudaError_t __stdcall __cudaCDP2OccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, size_t dynamicSmemSize, unsigned flags); 
#line 290
extern cudaError_t __stdcall cudaGraphLaunch(cudaGraphExec_t graphExec, cudaStream_t stream); 
#line 311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
static inline cudaGraphExec_t __stdcall cudaGetCurrentGraphExec() {int volatile ___ = 1;::exit(___);}
#if 0
#line 312
{ 
#line 313
unsigned __int64 current_graph_exec; 
#line 314
__asm mov.u64 %0, %%current_graph_exec;
return (cudaGraphExec_t)current_graph_exec; 
#line 316
} 
#endif
#line 346 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
extern cudaError_t __stdcall cudaGraphKernelNodeSetParam(cudaGraphDeviceNode_t node, size_t offset, const void * value, size_t size); 
#line 374
extern cudaError_t __stdcall cudaGraphKernelNodeSetEnabled(cudaGraphDeviceNode_t node, bool enable); 
#line 401
extern cudaError_t __stdcall cudaGraphKernelNodeSetGridDim(cudaGraphDeviceNode_t node, dim3 gridDim); 
#line 430
extern cudaError_t __stdcall cudaGraphKernelNodeUpdatesApply(const cudaGraphKernelNodeUpdate * updates, size_t updateCount); 
#line 448
static inline void __stdcall cudaTriggerProgrammaticLaunchCompletion() {int volatile ___ = 1;::exit(___);}
#if 0
#line 449
{ 
#line 450
__asm griddepcontrol.launch_dependents;
} 
#endif
#line 464 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
static inline void __stdcall cudaGridDependencySynchronize() {int volatile ___ = 1;::exit(___);}
#if 0
#line 465
{ 
#line 466
__asm griddepcontrol.wait;
} 
#endif
#line 480 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
extern void __stdcall cudaGraphSetConditional(cudaGraphConditionalHandle handle, unsigned value); 
#line 483
extern unsigned __int64 __stdcall cudaCGGetIntrinsicHandle(cudaCGScope scope); 
#line 484
extern cudaError_t __stdcall cudaCGSynchronize(unsigned __int64 handle, unsigned flags); 
#line 485
extern cudaError_t __stdcall cudaCGSynchronizeGrid(unsigned __int64 handle, unsigned flags); 
#line 486
extern cudaError_t __stdcall cudaCGGetSize(unsigned * numThreads, unsigned * numGrids, unsigned __int64 handle); 
#line 487
extern cudaError_t __stdcall cudaCGGetRank(unsigned * threadRank, unsigned * gridRank, unsigned __int64 handle); 
#line 715
static __inline void *__stdcall cudaGetParameterBuffer(size_t alignment, size_t size) {int volatile ___ = 1;(void)alignment;(void)size;::exit(___);}
#if 0
#line 716
{ 
#line 717
return __cudaCDP2GetParameterBuffer(alignment, size); 
#line 718
} 
#endif
#line 725 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
static __inline void *__stdcall cudaGetParameterBufferV2(void *func, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize) {int volatile ___ = 1;(void)func;(void)gridDimension;(void)blockDimension;(void)sharedMemSize;::exit(___);}
#if 0
#line 726
{ 
#line 727
return __cudaCDP2GetParameterBufferV2(func, gridDimension, blockDimension, sharedMemSize); 
#line 728
} 
#endif
#line 735 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDevice_ptsz(void *func, void *parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream) {int volatile ___ = 1;(void)func;(void)parameterBuffer;(void)gridDimension;(void)blockDimension;(void)sharedMemSize;(void)stream;::exit(___);}
#if 0
#line 736
{ 
#line 737
return __cudaCDP2LaunchDevice_ptsz(func, parameterBuffer, gridDimension, blockDimension, sharedMemSize, stream); 
#line 738
} 
#endif
#line 740 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDeviceV2_ptsz(void *parameterBuffer, cudaStream_t stream) {int volatile ___ = 1;(void)parameterBuffer;(void)stream;::exit(___);}
#if 0
#line 741
{ 
#line 742
return __cudaCDP2LaunchDeviceV2_ptsz(parameterBuffer, stream); 
#line 743
} 
#endif
#line 801 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDevice(void *func, void *parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream) {int volatile ___ = 1;(void)func;(void)parameterBuffer;(void)gridDimension;(void)blockDimension;(void)sharedMemSize;(void)stream;::exit(___);}
#if 0
#line 802
{ 
#line 803
return __cudaCDP2LaunchDevice(func, parameterBuffer, gridDimension, blockDimension, sharedMemSize, stream); 
#line 804
} 
#endif
#line 806 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDeviceV2(void *parameterBuffer, cudaStream_t stream) {int volatile ___ = 1;(void)parameterBuffer;(void)stream;::exit(___);}
#if 0
#line 807
{ 
#line 808
return __cudaCDP2LaunchDeviceV2(parameterBuffer, stream); 
#line 809
} 
#endif
#line 863 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_device_runtime_api.h"
}
#line 869
template< class T> static __inline cudaError_t cudaMalloc(T ** devPtr, size_t size); 
#line 870
template< class T> static __inline cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, T * entry); 
#line 871
template< class T> static __inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, T func, int blockSize, size_t dynamicSmemSize); 
#line 872
template< class T> static __inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, T func, int blockSize, size_t dynamicSmemSize, unsigned flags); 
#line 902
template< class T> static __inline ::cudaError_t __stdcall 
#line 903
cudaGraphKernelNodeSetParam(::cudaGraphDeviceNode_t node, ::size_t offset, const T &value) {int volatile ___ = 1;(void)node;(void)offset;(void)value;::exit(___);}
#if 0
#line 904
{ 
#line 905
return cudaGraphKernelNodeSetParam(node, offset, &value, sizeof(T)); 
#line 906
} 
#endif
#line 283 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern "C" {
#line 330 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceReset(); 
#line 352
extern cudaError_t __stdcall cudaDeviceSynchronize(); 
#line 438
extern cudaError_t __stdcall cudaDeviceSetLimit(cudaLimit limit, size_t value); 
#line 474
extern cudaError_t __stdcall cudaDeviceGetLimit(size_t * pValue, cudaLimit limit); 
#line 497
extern cudaError_t __stdcall cudaDeviceGetTexture1DLinearMaxWidth(size_t * maxWidthInElements, const cudaChannelFormatDesc * fmtDesc, int device); 
#line 531 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
#line 568
extern cudaError_t __stdcall cudaDeviceGetStreamPriorityRange(int * leastPriority, int * greatestPriority); 
#line 612
extern cudaError_t __stdcall cudaDeviceSetCacheConfig(cudaFuncCache cacheConfig); 
#line 639
extern cudaError_t __stdcall cudaDeviceGetByPCIBusId(int * device, const char * pciBusId); 
#line 669
extern cudaError_t __stdcall cudaDeviceGetPCIBusId(char * pciBusId, int len, int device); 
#line 720
extern cudaError_t __stdcall cudaIpcGetEventHandle(cudaIpcEventHandle_t * handle, cudaEvent_t event); 
#line 764
extern cudaError_t __stdcall cudaIpcOpenEventHandle(cudaEvent_t * event, cudaIpcEventHandle_t handle); 
#line 809
extern cudaError_t __stdcall cudaIpcGetMemHandle(cudaIpcMemHandle_t * handle, void * devPtr); 
#line 876
extern cudaError_t __stdcall cudaIpcOpenMemHandle(void ** devPtr, cudaIpcMemHandle_t handle, unsigned flags); 
#line 915
extern cudaError_t __stdcall cudaIpcCloseMemHandle(void * devPtr); 
#line 947
extern cudaError_t __stdcall cudaDeviceFlushGPUDirectRDMAWrites(cudaFlushGPUDirectRDMAWritesTarget target, cudaFlushGPUDirectRDMAWritesScope scope); 
#line 985 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceRegisterAsyncNotification(int device, cudaAsyncCallback callbackFunc, void * userData, cudaAsyncCallbackHandle_t * callback); 
#line 1008
extern cudaError_t __stdcall cudaDeviceUnregisterAsyncNotification(int device, cudaAsyncCallbackHandle_t callback); 
#line 1055
__declspec(deprecated) extern cudaError_t __stdcall cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
#line 1101
__declspec(deprecated) extern cudaError_t __stdcall cudaDeviceSetSharedMemConfig(cudaSharedMemConfig config); 
#line 1165
extern cudaError_t __stdcall cudaGetLastError(); 
#line 1216
extern cudaError_t __stdcall cudaPeekAtLastError(); 
#line 1232
extern const char *__stdcall cudaGetErrorName(cudaError_t error); 
#line 1248
extern const char *__stdcall cudaGetErrorString(cudaError_t error); 
#line 1277
extern cudaError_t __stdcall cudaGetDeviceCount(int * count); 
#line 1299
extern cudaError_t __stdcall cudaGetDeviceProperties(cudaDeviceProp * prop, int device); 
#line 1324
extern cudaError_t __stdcall cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
#line 1357
extern cudaError_t __stdcall cudaDeviceGetHostAtomicCapabilities(unsigned * capabilities, const cudaAtomicOperation * operations, unsigned count, int device); 
#line 1375
extern cudaError_t __stdcall cudaDeviceGetDefaultMemPool(cudaMemPool_t * memPool, int device); 
#line 1399
extern cudaError_t __stdcall cudaDeviceSetMemPool(int device, cudaMemPool_t memPool); 
#line 1419
extern cudaError_t __stdcall cudaDeviceGetMemPool(cudaMemPool_t * memPool, int device); 
#line 1481
extern cudaError_t __stdcall cudaDeviceGetNvSciSyncAttributes(void * nvSciSyncAttrList, int device, int flags); 
#line 1525
extern cudaError_t __stdcall cudaDeviceGetP2PAttribute(int * value, cudaDeviceP2PAttr attr, int srcDevice, int dstDevice); 
#line 1561
extern cudaError_t __stdcall cudaDeviceGetP2PAtomicCapabilities(unsigned * capabilities, const cudaAtomicOperation * operations, unsigned count, int srcDevice, int dstDevice); 
#line 1584
extern cudaError_t __stdcall cudaChooseDevice(int * device, const cudaDeviceProp * prop); 
#line 1613
extern cudaError_t __stdcall cudaInitDevice(int device, unsigned deviceFlags, unsigned flags); 
#line 1659
extern cudaError_t __stdcall cudaSetDevice(int device); 
#line 1681
extern cudaError_t __stdcall cudaGetDevice(int * device); 
#line 1712
extern cudaError_t __stdcall cudaSetValidDevices(int * device_arr, int len); 
#line 1782
extern cudaError_t __stdcall cudaSetDeviceFlags(unsigned flags); 
#line 1827
extern cudaError_t __stdcall cudaGetDeviceFlags(unsigned * flags); 
#line 1871
extern cudaError_t __stdcall cudaStreamCreate(cudaStream_t * pStream); 
#line 1907
extern cudaError_t __stdcall cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
#line 1959
extern cudaError_t __stdcall cudaStreamCreateWithPriority(cudaStream_t * pStream, unsigned flags, int priority); 
#line 1987
extern cudaError_t __stdcall cudaStreamGetPriority(cudaStream_t hStream, int * priority); 
#line 2013
extern cudaError_t __stdcall cudaStreamGetFlags(cudaStream_t hStream, unsigned * flags); 
#line 2050
extern cudaError_t __stdcall cudaStreamGetId(cudaStream_t hStream, unsigned __int64 * streamId); 
#line 2076
extern cudaError_t __stdcall cudaStreamGetDevice(cudaStream_t hStream, int * device); 
#line 2091
extern cudaError_t __stdcall cudaCtxResetPersistingL2Cache(); 
#line 2111
extern cudaError_t __stdcall cudaStreamCopyAttributes(cudaStream_t dst, cudaStream_t src); 
#line 2132
extern cudaError_t __stdcall cudaStreamGetAttribute(cudaStream_t hStream, cudaLaunchAttributeID attr, cudaLaunchAttributeValue * value_out); 
#line 2156
extern cudaError_t __stdcall cudaStreamSetAttribute(cudaStream_t hStream, cudaLaunchAttributeID attr, const cudaLaunchAttributeValue * value); 
#line 2190
extern cudaError_t __stdcall cudaStreamDestroy(cudaStream_t stream); 
#line 2221
extern cudaError_t __stdcall cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags = 0); 
#line 2229
typedef void (__stdcall *cudaStreamCallback_t)(cudaStream_t stream, cudaError_t status, void * userData); 
#line 2296
extern cudaError_t __stdcall cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback, void * userData, unsigned flags); 
#line 2320
extern cudaError_t __stdcall cudaStreamSynchronize(cudaStream_t stream); 
#line 2345
extern cudaError_t __stdcall cudaStreamQuery(cudaStream_t stream); 
#line 2429
extern cudaError_t __stdcall cudaStreamAttachMemAsync(cudaStream_t stream, void * devPtr, size_t length = 0, unsigned flags = 4); 
#line 2468 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaStreamBeginCapture(cudaStream_t stream, cudaStreamCaptureMode mode); 
#line 2509
extern cudaError_t __stdcall cudaStreamBeginCaptureToGraph(cudaStream_t stream, cudaGraph_t graph, const cudaGraphNode_t * dependencies, const cudaGraphEdgeData * dependencyData, size_t numDependencies, cudaStreamCaptureMode mode); 
#line 2560
extern cudaError_t __stdcall cudaThreadExchangeStreamCaptureMode(cudaStreamCaptureMode * mode); 
#line 2589
extern cudaError_t __stdcall cudaStreamEndCapture(cudaStream_t stream, cudaGraph_t * pGraph); 
#line 2627
extern cudaError_t __stdcall cudaStreamIsCapturing(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus); 
#line 2686
extern cudaError_t __stdcall cudaStreamGetCaptureInfo(cudaStream_t stream, cudaStreamCaptureStatus * captureStatus_out, unsigned __int64 * id_out = 0, cudaGraph_t * graph_out = 0, const cudaGraphNode_t ** dependencies_out = 0, const cudaGraphEdgeData ** edgeData_out = 0, size_t * numDependencies_out = 0); 
#line 2724
extern cudaError_t __stdcall cudaStreamUpdateCaptureDependencies(cudaStream_t stream, cudaGraphNode_t * dependencies, const cudaGraphEdgeData * dependencyData, size_t numDependencies, unsigned flags = 0); 
#line 2761
extern cudaError_t __stdcall cudaEventCreate(cudaEvent_t * event); 
#line 2798
extern cudaError_t __stdcall cudaEventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
#line 2839
extern cudaError_t __stdcall cudaEventRecord(cudaEvent_t event, cudaStream_t stream = 0); 
#line 2887
extern cudaError_t __stdcall cudaEventRecordWithFlags(cudaEvent_t event, cudaStream_t stream = 0, unsigned flags = 0); 
#line 2920 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaEventQuery(cudaEvent_t event); 
#line 2951
extern cudaError_t __stdcall cudaEventSynchronize(cudaEvent_t event); 
#line 2981
extern cudaError_t __stdcall cudaEventDestroy(cudaEvent_t event); 
#line 3029
extern cudaError_t __stdcall cudaEventElapsedTime(float * ms, cudaEvent_t start, cudaEvent_t end); 
#line 3210
extern cudaError_t __stdcall cudaImportExternalMemory(cudaExternalMemory_t * extMem_out, const cudaExternalMemoryHandleDesc * memHandleDesc); 
#line 3265
extern cudaError_t __stdcall cudaExternalMemoryGetMappedBuffer(void ** devPtr, cudaExternalMemory_t extMem, const cudaExternalMemoryBufferDesc * bufferDesc); 
#line 3325
extern cudaError_t __stdcall cudaExternalMemoryGetMappedMipmappedArray(cudaMipmappedArray_t * mipmap, cudaExternalMemory_t extMem, const cudaExternalMemoryMipmappedArrayDesc * mipmapDesc); 
#line 3349
extern cudaError_t __stdcall cudaDestroyExternalMemory(cudaExternalMemory_t extMem); 
#line 3503
extern cudaError_t __stdcall cudaImportExternalSemaphore(cudaExternalSemaphore_t * extSem_out, const cudaExternalSemaphoreHandleDesc * semHandleDesc); 
#line 3599
extern cudaError_t __stdcall cudaSignalExternalSemaphoresAsync(const cudaExternalSemaphore_t * extSemArray, const cudaExternalSemaphoreSignalParams * paramsArray, unsigned numExtSems, cudaStream_t stream = 0); 
#line 3675
extern cudaError_t __stdcall cudaWaitExternalSemaphoresAsync(const cudaExternalSemaphore_t * extSemArray, const cudaExternalSemaphoreWaitParams * paramsArray, unsigned numExtSems, cudaStream_t stream = 0); 
#line 3698
extern cudaError_t __stdcall cudaDestroyExternalSemaphore(cudaExternalSemaphore_t extSem); 
#line 3766
extern cudaError_t __stdcall cudaLaunchKernel(const void * func, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
#line 3829
extern cudaError_t __stdcall cudaLaunchKernelExC(const cudaLaunchConfig_t * config, const void * func, void ** args); 
#line 3886
extern cudaError_t __stdcall cudaLaunchCooperativeKernel(const void * func, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
#line 3936
extern cudaError_t __stdcall cudaFuncSetCacheConfig(const void * func, cudaFuncCache cacheConfig); 
#line 3971
extern cudaError_t __stdcall cudaFuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
#line 4030
extern cudaError_t __stdcall cudaFuncSetAttribute(const void * func, cudaFuncAttribute attr, int value); 
#line 4056
extern cudaError_t __stdcall cudaFuncGetName(const char ** name, const void * func); 
#line 4079
extern cudaError_t __stdcall cudaFuncGetParamInfo(const void * func, size_t paramIndex, size_t * paramOffset, size_t * paramSize); 
#line 4145
extern cudaError_t __stdcall cudaLaunchHostFunc(cudaStream_t stream, cudaHostFn_t fn, void * userData); 
#line 4219
__declspec(deprecated) extern cudaError_t __stdcall cudaFuncSetSharedMemConfig(const void * func, cudaSharedMemConfig config); 
#line 4276
extern cudaError_t __stdcall cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, size_t dynamicSMemSize); 
#line 4306
extern cudaError_t __stdcall cudaOccupancyAvailableDynamicSMemPerBlock(size_t * dynamicSmemSize, const void * func, int numBlocks, int blockSize); 
#line 4352
extern cudaError_t __stdcall cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, size_t dynamicSMemSize, unsigned flags); 
#line 4388
extern cudaError_t __stdcall cudaOccupancyMaxPotentialClusterSize(int * clusterSize, const void * func, const cudaLaunchConfig_t * launchConfig); 
#line 4428
extern cudaError_t __stdcall cudaOccupancyMaxActiveClusters(int * numClusters, const void * func, const cudaLaunchConfig_t * launchConfig); 
#line 4548
extern cudaError_t __stdcall cudaMallocManaged(void ** devPtr, size_t size, unsigned flags = 1); 
#line 4581 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaMalloc(void ** devPtr, size_t size); 
#line 4618
extern cudaError_t __stdcall cudaMallocHost(void ** ptr, size_t size); 
#line 4661
extern cudaError_t __stdcall cudaMallocPitch(void ** devPtr, size_t * pitch, size_t width, size_t height); 
#line 4713
extern cudaError_t __stdcall cudaMallocArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, size_t width, size_t height = 0, unsigned flags = 0); 
#line 4752
extern cudaError_t __stdcall cudaFree(void * devPtr); 
#line 4775
extern cudaError_t __stdcall cudaFreeHost(void * ptr); 
#line 4798
extern cudaError_t __stdcall cudaFreeArray(cudaArray_t array); 
#line 4821
extern cudaError_t __stdcall cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray); 
#line 4887
extern cudaError_t __stdcall cudaHostAlloc(void ** pHost, size_t size, unsigned flags); 
#line 4984
extern cudaError_t __stdcall cudaHostRegister(void * ptr, size_t size, unsigned flags); 
#line 5007
extern cudaError_t __stdcall cudaHostUnregister(void * ptr); 
#line 5052
extern cudaError_t __stdcall cudaHostGetDevicePointer(void ** pDevice, void * pHost, unsigned flags); 
#line 5074
extern cudaError_t __stdcall cudaHostGetFlags(unsigned * pFlags, void * pHost); 
#line 5113
extern cudaError_t __stdcall cudaMalloc3D(cudaPitchedPtr * pitchedDevPtr, cudaExtent extent); 
#line 5258
extern cudaError_t __stdcall cudaMalloc3DArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned flags = 0); 
#line 5403
extern cudaError_t __stdcall cudaMallocMipmappedArray(cudaMipmappedArray_t * mipmappedArray, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned numLevels, unsigned flags = 0); 
#line 5436
extern cudaError_t __stdcall cudaGetMipmappedArrayLevel(cudaArray_t * levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned level); 
#line 5541
extern cudaError_t __stdcall cudaMemcpy3D(const cudaMemcpy3DParms * p); 
#line 5573
extern cudaError_t __stdcall cudaMemcpy3DPeer(const cudaMemcpy3DPeerParms * p); 
#line 5691
extern cudaError_t __stdcall cudaMemcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream = 0); 
#line 5718
extern cudaError_t __stdcall cudaMemcpy3DPeerAsync(const cudaMemcpy3DPeerParms * p, cudaStream_t stream = 0); 
#line 5752
extern cudaError_t __stdcall cudaMemGetInfo(size_t * free, size_t * total); 
#line 5778
extern cudaError_t __stdcall cudaArrayGetInfo(cudaChannelFormatDesc * desc, cudaExtent * extent, unsigned * flags, cudaArray_t array); 
#line 5807
extern cudaError_t __stdcall cudaArrayGetPlane(cudaArray_t * pPlaneArray, cudaArray_t hArray, unsigned planeIdx); 
#line 5830
extern cudaError_t __stdcall cudaArrayGetMemoryRequirements(cudaArrayMemoryRequirements * memoryRequirements, cudaArray_t array, int device); 
#line 5854
extern cudaError_t __stdcall cudaMipmappedArrayGetMemoryRequirements(cudaArrayMemoryRequirements * memoryRequirements, cudaMipmappedArray_t mipmap, int device); 
#line 5882
extern cudaError_t __stdcall cudaArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaArray_t array); 
#line 5912 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaMipmappedArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaMipmappedArray_t mipmap); 
#line 5957 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaMemcpy(void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 5992
extern cudaError_t __stdcall cudaMemcpyPeer(void * dst, int dstDevice, const void * src, int srcDevice, size_t count); 
#line 6041
extern cudaError_t __stdcall cudaMemcpy2D(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind); 
#line 6091
extern cudaError_t __stdcall cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind); 
#line 6141
extern cudaError_t __stdcall cudaMemcpy2DFromArray(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind); 
#line 6188
extern cudaError_t __stdcall cudaMemcpy2DArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
#line 6231
extern cudaError_t __stdcall cudaMemcpyToSymbol(const void * symbol, const void * src, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyHostToDevice); 
#line 6275
extern cudaError_t __stdcall cudaMemcpyFromSymbol(void * dst, const void * symbol, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyDeviceToHost); 
#line 6332
extern cudaError_t __stdcall cudaMemcpyAsync(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6367
extern cudaError_t __stdcall cudaMemcpyPeerAsync(void * dst, int dstDevice, const void * src, int srcDevice, size_t count, cudaStream_t stream = 0); 
#line 6435
extern cudaError_t __stdcall cudaMemcpyBatchAsync(void *const * dsts, const void *const * srcs, const size_t * sizes, size_t count, cudaMemcpyAttributes * attrs, size_t * attrsIdxs, size_t numAttrs, cudaStream_t stream); 
#line 6499
extern cudaError_t __stdcall cudaMemcpy3DBatchAsync(size_t numOps, cudaMemcpy3DBatchOp * opList, unsigned __int64 flags, cudaStream_t stream); 
#line 6561
extern cudaError_t __stdcall cudaMemcpy2DAsync(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6619
extern cudaError_t __stdcall cudaMemcpy2DToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6676
extern cudaError_t __stdcall cudaMemcpy2DFromArrayAsync(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6727
extern cudaError_t __stdcall cudaMemcpyToSymbolAsync(const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6778
extern cudaError_t __stdcall cudaMemcpyFromSymbolAsync(void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6807
extern cudaError_t __stdcall cudaMemset(void * devPtr, int value, size_t count); 
#line 6841
extern cudaError_t __stdcall cudaMemset2D(void * devPtr, size_t pitch, int value, size_t width, size_t height); 
#line 6887
extern cudaError_t __stdcall cudaMemset3D(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent); 
#line 6923
extern cudaError_t __stdcall cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream = 0); 
#line 6964
extern cudaError_t __stdcall cudaMemset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream = 0); 
#line 7017
extern cudaError_t __stdcall cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream = 0); 
#line 7045
extern cudaError_t __stdcall cudaGetSymbolAddress(void ** devPtr, const void * symbol); 
#line 7072
extern cudaError_t __stdcall cudaGetSymbolSize(size_t * size, const void * symbol); 
#line 7152
extern cudaError_t __stdcall cudaMemPrefetchAsync(const void * devPtr, size_t count, cudaMemLocation location, unsigned flags, cudaStream_t stream = 0); 
#line 7193
extern cudaError_t __stdcall cudaMemPrefetchBatchAsync(void ** dptrs, size_t * sizes, size_t count, cudaMemLocation * prefetchLocs, size_t * prefetchLocIdxs, size_t numPrefetchLocs, unsigned __int64 flags, cudaStream_t stream); 
#line 7226
extern cudaError_t __stdcall cudaMemDiscardBatchAsync(void ** dptrs, size_t * sizes, size_t count, unsigned __int64 flags, cudaStream_t stream); 
#line 7274
extern cudaError_t __stdcall cudaMemDiscardAndPrefetchBatchAsync(void ** dptrs, size_t * sizes, size_t count, cudaMemLocation * prefetchLocs, size_t * prefetchLocIdxs, size_t numPrefetchLocs, unsigned __int64 flags, cudaStream_t stream); 
#line 7399
extern cudaError_t __stdcall cudaMemAdvise(const void * devPtr, size_t count, cudaMemoryAdvise advice, cudaMemLocation location); 
#line 7481
extern cudaError_t __stdcall cudaMemRangeGetAttribute(void * data, size_t dataSize, cudaMemRangeAttribute attribute, const void * devPtr, size_t count); 
#line 7524
extern cudaError_t __stdcall cudaMemRangeGetAttributes(void ** data, size_t * dataSizes, cudaMemRangeAttribute * attributes, size_t numAttributes, const void * devPtr, size_t count); 
#line 7584
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t count, cudaMemcpyKind kind); 
#line 7626
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyFromArray(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind); 
#line 7669
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
#line 7720
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 7770
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyFromArrayAsync(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 7839
extern cudaError_t __stdcall cudaMallocAsync(void ** devPtr, size_t size, cudaStream_t hStream); 
#line 7865
extern cudaError_t __stdcall cudaFreeAsync(void * devPtr, cudaStream_t hStream); 
#line 7890
extern cudaError_t __stdcall cudaMemPoolTrimTo(cudaMemPool_t memPool, size_t minBytesToKeep); 
#line 7934
extern cudaError_t __stdcall cudaMemPoolSetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value); 
#line 7982
extern cudaError_t __stdcall cudaMemPoolGetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value); 
#line 7997
extern cudaError_t __stdcall cudaMemPoolSetAccess(cudaMemPool_t memPool, const cudaMemAccessDesc * descList, size_t count); 
#line 8010
extern cudaError_t __stdcall cudaMemPoolGetAccess(cudaMemAccessFlags * flags, cudaMemPool_t memPool, cudaMemLocation * location); 
#line 8061
extern cudaError_t __stdcall cudaMemPoolCreate(cudaMemPool_t * memPool, const cudaMemPoolProps * poolProps); 
#line 8083
extern cudaError_t __stdcall cudaMemPoolDestroy(cudaMemPool_t memPool); 
#line 8102
extern cudaError_t __stdcall cudaMemGetDefaultMemPool(cudaMemPool_t * memPool, cudaMemLocation * location, cudaMemAllocationType type); 
#line 8125
extern cudaError_t __stdcall cudaMemGetMemPool(cudaMemPool_t * memPool, cudaMemLocation * location, cudaMemAllocationType type); 
#line 8153
extern cudaError_t __stdcall cudaMemSetMemPool(cudaMemLocation * location, cudaMemAllocationType type, cudaMemPool_t memPool); 
#line 8189
extern cudaError_t __stdcall cudaMallocFromPoolAsync(void ** ptr, size_t size, cudaMemPool_t memPool, cudaStream_t stream); 
#line 8214
extern cudaError_t __stdcall cudaMemPoolExportToShareableHandle(void * shareableHandle, cudaMemPool_t memPool, cudaMemAllocationHandleType handleType, unsigned flags); 
#line 8241
extern cudaError_t __stdcall cudaMemPoolImportFromShareableHandle(cudaMemPool_t * memPool, void * shareableHandle, cudaMemAllocationHandleType handleType, unsigned flags); 
#line 8264
extern cudaError_t __stdcall cudaMemPoolExportPointer(cudaMemPoolPtrExportData * exportData, void * ptr); 
#line 8293
extern cudaError_t __stdcall cudaMemPoolImportPointer(void ** ptr, cudaMemPool_t memPool, cudaMemPoolPtrExportData * exportData); 
#line 8446
extern cudaError_t __stdcall cudaPointerGetAttributes(cudaPointerAttributes * attributes, const void * ptr); 
#line 8487
extern cudaError_t __stdcall cudaDeviceCanAccessPeer(int * canAccessPeer, int device, int peerDevice); 
#line 8529
extern cudaError_t __stdcall cudaDeviceEnablePeerAccess(int peerDevice, unsigned flags); 
#line 8551
extern cudaError_t __stdcall cudaDeviceDisablePeerAccess(int peerDevice); 
#line 8615
extern cudaError_t __stdcall cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource); 
#line 8650
extern cudaError_t __stdcall cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t resource, unsigned flags); 
#line 8689
extern cudaError_t __stdcall cudaGraphicsMapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
#line 8724
extern cudaError_t __stdcall cudaGraphicsUnmapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
#line 8756
extern cudaError_t __stdcall cudaGraphicsResourceGetMappedPointer(void ** devPtr, size_t * size, cudaGraphicsResource_t resource); 
#line 8794
extern cudaError_t __stdcall cudaGraphicsSubResourceGetMappedArray(cudaArray_t * array, cudaGraphicsResource_t resource, unsigned arrayIndex, unsigned mipLevel); 
#line 8823
extern cudaError_t __stdcall cudaGraphicsResourceGetMappedMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaGraphicsResource_t resource); 
#line 8858
extern cudaError_t __stdcall cudaGetChannelDesc(cudaChannelFormatDesc * desc, cudaArray_const_t array); 
#line 8888
extern cudaChannelFormatDesc __stdcall cudaCreateChannelDesc(int x, int y, int z, int w, cudaChannelFormatKind f); 
#line 9113
extern cudaError_t __stdcall cudaCreateTextureObject(cudaTextureObject_t * pTexObject, const cudaResourceDesc * pResDesc, const cudaTextureDesc * pTexDesc, const cudaResourceViewDesc * pResViewDesc); 
#line 9133
extern cudaError_t __stdcall cudaDestroyTextureObject(cudaTextureObject_t texObject); 
#line 9153
extern cudaError_t __stdcall cudaGetTextureObjectResourceDesc(cudaResourceDesc * pResDesc, cudaTextureObject_t texObject); 
#line 9173
extern cudaError_t __stdcall cudaGetTextureObjectTextureDesc(cudaTextureDesc * pTexDesc, cudaTextureObject_t texObject); 
#line 9194
extern cudaError_t __stdcall cudaGetTextureObjectResourceViewDesc(cudaResourceViewDesc * pResViewDesc, cudaTextureObject_t texObject); 
#line 9239
extern cudaError_t __stdcall cudaCreateSurfaceObject(cudaSurfaceObject_t * pSurfObject, const cudaResourceDesc * pResDesc); 
#line 9259
extern cudaError_t __stdcall cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject); 
#line 9278
extern cudaError_t __stdcall cudaGetSurfaceObjectResourceDesc(cudaResourceDesc * pResDesc, cudaSurfaceObject_t surfObject); 
#line 9312
extern cudaError_t __stdcall cudaDriverGetVersion(int * driverVersion); 
#line 9341
extern cudaError_t __stdcall cudaRuntimeGetVersion(int * runtimeVersion); 
#line 9365
typedef void (__stdcall *cudaLogsCallback_t)(void * data, cudaLogLevel logLevel, char * message, size_t length); 
#line 9378
extern cudaError_t __stdcall cudaLogsRegisterCallback(cudaLogsCallback_t callbackFunc, void * userData, cudaLogsCallbackHandle * callback_out); 
#line 9389
extern cudaError_t __stdcall cudaLogsUnregisterCallback(cudaLogsCallbackHandle callback); 
#line 9401
extern cudaError_t __stdcall cudaLogsCurrent(cudaLogIterator * iterator_out, unsigned flags); 
#line 9425
extern cudaError_t __stdcall cudaLogsDumpToFile(cudaLogIterator * iterator, const char * pathToFile, unsigned flags); 
#line 9461
extern cudaError_t __stdcall cudaLogsDumpToMemory(cudaLogIterator * iterator, char * buffer, size_t * size, unsigned flags); 
#line 9508
extern cudaError_t __stdcall cudaGraphCreate(cudaGraph_t * pGraph, unsigned flags); 
#line 9607
extern cudaError_t __stdcall cudaGraphAddKernelNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaKernelNodeParams * pNodeParams); 
#line 9640
extern cudaError_t __stdcall cudaGraphKernelNodeGetParams(cudaGraphNode_t node, cudaKernelNodeParams * pNodeParams); 
#line 9667
extern cudaError_t __stdcall cudaGraphKernelNodeSetParams(cudaGraphNode_t node, const cudaKernelNodeParams * pNodeParams); 
#line 9687
extern cudaError_t __stdcall cudaGraphKernelNodeCopyAttributes(cudaGraphNode_t hDst, cudaGraphNode_t hSrc); 
#line 9710
extern cudaError_t __stdcall cudaGraphKernelNodeGetAttribute(cudaGraphNode_t hNode, cudaLaunchAttributeID attr, cudaLaunchAttributeValue * value_out); 
#line 9734
extern cudaError_t __stdcall cudaGraphKernelNodeSetAttribute(cudaGraphNode_t hNode, cudaLaunchAttributeID attr, const cudaLaunchAttributeValue * value); 
#line 9785
extern cudaError_t __stdcall cudaGraphAddMemcpyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaMemcpy3DParms * pCopyParams); 
#line 9844
extern cudaError_t __stdcall cudaGraphAddMemcpyNodeToSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 9913 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemcpyNodeFromSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 9981 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemcpyNode1D(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 10013 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemcpyNodeGetParams(cudaGraphNode_t node, cudaMemcpy3DParms * pNodeParams); 
#line 10040
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParams(cudaGraphNode_t node, const cudaMemcpy3DParms * pNodeParams); 
#line 10079
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParamsToSymbol(cudaGraphNode_t node, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 10125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParamsFromSymbol(cudaGraphNode_t node, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 10171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParams1D(cudaGraphNode_t node, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 10219 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemsetNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaMemsetParams * pMemsetParams); 
#line 10242
extern cudaError_t __stdcall cudaGraphMemsetNodeGetParams(cudaGraphNode_t node, cudaMemsetParams * pNodeParams); 
#line 10266
extern cudaError_t __stdcall cudaGraphMemsetNodeSetParams(cudaGraphNode_t node, const cudaMemsetParams * pNodeParams); 
#line 10308
extern cudaError_t __stdcall cudaGraphAddHostNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaHostNodeParams * pNodeParams); 
#line 10331
extern cudaError_t __stdcall cudaGraphHostNodeGetParams(cudaGraphNode_t node, cudaHostNodeParams * pNodeParams); 
#line 10355
extern cudaError_t __stdcall cudaGraphHostNodeSetParams(cudaGraphNode_t node, const cudaHostNodeParams * pNodeParams); 
#line 10397
extern cudaError_t __stdcall cudaGraphAddChildGraphNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaGraph_t childGraph); 
#line 10424
extern cudaError_t __stdcall cudaGraphChildGraphNodeGetGraph(cudaGraphNode_t node, cudaGraph_t * pGraph); 
#line 10462
extern cudaError_t __stdcall cudaGraphAddEmptyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies); 
#line 10506
extern cudaError_t __stdcall cudaGraphAddEventRecordNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaEvent_t event); 
#line 10533 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventRecordNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out); 
#line 10561 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventRecordNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event); 
#line 10608 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddEventWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaEvent_t event); 
#line 10635 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventWaitNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out); 
#line 10663 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventWaitNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event); 
#line 10713 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddExternalSemaphoresSignalNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
#line 10746 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresSignalNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams * params_out); 
#line 10774 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresSignalNodeSetParams(cudaGraphNode_t hNode, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
#line 10824 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddExternalSemaphoresWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
#line 10857 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresWaitNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams * params_out); 
#line 10885 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresWaitNodeSetParams(cudaGraphNode_t hNode, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
#line 10963 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemAllocNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaMemAllocNodeParams * nodeParams); 
#line 10990 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemAllocNodeGetParams(cudaGraphNode_t node, cudaMemAllocNodeParams * params_out); 
#line 11051 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemFreeNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dptr); 
#line 11075 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemFreeNodeGetParams(cudaGraphNode_t node, void * dptr_out); 
#line 11103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceGraphMemTrim(int device); 
#line 11140 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceGetGraphMemAttribute(int device, cudaGraphMemAttributeType attr, void * value); 
#line 11174 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceSetGraphMemAttribute(int device, cudaGraphMemAttributeType attr, void * value); 
#line 11205 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphClone(cudaGraph_t * pGraphClone, cudaGraph_t originalGraph); 
#line 11233
extern cudaError_t __stdcall cudaGraphNodeFindInClone(cudaGraphNode_t * pNode, cudaGraphNode_t originalNode, cudaGraph_t clonedGraph); 
#line 11264
extern cudaError_t __stdcall cudaGraphNodeGetType(cudaGraphNode_t node, cudaGraphNodeType * pType); 
#line 11295
extern cudaError_t __stdcall cudaGraphGetNodes(cudaGraph_t graph, cudaGraphNode_t * nodes, size_t * numNodes); 
#line 11326
extern cudaError_t __stdcall cudaGraphGetRootNodes(cudaGraph_t graph, cudaGraphNode_t * pRootNodes, size_t * pNumRootNodes); 
#line 11366
extern cudaError_t __stdcall cudaGraphGetEdges(cudaGraph_t graph, cudaGraphNode_t * from, cudaGraphNode_t * to, cudaGraphEdgeData * edgeData, size_t * numEdges); 
#line 11403
extern cudaError_t __stdcall cudaGraphNodeGetDependencies(cudaGraphNode_t node, cudaGraphNode_t * pDependencies, cudaGraphEdgeData * edgeData, size_t * pNumDependencies); 
#line 11441
extern cudaError_t __stdcall cudaGraphNodeGetDependentNodes(cudaGraphNode_t node, cudaGraphNode_t * pDependentNodes, cudaGraphEdgeData * edgeData, size_t * pNumDependentNodes); 
#line 11473
extern cudaError_t __stdcall cudaGraphAddDependencies(cudaGraph_t graph, const cudaGraphNode_t * from, const cudaGraphNode_t * to, const cudaGraphEdgeData * edgeData, size_t numDependencies); 
#line 11508
extern cudaError_t __stdcall cudaGraphRemoveDependencies(cudaGraph_t graph, const cudaGraphNode_t * from, const cudaGraphNode_t * to, const cudaGraphEdgeData * edgeData, size_t numDependencies); 
#line 11538
extern cudaError_t __stdcall cudaGraphDestroyNode(cudaGraphNode_t node); 
#line 11609
extern cudaError_t __stdcall cudaGraphInstantiate(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, unsigned __int64 flags = 0); 
#line 11682
extern cudaError_t __stdcall cudaGraphInstantiateWithFlags(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, unsigned __int64 flags = 0); 
#line 11789 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphInstantiateWithParams(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, cudaGraphInstantiateParams * instantiateParams); 
#line 11814
extern cudaError_t __stdcall cudaGraphExecGetFlags(cudaGraphExec_t graphExec, unsigned __int64 * flags); 
#line 11874
extern cudaError_t __stdcall cudaGraphExecKernelNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaKernelNodeParams * pNodeParams); 
#line 11925
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaMemcpy3DParms * pNodeParams); 
#line 11980
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParamsToSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 12043 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParamsFromSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 12104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParams1D(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 12163 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecMemsetNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaMemsetParams * pNodeParams); 
#line 12203
extern cudaError_t __stdcall cudaGraphExecHostNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaHostNodeParams * pNodeParams); 
#line 12250
extern cudaError_t __stdcall cudaGraphExecChildGraphNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaGraph_t childGraph); 
#line 12295 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecEventRecordNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event); 
#line 12340 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecEventWaitNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event); 
#line 12388 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecExternalSemaphoresSignalNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
#line 12436 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecExternalSemaphoresWaitNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
#line 12476 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphNodeSetEnabled(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, unsigned isEnabled); 
#line 12510 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphNodeGetEnabled(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, unsigned * isEnabled); 
#line 12604 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecUpdate(cudaGraphExec_t hGraphExec, cudaGraph_t hGraph, cudaGraphExecUpdateResultInfo * resultInfo); 
#line 12629
extern cudaError_t __stdcall cudaGraphUpload(cudaGraphExec_t graphExec, cudaStream_t stream); 
#line 12660 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphLaunch(cudaGraphExec_t graphExec, cudaStream_t stream); 
#line 12683
extern cudaError_t __stdcall cudaGraphExecDestroy(cudaGraphExec_t graphExec); 
#line 12704
extern cudaError_t __stdcall cudaGraphDestroy(cudaGraph_t graph); 
#line 12723
extern cudaError_t __stdcall cudaGraphDebugDotPrint(cudaGraph_t graph, const char * path, unsigned flags); 
#line 12759
extern cudaError_t __stdcall cudaUserObjectCreate(cudaUserObject_t * object_out, void * ptr, cudaHostFn_t destroy, unsigned initialRefcount, unsigned flags); 
#line 12783
extern cudaError_t __stdcall cudaUserObjectRetain(cudaUserObject_t object, unsigned count = 1); 
#line 12811
extern cudaError_t __stdcall cudaUserObjectRelease(cudaUserObject_t object, unsigned count = 1); 
#line 12839
extern cudaError_t __stdcall cudaGraphRetainUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned count = 1, unsigned flags = 0); 
#line 12864
extern cudaError_t __stdcall cudaGraphReleaseUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned count = 1); 
#line 12908
extern cudaError_t __stdcall cudaGraphAddNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, const cudaGraphEdgeData * dependencyData, size_t numDependencies, cudaGraphNodeParams * nodeParams); 
#line 12937
extern cudaError_t __stdcall cudaGraphNodeSetParams(cudaGraphNode_t node, cudaGraphNodeParams * nodeParams); 
#line 12986
extern cudaError_t __stdcall cudaGraphExecNodeSetParams(cudaGraphExec_t graphExec, cudaGraphNode_t node, cudaGraphNodeParams * nodeParams); 
#line 13013
extern cudaError_t __stdcall cudaGraphConditionalHandleCreate(cudaGraphConditionalHandle * pHandle_out, cudaGraph_t graph, unsigned defaultLaunchValue = 0, unsigned flags = 0); 
#line 13101
__declspec(deprecated) extern cudaError_t __stdcall cudaGetDriverEntryPoint(const char * symbol, void ** funcPtr, unsigned __int64 flags, cudaDriverEntryPointQueryResult * driverStatus = 0); 
#line 13178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGetDriverEntryPointByVersion(const char * symbol, void ** funcPtr, unsigned cudaVersion, unsigned __int64 flags, cudaDriverEntryPointQueryResult * driverStatus = 0); 
#line 13253 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaLibraryLoadData(cudaLibrary_t * library, const void * code, cudaJitOption * jitOptions, void ** jitOptionsValues, unsigned numJitOptions, cudaLibraryOption * libraryOptions, void ** libraryOptionValues, unsigned numLibraryOptions); 
#line 13313
extern cudaError_t __stdcall cudaLibraryLoadFromFile(cudaLibrary_t * library, const char * fileName, cudaJitOption * jitOptions, void ** jitOptionsValues, unsigned numJitOptions, cudaLibraryOption * libraryOptions, void ** libraryOptionValues, unsigned numLibraryOptions); 
#line 13334
extern cudaError_t __stdcall cudaLibraryUnload(cudaLibrary_t library); 
#line 13359
extern cudaError_t __stdcall cudaLibraryGetKernel(cudaKernel_t * pKernel, cudaLibrary_t library, const char * name); 
#line 13393
extern cudaError_t __stdcall cudaLibraryGetGlobal(void ** dptr, size_t * bytes, cudaLibrary_t library, const char * name); 
#line 13426
extern cudaError_t __stdcall cudaLibraryGetManaged(void ** dptr, size_t * bytes, cudaLibrary_t library, const char * name); 
#line 13453
extern cudaError_t __stdcall cudaLibraryGetUnifiedFunction(void ** fptr, cudaLibrary_t library, const char * symbol); 
#line 13475
extern cudaError_t __stdcall cudaLibraryGetKernelCount(unsigned * count, cudaLibrary_t lib); 
#line 13497
extern cudaError_t __stdcall cudaLibraryEnumerateKernels(cudaKernel_t * kernels, unsigned numKernels, cudaLibrary_t lib); 
#line 13566
extern cudaError_t __stdcall cudaKernelSetAttributeForDevice(cudaKernel_t kernel, cudaFuncAttribute attr, int value, int device); 
#line 13571
extern cudaError_t __stdcall cudaGetExportTable(const void ** ppExportTable, const cudaUUID_t * pExportTableId); 
#line 13757
extern cudaError_t __stdcall cudaGetFuncBySymbol(cudaFunction_t * functionPtr, const void * symbolPtr); 
#line 13781
extern cudaError_t __stdcall cudaGetKernel(cudaKernel_t * kernelPtr, const void * entryFuncAddr); 
#line 13948 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\cuda_runtime_api.h"
}
#line 120 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\channel_descriptor.h"
template< class T> __inline ::cudaChannelFormatDesc cudaCreateChannelDesc() 
#line 121
{ 
#line 122
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
#line 123
} 
#line 125
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf() 
#line 126
{ 
#line 127
int e = (((int)sizeof(unsigned short)) * 8); 
#line 129
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 130
} 
#line 132
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf1() 
#line 133
{ 
#line 134
int e = (((int)sizeof(unsigned short)) * 8); 
#line 136
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 137
} 
#line 139
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf2() 
#line 140
{ 
#line 141
int e = (((int)sizeof(unsigned short)) * 8); 
#line 143
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
#line 144
} 
#line 146
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf4() 
#line 147
{ 
#line 148
int e = (((int)sizeof(unsigned short)) * 8); 
#line 150
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
#line 151
} 
#line 153
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char> () 
#line 154
{ 
#line 155
int e = (((int)sizeof(char)) * 8); 
#line 160 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 162 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\channel_descriptor.h"
} 
#line 164
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> () 
#line 165
{ 
#line 166
int e = (((int)sizeof(signed char)) * 8); 
#line 168
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 169
} 
#line 171
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> () 
#line 172
{ 
#line 173
int e = (((int)sizeof(unsigned char)) * 8); 
#line 175
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 176
} 
#line 178
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> () 
#line 179
{ 
#line 180
int e = (((int)sizeof(signed char)) * 8); 
#line 182
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 183
} 
#line 185
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> () 
#line 186
{ 
#line 187
int e = (((int)sizeof(unsigned char)) * 8); 
#line 189
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 190
} 
#line 192
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> () 
#line 193
{ 
#line 194
int e = (((int)sizeof(signed char)) * 8); 
#line 196
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 197
} 
#line 199
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> () 
#line 200
{ 
#line 201
int e = (((int)sizeof(unsigned char)) * 8); 
#line 203
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 204
} 
#line 206
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> () 
#line 207
{ 
#line 208
int e = (((int)sizeof(signed char)) * 8); 
#line 210
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 211
} 
#line 213
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> () 
#line 214
{ 
#line 215
int e = (((int)sizeof(unsigned char)) * 8); 
#line 217
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 218
} 
#line 220
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short> () 
#line 221
{ 
#line 222
int e = (((int)sizeof(short)) * 8); 
#line 224
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 225
} 
#line 227
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> () 
#line 228
{ 
#line 229
int e = (((int)sizeof(unsigned short)) * 8); 
#line 231
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 232
} 
#line 234
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> () 
#line 235
{ 
#line 236
int e = (((int)sizeof(short)) * 8); 
#line 238
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 239
} 
#line 241
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> () 
#line 242
{ 
#line 243
int e = (((int)sizeof(unsigned short)) * 8); 
#line 245
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 246
} 
#line 248
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> () 
#line 249
{ 
#line 250
int e = (((int)sizeof(short)) * 8); 
#line 252
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 253
} 
#line 255
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> () 
#line 256
{ 
#line 257
int e = (((int)sizeof(unsigned short)) * 8); 
#line 259
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 260
} 
#line 262
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> () 
#line 263
{ 
#line 264
int e = (((int)sizeof(short)) * 8); 
#line 266
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 267
} 
#line 269
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> () 
#line 270
{ 
#line 271
int e = (((int)sizeof(unsigned short)) * 8); 
#line 273
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 274
} 
#line 276
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int> () 
#line 277
{ 
#line 278
int e = (((int)sizeof(int)) * 8); 
#line 280
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 281
} 
#line 283
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> () 
#line 284
{ 
#line 285
int e = (((int)sizeof(unsigned)) * 8); 
#line 287
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 288
} 
#line 290
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> () 
#line 291
{ 
#line 292
int e = (((int)sizeof(int)) * 8); 
#line 294
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 295
} 
#line 297
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> () 
#line 298
{ 
#line 299
int e = (((int)sizeof(unsigned)) * 8); 
#line 301
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 302
} 
#line 304
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> () 
#line 305
{ 
#line 306
int e = (((int)sizeof(int)) * 8); 
#line 308
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 309
} 
#line 311
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> () 
#line 312
{ 
#line 313
int e = (((int)sizeof(unsigned)) * 8); 
#line 315
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 316
} 
#line 318
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> () 
#line 319
{ 
#line 320
int e = (((int)sizeof(int)) * 8); 
#line 322
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 323
} 
#line 325
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> () 
#line 326
{ 
#line 327
int e = (((int)sizeof(unsigned)) * 8); 
#line 329
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 330
} 
#line 334
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long> () 
#line 335
{ 
#line 336
int e = (((int)sizeof(long)) * 8); 
#line 338
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 339
} 
#line 341
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned long> () 
#line 342
{ 
#line 343
int e = (((int)sizeof(unsigned long)) * 8); 
#line 345
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 346
} 
#line 348
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long1> () 
#line 349
{ 
#line 350
int e = (((int)sizeof(long)) * 8); 
#line 352
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 353
} 
#line 355
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong1> () 
#line 356
{ 
#line 357
int e = (((int)sizeof(unsigned long)) * 8); 
#line 359
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 360
} 
#line 362
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long2> () 
#line 363
{ 
#line 364
int e = (((int)sizeof(long)) * 8); 
#line 366
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 367
} 
#line 369
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong2> () 
#line 370
{ 
#line 371
int e = (((int)sizeof(unsigned long)) * 8); 
#line 373
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 374
} 
#line 376
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 377
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long4> () 
#line 378
{ 
#line 379
int e = (((int)sizeof(long)) * 8); 
#line 381
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 382
} 
#line 384
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong4> () 
#line 385
{ 
#line 386
int e = (((int)sizeof(unsigned long)) * 8); 
#line 388
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 389
} 
#line 390
__pragma( warning(pop)) 
#line 394 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\channel_descriptor.h"
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float> () 
#line 395
{ 
#line 396
int e = (((int)sizeof(float)) * 8); 
#line 398
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 399
} 
#line 401
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> () 
#line 402
{ 
#line 403
int e = (((int)sizeof(float)) * 8); 
#line 405
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 406
} 
#line 408
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> () 
#line 409
{ 
#line 410
int e = (((int)sizeof(float)) * 8); 
#line 412
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
#line 413
} 
#line 415
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> () 
#line 416
{ 
#line 417
int e = (((int)sizeof(float)) * 8); 
#line 419
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
#line 420
} 
#line 422
static __inline cudaChannelFormatDesc cudaCreateChannelDescNV12() 
#line 423
{ 
#line 424
int e = (((int)sizeof(char)) * 8); 
#line 426
return cudaCreateChannelDesc(e, e, e, 0, cudaChannelFormatKindNV12); 
#line 427
} 
#line 429
template< cudaChannelFormatKind > __inline ::cudaChannelFormatDesc cudaCreateChannelDesc() 
#line 430
{ 
#line 431
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
#line 432
} 
#line 435
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized8X1> () 
#line 436
{ 
#line 437
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindSignedNormalized8X1); 
#line 438
} 
#line 440
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized8X2> () 
#line 441
{ 
#line 442
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindSignedNormalized8X2); 
#line 443
} 
#line 445
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized8X4> () 
#line 446
{ 
#line 447
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindSignedNormalized8X4); 
#line 448
} 
#line 451
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized8X1> () 
#line 452
{ 
#line 453
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsignedNormalized8X1); 
#line 454
} 
#line 456
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized8X2> () 
#line 457
{ 
#line 458
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindUnsignedNormalized8X2); 
#line 459
} 
#line 461
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized8X4> () 
#line 462
{ 
#line 463
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedNormalized8X4); 
#line 464
} 
#line 467
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized16X1> () 
#line 468
{ 
#line 469
return cudaCreateChannelDesc(16, 0, 0, 0, cudaChannelFormatKindSignedNormalized16X1); 
#line 470
} 
#line 472
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized16X2> () 
#line 473
{ 
#line 474
return cudaCreateChannelDesc(16, 16, 0, 0, cudaChannelFormatKindSignedNormalized16X2); 
#line 475
} 
#line 477
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized16X4> () 
#line 478
{ 
#line 479
return cudaCreateChannelDesc(16, 16, 16, 16, cudaChannelFormatKindSignedNormalized16X4); 
#line 480
} 
#line 483
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized16X1> () 
#line 484
{ 
#line 485
return cudaCreateChannelDesc(16, 0, 0, 0, cudaChannelFormatKindUnsignedNormalized16X1); 
#line 486
} 
#line 488
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized16X2> () 
#line 489
{ 
#line 490
return cudaCreateChannelDesc(16, 16, 0, 0, cudaChannelFormatKindUnsignedNormalized16X2); 
#line 491
} 
#line 493
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized16X4> () 
#line 494
{ 
#line 495
return cudaCreateChannelDesc(16, 16, 16, 16, cudaChannelFormatKindUnsignedNormalized16X4); 
#line 496
} 
#line 499
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindNV12> () 
#line 500
{ 
#line 501
return cudaCreateChannelDesc(8, 8, 8, 0, cudaChannelFormatKindNV12); 
#line 502
} 
#line 505
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized1010102> () 
#line 506
{ 
#line 507
return cudaCreateChannelDesc(10, 10, 10, 2, cudaChannelFormatKindUnsignedNormalized1010102); 
#line 508
} 
#line 511
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed1> () 
#line 512
{ 
#line 513
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed1); 
#line 514
} 
#line 517
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed1SRGB> () 
#line 518
{ 
#line 519
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed1SRGB); 
#line 520
} 
#line 523
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed2> () 
#line 524
{ 
#line 525
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed2); 
#line 526
} 
#line 529
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed2SRGB> () 
#line 530
{ 
#line 531
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed2SRGB); 
#line 532
} 
#line 535
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed3> () 
#line 536
{ 
#line 537
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed3); 
#line 538
} 
#line 541
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed3SRGB> () 
#line 542
{ 
#line 543
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed3SRGB); 
#line 544
} 
#line 547
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed4> () 
#line 548
{ 
#line 549
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsignedBlockCompressed4); 
#line 550
} 
#line 553
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedBlockCompressed4> () 
#line 554
{ 
#line 555
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindSignedBlockCompressed4); 
#line 556
} 
#line 559
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed5> () 
#line 560
{ 
#line 561
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindUnsignedBlockCompressed5); 
#line 562
} 
#line 565
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedBlockCompressed5> () 
#line 566
{ 
#line 567
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindSignedBlockCompressed5); 
#line 568
} 
#line 571
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed6H> () 
#line 572
{ 
#line 573
return cudaCreateChannelDesc(16, 16, 16, 0, cudaChannelFormatKindUnsignedBlockCompressed6H); 
#line 574
} 
#line 577
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedBlockCompressed6H> () 
#line 578
{ 
#line 579
return cudaCreateChannelDesc(16, 16, 16, 0, cudaChannelFormatKindSignedBlockCompressed6H); 
#line 580
} 
#line 583
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed7> () 
#line 584
{ 
#line 585
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed7); 
#line 586
} 
#line 589
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed7SRGB> () 
#line 590
{ 
#line 591
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed7SRGB); 
#line 592
} 
#line 79 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\driver_functions.h"
static __inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz) 
#line 80
{ 
#line 81
cudaPitchedPtr s; 
#line 83
(s.ptr) = d; 
#line 84
(s.pitch) = p; 
#line 85
(s.xsize) = xsz; 
#line 86
(s.ysize) = ysz; 
#line 88
return s; 
#line 89
} 
#line 106
static __inline cudaPos make_cudaPos(size_t x, size_t y, size_t z) 
#line 107
{ 
#line 108
cudaPos p; 
#line 110
(p.x) = x; 
#line 111
(p.y) = y; 
#line 112
(p.z) = z; 
#line 114
return p; 
#line 115
} 
#line 132
static __inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d) 
#line 133
{ 
#line 134
cudaExtent e; 
#line 136
(e.width) = w; 
#line 137
(e.height) = h; 
#line 138
(e.depth) = d; 
#line 140
return e; 
#line 141
} 
#line 77 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_functions.h"
static __inline char1 make_char1(signed char x); 
#line 79
static __inline uchar1 make_uchar1(unsigned char x); 
#line 81
static __inline char2 make_char2(signed char x, signed char y); 
#line 83
static __inline uchar2 make_uchar2(unsigned char x, unsigned char y); 
#line 85
static __inline char3 make_char3(signed char x, signed char y, signed char z); 
#line 87
static __inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z); 
#line 89
static __inline char4 make_char4(signed char x, signed char y, signed char z, signed char w); 
#line 91
static __inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w); 
#line 93
static __inline short1 make_short1(short x); 
#line 95
static __inline ushort1 make_ushort1(unsigned short x); 
#line 97
static __inline short2 make_short2(short x, short y); 
#line 99
static __inline ushort2 make_ushort2(unsigned short x, unsigned short y); 
#line 101
static __inline short3 make_short3(short x, short y, short z); 
#line 103
static __inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z); 
#line 105
static __inline short4 make_short4(short x, short y, short z, short w); 
#line 107
static __inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w); 
#line 109
static __inline int1 make_int1(int x); 
#line 111
static __inline uint1 make_uint1(unsigned x); 
#line 113
static __inline int2 make_int2(int x, int y); 
#line 115
static __inline uint2 make_uint2(unsigned x, unsigned y); 
#line 117
static __inline int3 make_int3(int x, int y, int z); 
#line 119
static __inline uint3 make_uint3(unsigned x, unsigned y, unsigned z); 
#line 121
static __inline int4 make_int4(int x, int y, int z, int w); 
#line 123
static __inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w); 
#line 125
static __inline long1 make_long1(long x); 
#line 127
static __inline ulong1 make_ulong1(unsigned long x); 
#line 129
static __inline long2 make_long2(long x, long y); 
#line 131
static __inline ulong2 make_ulong2(unsigned long x, unsigned long y); 
#line 133
static __inline long3 make_long3(long x, long y, long z); 
#line 135
static __inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z); 
#line 137
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 138
static __inline long4 make_long4(long x, long y, long z, long w); 
#line 140
static __inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w); 
#line 141
__pragma( warning(pop)) 
#line 143
static __inline long4_16a make_long4_16a(long x, long y, long z, long w); 
#line 145
static __inline long4_32a make_long4_32a(long x, long y, long z, long w); 
#line 147
static __inline ulong4_16a make_ulong4_16a(unsigned long x, unsigned long y, unsigned long z, unsigned long w); 
#line 149
static __inline ulong4_32a make_ulong4_32a(unsigned long x, unsigned long y, unsigned long z, unsigned long w); 
#line 151
static __inline float1 make_float1(float x); 
#line 153
static __inline float2 make_float2(float x, float y); 
#line 155
static __inline float3 make_float3(float x, float y, float z); 
#line 157
static __inline float4 make_float4(float x, float y, float z, float w); 
#line 159
static __inline longlong1 make_longlong1(__int64 x); 
#line 161
static __inline ulonglong1 make_ulonglong1(unsigned __int64 x); 
#line 163
static __inline longlong2 make_longlong2(__int64 x, __int64 y); 
#line 165
static __inline ulonglong2 make_ulonglong2(unsigned __int64 x, unsigned __int64 y); 
#line 167
static __inline longlong3 make_longlong3(__int64 x, __int64 y, __int64 z); 
#line 169
static __inline ulonglong3 make_ulonglong3(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z); 
#line 171
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 172
static __inline longlong4 make_longlong4(__int64 x, __int64 y, __int64 z, __int64 w); 
#line 174
static __inline ulonglong4 make_ulonglong4(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z, unsigned __int64 w); 
#line 175
__pragma( warning(pop)) 
#line 177
static __inline double1 make_double1(double x); 
#line 179
static __inline double2 make_double2(double x, double y); 
#line 181
static __inline double3 make_double3(double x, double y, double z); 
#line 183
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 184
static __inline double4 make_double4(double x, double y, double z, double w); 
#line 185
__pragma( warning(pop)) 
#line 187
static __inline double4_16a make_double4_16a(double x, double y, double z, double w); 
#line 189
static __inline double4_32a make_double4_32a(double x, double y, double z, double w); 
#line 73 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\vector_functions.hpp"
static __inline char1 make_char1(signed char x) 
#line 74
{ 
#line 75
char1 t; (t.x) = x; return t; 
#line 76
} 
#line 78
static __inline uchar1 make_uchar1(unsigned char x) 
#line 79
{ 
#line 80
uchar1 t; (t.x) = x; return t; 
#line 81
} 
#line 83
static __inline char2 make_char2(signed char x, signed char y) 
#line 84
{ 
#line 85
char2 t; (t.x) = x; (t.y) = y; return t; 
#line 86
} 
#line 88
static __inline uchar2 make_uchar2(unsigned char x, unsigned char y) 
#line 89
{ 
#line 90
uchar2 t; (t.x) = x; (t.y) = y; return t; 
#line 91
} 
#line 93
static __inline char3 make_char3(signed char x, signed char y, signed char z) 
#line 94
{ 
#line 95
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 96
} 
#line 98
static __inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z) 
#line 99
{ 
#line 100
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 101
} 
#line 103
static __inline char4 make_char4(signed char x, signed char y, signed char z, signed char w) 
#line 104
{ 
#line 105
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 106
} 
#line 108
static __inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w) 
#line 109
{ 
#line 110
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 111
} 
#line 113
static __inline short1 make_short1(short x) 
#line 114
{ 
#line 115
short1 t; (t.x) = x; return t; 
#line 116
} 
#line 118
static __inline ushort1 make_ushort1(unsigned short x) 
#line 119
{ 
#line 120
ushort1 t; (t.x) = x; return t; 
#line 121
} 
#line 123
static __inline short2 make_short2(short x, short y) 
#line 124
{ 
#line 125
short2 t; (t.x) = x; (t.y) = y; return t; 
#line 126
} 
#line 128
static __inline ushort2 make_ushort2(unsigned short x, unsigned short y) 
#line 129
{ 
#line 130
ushort2 t; (t.x) = x; (t.y) = y; return t; 
#line 131
} 
#line 133
static __inline short3 make_short3(short x, short y, short z) 
#line 134
{ 
#line 135
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 136
} 
#line 138
static __inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z) 
#line 139
{ 
#line 140
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 141
} 
#line 143
static __inline short4 make_short4(short x, short y, short z, short w) 
#line 144
{ 
#line 145
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 146
} 
#line 148
static __inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w) 
#line 149
{ 
#line 150
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 151
} 
#line 153
static __inline int1 make_int1(int x) 
#line 154
{ 
#line 155
int1 t; (t.x) = x; return t; 
#line 156
} 
#line 158
static __inline uint1 make_uint1(unsigned x) 
#line 159
{ 
#line 160
uint1 t; (t.x) = x; return t; 
#line 161
} 
#line 163
static __inline int2 make_int2(int x, int y) 
#line 164
{ 
#line 165
int2 t; (t.x) = x; (t.y) = y; return t; 
#line 166
} 
#line 168
static __inline uint2 make_uint2(unsigned x, unsigned y) 
#line 169
{ 
#line 170
uint2 t; (t.x) = x; (t.y) = y; return t; 
#line 171
} 
#line 173
static __inline int3 make_int3(int x, int y, int z) 
#line 174
{ 
#line 175
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 176
} 
#line 178
static __inline uint3 make_uint3(unsigned x, unsigned y, unsigned z) 
#line 179
{ 
#line 180
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 181
} 
#line 183
static __inline int4 make_int4(int x, int y, int z, int w) 
#line 184
{ 
#line 185
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 186
} 
#line 188
static __inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w) 
#line 189
{ 
#line 190
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 191
} 
#line 193
static __inline long1 make_long1(long x) 
#line 194
{ 
#line 195
long1 t; (t.x) = x; return t; 
#line 196
} 
#line 198
static __inline ulong1 make_ulong1(unsigned long x) 
#line 199
{ 
#line 200
ulong1 t; (t.x) = x; return t; 
#line 201
} 
#line 203
static __inline long2 make_long2(long x, long y) 
#line 204
{ 
#line 205
long2 t; (t.x) = x; (t.y) = y; return t; 
#line 206
} 
#line 208
static __inline ulong2 make_ulong2(unsigned long x, unsigned long y) 
#line 209
{ 
#line 210
ulong2 t; (t.x) = x; (t.y) = y; return t; 
#line 211
} 
#line 213
static __inline long3 make_long3(long x, long y, long z) 
#line 214
{ 
#line 215
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 216
} 
#line 218
static __inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z) 
#line 219
{ 
#line 220
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 221
} 
#line 223
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 224
static __inline long4 make_long4(long x, long y, long z, long w) 
#line 225
{ 
#line 226
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 227
} 
#line 229
static __inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
#line 230
{ 
#line 231
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 232
} 
#line 233
__pragma( warning(pop)) 
#line 235
static __inline long4_16a make_long4_16a(long x, long y, long z, long w) 
#line 236
{ 
#line 237
long4_16a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 238
} 
#line 240
static __inline long4_32a make_long4_32a(long x, long y, long z, long w) 
#line 241
{ 
#line 242
long4_32a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 243
} 
#line 245
static __inline ulong4_16a make_ulong4_16a(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
#line 246
{ 
#line 247
ulong4_16a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 248
} 
#line 250
static __inline ulong4_32a make_ulong4_32a(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
#line 251
{ 
#line 252
ulong4_32a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 253
} 
#line 255
static __inline float1 make_float1(float x) 
#line 256
{ 
#line 257
float1 t; (t.x) = x; return t; 
#line 258
} 
#line 260
static __inline float2 make_float2(float x, float y) 
#line 261
{ 
#line 262
float2 t; (t.x) = x; (t.y) = y; return t; 
#line 263
} 
#line 265
static __inline float3 make_float3(float x, float y, float z) 
#line 266
{ 
#line 267
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 268
} 
#line 270
static __inline float4 make_float4(float x, float y, float z, float w) 
#line 271
{ 
#line 272
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 273
} 
#line 275
static __inline longlong1 make_longlong1(__int64 x) 
#line 276
{ 
#line 277
longlong1 t; (t.x) = x; return t; 
#line 278
} 
#line 280
static __inline ulonglong1 make_ulonglong1(unsigned __int64 x) 
#line 281
{ 
#line 282
ulonglong1 t; (t.x) = x; return t; 
#line 283
} 
#line 285
static __inline longlong2 make_longlong2(__int64 x, __int64 y) 
#line 286
{ 
#line 287
longlong2 t; (t.x) = x; (t.y) = y; return t; 
#line 288
} 
#line 290
static __inline ulonglong2 make_ulonglong2(unsigned __int64 x, unsigned __int64 y) 
#line 291
{ 
#line 292
ulonglong2 t; (t.x) = x; (t.y) = y; return t; 
#line 293
} 
#line 295
static __inline longlong3 make_longlong3(__int64 x, __int64 y, __int64 z) 
#line 296
{ 
#line 297
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 298
} 
#line 300
static __inline ulonglong3 make_ulonglong3(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z) 
#line 301
{ 
#line 302
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 303
} 
#line 305
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 306
static __inline longlong4 make_longlong4(__int64 x, __int64 y, __int64 z, __int64 w) 
#line 307
{ 
#line 308
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 309
} 
#line 311
static __inline ulonglong4 make_ulonglong4(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z, unsigned __int64 w) 
#line 312
{ 
#line 313
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 314
} 
#line 315
__pragma( warning(pop)) 
#line 317
static __inline longlong4_16a make_longlong4_16a(__int64 x, __int64 y, __int64 z, __int64 w) 
#line 318
{ 
#line 319
longlong4_16a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 320
} 
#line 322
static __inline longlong4_32a make_longlong4_32a(__int64 x, __int64 y, __int64 z, __int64 w) 
#line 323
{ 
#line 324
longlong4_32a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 325
} 
#line 327
static __inline ulonglong4_16a make_ulonglong4_16a(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z, unsigned __int64 w) 
#line 328
{ 
#line 329
ulonglong4_16a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 330
} 
#line 332
static __inline ulonglong4_32a make_ulonglong4_32a(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z, unsigned __int64 w) 
#line 333
{ 
#line 334
ulonglong4_32a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 335
} 
#line 336
static __inline double1 make_double1(double x) 
#line 337
{ 
#line 338
double1 t; (t.x) = x; return t; 
#line 339
} 
#line 341
static __inline double2 make_double2(double x, double y) 
#line 342
{ 
#line 343
double2 t; (t.x) = x; (t.y) = y; return t; 
#line 344
} 
#line 346
static __inline double3 make_double3(double x, double y, double z) 
#line 347
{ 
#line 348
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 349
} 
#line 351
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 352
static __inline double4 make_double4(double x, double y, double z, double w) 
#line 353
{ 
#line 354
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 355
} 
#line 356
__pragma( warning(pop)) 
#line 358
static __inline double4_16a make_double4_16a(double x, double y, double z, double w) 
#line 359
{ 
#line 360
double4_16a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 361
} 
#line 363
static __inline double4_32a make_double4_32a(double x, double y, double z, double w) 
#line 364
{ 
#line 365
double4_32a t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 366
} 
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\errno.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 23
int *__cdecl _errno(); 
#line 26
errno_t __cdecl _set_errno(int _Value); 
#line 27
errno_t __cdecl _get_errno(int * _Value); 
#line 29
unsigned long *__cdecl __doserrno(); 
#line 32
errno_t __cdecl _set_doserrno(unsigned long _Value); 
#line 33
errno_t __cdecl _get_doserrno(unsigned long * _Value); 
#line 134 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\errno.h"
}__pragma( pack ( pop )) 
#line 136
#pragma warning(pop)
#line 12 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_string.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 21
[[nodiscard]] const void *__cdecl 
#line 22
memchr(const void * _Buf, int _Val, size_t _MaxCount); 
#line 28
[[nodiscard]] int __cdecl 
#line 29
memcmp(const void * _Buf1, const void * _Buf2, size_t _Size); 
#line 43 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_string.h"
void *__cdecl memcpy(void * _Dst, const void * _Src, size_t _Size); 
#line 50
void *__cdecl memmove(void * _Dst, const void * _Src, size_t _Size); 
#line 63 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_string.h"
void *__cdecl memset(void * _Dst, int _Val, size_t _Size); 
#line 69
[[nodiscard]] const char *__cdecl 
#line 70
strchr(const char * _Str, int _Val); 
#line 75
[[nodiscard]] const char *__cdecl 
#line 76
strrchr(const char * _Str, int _Ch); 
#line 81
[[nodiscard]] const char *__cdecl 
#line 82
strstr(const char * _Str, const char * _SubStr); 
#line 87
[[nodiscard]] const __wchar_t *__cdecl 
#line 89
wcschr(const __wchar_t * _Str, __wchar_t _Ch); 
#line 94
[[nodiscard]] const __wchar_t *__cdecl 
#line 95
wcsrchr(const __wchar_t * _Str, __wchar_t _Ch); 
#line 100
[[nodiscard]] const __wchar_t *__cdecl 
#line 102
wcsstr(const __wchar_t * _Str, const __wchar_t * _SubStr); 
#line 109
}__pragma( pack ( pop )) 
#line 113 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_string.h"
#pragma warning(pop)
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memcpy_s.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 39 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memcpy_s.h"
static __inline errno_t __cdecl memcpy_s(void *const 
#line 40
_Destination, const rsize_t 
#line 41
_DestinationSize, const void *const 
#line 42
_Source, const rsize_t 
#line 43
_SourceSize) 
#line 45
{ 
#line 46
if (_SourceSize == (0)) 
#line 47
{ 
#line 48
return 0; 
#line 49
}  
#line 51
{ int _Expr_val = !(!(_Destination != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 52
if ((_Source == (0)) || (_DestinationSize < _SourceSize)) 
#line 53
{ 
#line 54
memset(_Destination, 0, _DestinationSize); 
#line 56
{ int _Expr_val = !(!(_Source != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 57
{ int _Expr_val = !(!(_DestinationSize >= _SourceSize)); if (!_Expr_val) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; }  } ; 
#line 60
return 22; 
#line 61
}  
#line 62
memcpy(_Destination, _Source, _SourceSize); 
#line 63
return 0; 
#line 64
} 
#line 67
static __inline errno_t __cdecl memmove_s(void *const 
#line 68
_Destination, const rsize_t 
#line 69
_DestinationSize, const void *const 
#line 70
_Source, const rsize_t 
#line 71
_SourceSize) 
#line 73
{ 
#line 74
if (_SourceSize == (0)) 
#line 75
{ 
#line 76
return 0; 
#line 77
}  
#line 79
{ int _Expr_val = !(!(_Destination != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 80
{ int _Expr_val = !(!(_Source != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 81
{ int _Expr_val = !(!(_DestinationSize >= _SourceSize)); if (!_Expr_val) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; }  } ; 
#line 83
memmove(_Destination, _Source, _SourceSize); 
#line 84
return 0; 
#line 85
} 
#line 93 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memcpy_s.h"
}
#line 92
#pragma warning(pop)
__pragma( pack ( pop )) 
#line 17 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memory.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 23
__pragma( pack ( push, 8 )) extern "C" {
#line 28
int __cdecl _memicmp(const void * _Buf1, const void * _Buf2, size_t _Size); 
#line 35
int __cdecl _memicmp_l(const void * _Buf1, const void * _Buf2, size_t _Size, _locale_t _Locale); 
#line 83 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memory.h"
void *__cdecl memccpy(void * _Dst, const void * _Src, int _Val, size_t _Size); 
#line 91
int __cdecl memicmp(const void * _Buf1, const void * _Buf2, size_t _Size); 
#line 104 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memory.h"
extern "C++" inline void *__cdecl memchr(void *
#line 105
_Pv, int 
#line 106
_C, size_t 
#line 107
_N) 
#line 109
{ 
#line 110
const void *const _Pvc = _Pv; 
#line 111
return const_cast< void *>(memchr(_Pvc, _C, _N)); 
#line 112
} 
#line 118 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memory.h"
}__pragma( pack ( pop )) 
#line 122 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_memory.h"
#pragma warning(pop)
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 20
__pragma( pack ( push, 8 )) extern "C" {
#line 32
errno_t __cdecl wcscat_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source); 
#line 39
errno_t __cdecl wcscpy_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source); 
#line 46
errno_t __cdecl wcsncat_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source, rsize_t _MaxCount); 
#line 54
errno_t __cdecl wcsncpy_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source, rsize_t _MaxCount); 
#line 62
__wchar_t *__cdecl wcstok_s(__wchar_t * _String, const __wchar_t * _Delimiter, __wchar_t ** _Context); 
#line 83 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__declspec(allocator) __wchar_t *__cdecl _wcsdup(const __wchar_t * _String); 
#line 93 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcscat_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source ) throw ( ) { return wcscat_s ( _Destination, _Size, _Source ); }}
#line 100 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcscat(__wchar_t * _Destination, const __wchar_t * _Source); 
#line 108 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
int __cdecl wcscmp(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 113
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcscpy_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source ) throw ( ) { return wcscpy_s ( _Destination, _Size, _Source ); }}
#line 119 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcscpy(__wchar_t * _Destination, const __wchar_t * _Source); 
#line 126 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
size_t __cdecl wcscspn(const __wchar_t * _String, const __wchar_t * _Control); 
#line 132
size_t __cdecl wcslen(const __wchar_t * _String); 
#line 145 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
size_t __cdecl wcsnlen(const __wchar_t * _Source, size_t _MaxCount); 
#line 161 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
static __inline size_t __cdecl wcsnlen_s(const __wchar_t *
#line 162
_Source, size_t 
#line 163
_MaxCount) 
#line 165
{ 
#line 166
return (_Source == (0)) ? 0 : wcsnlen(_Source, _MaxCount); 
#line 167
} 
#line 171 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcsncat_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source, size_t _Count ) throw ( ) { return wcsncat_s ( _Destination, _Size, _Source, _Count ); }}
#line 178 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcsncat(__wchar_t * _Destination, const __wchar_t * _Source, size_t _Count); 
#line 187 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
int __cdecl wcsncmp(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 193
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcsncpy_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source, size_t _Count ) throw ( ) { return wcsncpy_s ( _Destination, _Size, _Source, _Count ); }}
#line 200 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcsncpy(__wchar_t * _Destination, const __wchar_t * _Source, size_t _Count); 
#line 209 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
const __wchar_t *__cdecl wcspbrk(const __wchar_t * _String, const __wchar_t * _Control); 
#line 215
size_t __cdecl wcsspn(const __wchar_t * _String, const __wchar_t * _Control); 
#line 221
__wchar_t *__cdecl wcstok(__wchar_t * _String, const __wchar_t * _Delimiter, __wchar_t ** _Context); 
#line 239 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
static __inline __wchar_t *__cdecl _wcstok(__wchar_t *const 
#line 240
_String, const __wchar_t *const 
#line 241
_Delimiter) 
#line 243
{ 
#line 244
return wcstok(_String, _Delimiter, 0); 
#line 245
} 
#line 253 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
extern "C++" 
#line 252
__declspec(deprecated("wcstok has been changed to conform with the ISO C standard, adding an extra context parameter. To use the legacy Microsoft wcsto" "k, define _CRT_NON_CONFORMING_WCSTOK.")) inline __wchar_t *__cdecl 
#line 253
wcstok(__wchar_t *
#line 254
_String, const __wchar_t *
#line 255
_Delimiter) throw() 
#line 257
{ 
#line 258
return wcstok(_String, _Delimiter, 0); 
#line 259
} 
#line 268 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcserror(int _ErrorNumber); 
#line 273
errno_t __cdecl _wcserror_s(__wchar_t * _Buffer, size_t _SizeInWords, int _ErrorNumber); 
#line 279
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcserror_s ( wchar_t ( & _Buffer ) [ _Size ], int _Error ) throw ( ) { return _wcserror_s ( _Buffer, _Size, _Error ); }}
#line 288 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl __wcserror(const __wchar_t * _String); 
#line 292
errno_t __cdecl __wcserror_s(__wchar_t * _Buffer, size_t _SizeInWords, const __wchar_t * _ErrorMessage); 
#line 298
extern "C++" {template < size_t _Size > inline errno_t __cdecl __wcserror_s ( wchar_t ( & _Buffer ) [ _Size ], wchar_t const * _ErrorMessage ) throw ( ) { return __wcserror_s ( _Buffer, _Size, _ErrorMessage ); }}
#line 304 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
int __cdecl _wcsicmp(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 309
int __cdecl _wcsicmp_l(const __wchar_t * _String1, const __wchar_t * _String2, _locale_t _Locale); 
#line 315
int __cdecl _wcsnicmp(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 321
int __cdecl _wcsnicmp_l(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 328
errno_t __cdecl _wcsnset_s(__wchar_t * _Destination, size_t _SizeInWords, __wchar_t _Value, size_t _MaxCount); 
#line 335
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsnset_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t _Value, size_t _MaxCount ) throw ( ) { return _wcsnset_s ( _Destination, _Size, _Value, _MaxCount ); }}
#line 342 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsnset(__wchar_t * _String, __wchar_t _Value, size_t _MaxCount); 
#line 350 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsrev(__wchar_t * _String); 
#line 354
errno_t __cdecl _wcsset_s(__wchar_t * _Destination, size_t _SizeInWords, __wchar_t _Value); 
#line 360
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsset_s ( wchar_t ( & _String ) [ _Size ], wchar_t _Value ) throw ( ) { return _wcsset_s ( _String, _Size, _Value ); }}
#line 366 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsset(__wchar_t * _String, __wchar_t _Value); 
#line 373 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcslwr_s(__wchar_t * _String, size_t _SizeInWords); 
#line 378
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcslwr_s ( wchar_t ( & _String ) [ _Size ] ) throw ( ) { return _wcslwr_s ( _String, _Size ); }}
#line 383 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcslwr(__wchar_t * _String); 
#line 389 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcslwr_s_l(__wchar_t * _String, size_t _SizeInWords, _locale_t _Locale); 
#line 395
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcslwr_s_l ( wchar_t ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _wcslwr_s_l ( _String, _Size, _Locale ); }}
#line 401 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcslwr_l(__wchar_t * _String, _locale_t _Locale); 
#line 409 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcsupr_s(__wchar_t * _String, size_t _Size); 
#line 414
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsupr_s ( wchar_t ( & _String ) [ _Size ] ) throw ( ) { return _wcsupr_s ( _String, _Size ); }}
#line 419 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsupr(__wchar_t * _String); 
#line 425 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcsupr_s_l(__wchar_t * _String, size_t _Size, _locale_t _Locale); 
#line 431
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsupr_s_l ( wchar_t ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _wcsupr_s_l ( _String, _Size, _Locale ); }}
#line 437 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsupr_l(__wchar_t * _String, _locale_t _Locale); 
#line 446 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
size_t __cdecl wcsxfrm(__wchar_t * _Destination, const __wchar_t * _Source, size_t _MaxCount); 
#line 454
size_t __cdecl _wcsxfrm_l(__wchar_t * _Destination, const __wchar_t * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 462
int __cdecl wcscoll(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 468
int __cdecl _wcscoll_l(const __wchar_t * _String1, const __wchar_t * _String2, _locale_t _Locale); 
#line 475
int __cdecl _wcsicoll(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 481
int __cdecl _wcsicoll_l(const __wchar_t * _String1, const __wchar_t * _String2, _locale_t _Locale); 
#line 488
int __cdecl _wcsncoll(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 495
int __cdecl _wcsncoll_l(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 503
int __cdecl _wcsnicoll(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 510
int __cdecl _wcsnicoll_l(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 525
extern "C++" {
#line 529
inline __wchar_t *__cdecl wcschr(__wchar_t *_String, __wchar_t _C) 
#line 530
{ 
#line 531
return const_cast< __wchar_t *>(wcschr(static_cast< const __wchar_t *>(_String), _C)); 
#line 532
} 
#line 535
inline __wchar_t *__cdecl wcspbrk(__wchar_t *_String, const __wchar_t *_Control) 
#line 536
{ 
#line 537
return const_cast< __wchar_t *>(wcspbrk(static_cast< const __wchar_t *>(_String), _Control)); 
#line 538
} 
#line 541
inline __wchar_t *__cdecl wcsrchr(__wchar_t *_String, __wchar_t _C) 
#line 542
{ 
#line 543
return const_cast< __wchar_t *>(wcsrchr(static_cast< const __wchar_t *>(_String), _C)); 
#line 544
} 
#line 548
inline __wchar_t *__cdecl wcsstr(__wchar_t *_String, const __wchar_t *_SubStr) 
#line 549
{ 
#line 550
return const_cast< __wchar_t *>(wcsstr(static_cast< const __wchar_t *>(_String), _SubStr)); 
#line 551
} 
#line 553
}
#line 570 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcsdup(const __wchar_t * _String); 
#line 582 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
int __cdecl wcsicmp(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 588
int __cdecl wcsnicmp(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 596
__wchar_t *__cdecl wcsnset(__wchar_t * _String, __wchar_t _Value, size_t _MaxCount); 
#line 604
__wchar_t *__cdecl wcsrev(__wchar_t * _String); 
#line 610
__wchar_t *__cdecl wcsset(__wchar_t * _String, __wchar_t _Value); 
#line 617
__wchar_t *__cdecl wcslwr(__wchar_t * _String); 
#line 623
__wchar_t *__cdecl wcsupr(__wchar_t * _String); 
#line 628
int __cdecl wcsicoll(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 637 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
}__pragma( pack ( pop )) 
#line 641 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wstring.h"
#pragma warning(pop)
#line 19 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 23
__pragma( pack ( push, 8 )) extern "C" {
#line 32
errno_t __cdecl strcpy_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source); 
#line 39
errno_t __cdecl strcat_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source); 
#line 46
errno_t __cdecl strerror_s(char * _Buffer, size_t _SizeInBytes, int _ErrorNumber); 
#line 52
errno_t __cdecl strncat_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source, rsize_t _MaxCount); 
#line 60
errno_t __cdecl strncpy_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source, rsize_t _MaxCount); 
#line 68
char *__cdecl strtok_s(char * _String, const char * _Delimiter, char ** _Context); 
#line 76 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
void *__cdecl _memccpy(void * _Dst, const void * _Src, int _Val, size_t _MaxCount); 
#line 83
extern "C++" {template < size_t _Size > inline errno_t __cdecl strcat_s ( char ( & _Destination ) [ _Size ], char const * _Source ) throw ( ) { return strcat_s ( _Destination, _Size, _Source ); }}
#line 91 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl strcat(char * _Destination, const char * _Source); 
#line 100 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
int __cdecl strcmp(const char * _Str1, const char * _Str2); 
#line 106
int __cdecl _strcmpi(const char * _String1, const char * _String2); 
#line 112
int __cdecl strcoll(const char * _String1, const char * _String2); 
#line 118
int __cdecl _strcoll_l(const char * _String1, const char * _String2, _locale_t _Locale); 
#line 124
extern "C++" {template < size_t _Size > inline errno_t __cdecl strcpy_s ( char ( & _Destination ) [ _Size ], char const * _Source ) throw ( ) { return strcpy_s ( _Destination, _Size, _Source ); }}
#line 130 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl strcpy(char * _Destination, const char * _Source); 
#line 137 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
size_t __cdecl strcspn(const char * _Str, const char * _Control); 
#line 148 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
__declspec(allocator) char *__cdecl _strdup(const char * _Source); 
#line 159 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl _strerror(const char * _ErrorMessage); 
#line 164
errno_t __cdecl _strerror_s(char * _Buffer, size_t _SizeInBytes, const char * _ErrorMessage); 
#line 170
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strerror_s ( char ( & _Buffer ) [ _Size ], char const * _ErrorMessage ) throw ( ) { return _strerror_s ( _Buffer, _Size, _ErrorMessage ); }}
#line 178 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl strerror(int _ErrorMessage); 
#line 182
extern "C++" {template < size_t _Size > inline errno_t __cdecl strerror_s ( char ( & _Buffer ) [ _Size ], int _ErrorMessage ) throw ( ) { return strerror_s ( _Buffer, _Size, _ErrorMessage ); }}
#line 189 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
int __cdecl _stricmp(const char * _String1, const char * _String2); 
#line 195
int __cdecl _stricoll(const char * _String1, const char * _String2); 
#line 201
int __cdecl _stricoll_l(const char * _String1, const char * _String2, _locale_t _Locale); 
#line 208
int __cdecl _stricmp_l(const char * _String1, const char * _String2, _locale_t _Locale); 
#line 215
size_t __cdecl strlen(const char * _Str); 
#line 220
errno_t __cdecl _strlwr_s(char * _String, size_t _Size); 
#line 225
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strlwr_s ( char ( & _String ) [ _Size ] ) throw ( ) { return _strlwr_s ( _String, _Size ); }}
#line 230 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl _strlwr(char * _String); 
#line 236 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
errno_t __cdecl _strlwr_s_l(char * _String, size_t _Size, _locale_t _Locale); 
#line 242
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strlwr_s_l ( char ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _strlwr_s_l ( _String, _Size, _Locale ); }}
#line 248 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl _strlwr_l(char * _String, _locale_t _Locale); 
#line 255 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl strncat_s ( char ( & _Destination ) [ _Size ], char const * _Source, size_t _Count ) throw ( ) { return strncat_s ( _Destination, _Size, _Source, _Count ); }}
#line 262 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl strncat(char * _Destination, const char * _Source, size_t _Count); 
#line 271 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
int __cdecl strncmp(const char * _Str1, const char * _Str2, size_t _MaxCount); 
#line 278
int __cdecl _strnicmp(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 285
int __cdecl _strnicmp_l(const char * _String1, const char * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 293
int __cdecl _strnicoll(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 300
int __cdecl _strnicoll_l(const char * _String1, const char * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 308
int __cdecl _strncoll(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 315
int __cdecl _strncoll_l(const char * _String1, const char * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 322
size_t __cdecl __strncnt(const char * _String, size_t _Count); 
#line 327
extern "C++" {template < size_t _Size > inline errno_t __cdecl strncpy_s ( char ( & _Destination ) [ _Size ], char const * _Source, size_t _Count ) throw ( ) { return strncpy_s ( _Destination, _Size, _Source, _Count ); }}
#line 334 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl strncpy(char * _Destination, const char * _Source, size_t _Count); 
#line 351 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
size_t __cdecl strnlen(const char * _String, size_t _MaxCount); 
#line 367 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
static __inline size_t __cdecl strnlen_s(const char *
#line 368
_String, size_t 
#line 369
_MaxCount) 
#line 371
{ 
#line 372
return (_String == (0)) ? 0 : strnlen(_String, _MaxCount); 
#line 373
} 
#line 378 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
errno_t __cdecl _strnset_s(char * _String, size_t _SizeInBytes, int _Value, size_t _MaxCount); 
#line 385
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strnset_s ( char ( & _Destination ) [ _Size ], int _Value, size_t _Count ) throw ( ) { return _strnset_s ( _Destination, _Size, _Value, _Count ); }}
#line 392 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl _strnset(char * _Destination, int _Value, size_t _Count); 
#line 401 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
const char *__cdecl strpbrk(const char * _Str, const char * _Control); 
#line 406
char *__cdecl _strrev(char * _Str); 
#line 411
errno_t __cdecl _strset_s(char * _Destination, size_t _DestinationSize, int _Value); 
#line 417
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strset_s ( char ( & _Destination ) [ _Size ], int _Value ) throw ( ) { return _strset_s ( _Destination, _Size, _Value ); }}
#line 423 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl _strset(char * _Destination, int _Value); 
#line 430 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
size_t __cdecl strspn(const char * _Str, const char * _Control); 
#line 436
char *__cdecl strtok(char * _String, const char * _Delimiter); 
#line 442
errno_t __cdecl _strupr_s(char * _String, size_t _Size); 
#line 447
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strupr_s ( char ( & _String ) [ _Size ] ) throw ( ) { return _strupr_s ( _String, _Size ); }}
#line 452 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl _strupr(char * _String); 
#line 458 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
errno_t __cdecl _strupr_s_l(char * _String, size_t _Size, _locale_t _Locale); 
#line 464
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strupr_s_l ( char ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _strupr_s_l ( _String, _Size, _Locale ); }}
#line 470 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl _strupr_l(char * _String, _locale_t _Locale); 
#line 479 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
size_t __cdecl strxfrm(char * _Destination, const char * _Source, size_t _MaxCount); 
#line 487
size_t __cdecl _strxfrm_l(char * _Destination, const char * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 497
extern "C++" {
#line 500
inline char *__cdecl strchr(char *const _String, const int _Ch) 
#line 501
{ 
#line 502
return const_cast< char *>(strchr(static_cast< const char *>(_String), _Ch)); 
#line 503
} 
#line 506
inline char *__cdecl strpbrk(char *const _String, const char *const _Control) 
#line 507
{ 
#line 508
return const_cast< char *>(strpbrk(static_cast< const char *>(_String), _Control)); 
#line 509
} 
#line 512
inline char *__cdecl strrchr(char *const _String, const int _Ch) 
#line 513
{ 
#line 514
return const_cast< char *>(strrchr(static_cast< const char *>(_String), _Ch)); 
#line 515
} 
#line 518
inline char *__cdecl strstr(char *const _String, const char *const _SubString) 
#line 519
{ 
#line 520
return const_cast< char *>(strstr(static_cast< const char *>(_String), _SubString)); 
#line 521
} 
#line 522
}
#line 532 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
char *__cdecl strdup(const char * _String); 
#line 539
int __cdecl strcmpi(const char * _String1, const char * _String2); 
#line 545
int __cdecl stricmp(const char * _String1, const char * _String2); 
#line 551
char *__cdecl strlwr(char * _String); 
#line 556
int __cdecl strnicmp(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 563
char *__cdecl strnset(char * _String, int _Value, size_t _MaxCount); 
#line 570
char *__cdecl strrev(char * _String); 
#line 575
char *__cdecl strset(char * _String, int _Value); 
#line 580
char *__cdecl strupr(char * _String); 
#line 588 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\string.h"
}__pragma( pack ( pop )) 
#line 590
#pragma warning(pop)
#line 13 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 26
struct tm { 
#line 28
int tm_sec; 
#line 29
int tm_min; 
#line 30
int tm_hour; 
#line 31
int tm_mday; 
#line 32
int tm_mon; 
#line 33
int tm_year; 
#line 34
int tm_wday; 
#line 35
int tm_yday; 
#line 36
int tm_isdst; 
#line 37
}; 
#line 48
__wchar_t *__cdecl _wasctime(const tm * _Tm); 
#line 54
errno_t __cdecl _wasctime_s(__wchar_t * _Buffer, size_t _SizeInWords, const tm * _Tm); 
#line 60
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wasctime_s ( wchar_t ( & _Buffer ) [ _Size ], struct tm const * _Time ) throw ( ) { return _wasctime_s ( _Buffer, _Size, _Time ); }}
#line 69 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
size_t __cdecl wcsftime(__wchar_t * _Buffer, size_t _SizeInWords, const __wchar_t * _Format, const tm * _Tm); 
#line 78
size_t __cdecl _wcsftime_l(__wchar_t * _Buffer, size_t _SizeInWords, const __wchar_t * _Format, const tm * _Tm, _locale_t _Locale); 
#line 88
__wchar_t *__cdecl _wctime32(const __time32_t * _Time); 
#line 93
errno_t __cdecl _wctime32_s(__wchar_t * _Buffer, size_t _SizeInWords, const __time32_t * _Time); 
#line 99
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wctime32_s ( wchar_t ( & _Buffer ) [ _Size ], __time32_t const * _Time ) throw ( ) { return _wctime32_s ( _Buffer, _Size, _Time ); }}
#line 108 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
__wchar_t *__cdecl _wctime64(const __time64_t * _Time); 
#line 113
errno_t __cdecl _wctime64_s(__wchar_t * _Buffer, size_t _SizeInWords, const __time64_t * _Time); 
#line 118
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wctime64_s ( wchar_t ( & _Buffer ) [ _Size ], __time64_t const * _Time ) throw ( ) { return _wctime64_s ( _Buffer, _Size, _Time ); }}
#line 125 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
errno_t __cdecl _wstrdate_s(__wchar_t * _Buffer, size_t _SizeInWords); 
#line 130
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wstrdate_s ( wchar_t ( & _Buffer ) [ _Size ] ) throw ( ) { return _wstrdate_s ( _Buffer, _Size ); }}
#line 135 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
__wchar_t *__cdecl _wstrdate(__wchar_t * _Buffer); 
#line 141 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
errno_t __cdecl _wstrtime_s(__wchar_t * _Buffer, size_t _SizeInWords); 
#line 146
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wstrtime_s ( wchar_t ( & _Buffer ) [ _Size ] ) throw ( ) { return _wstrtime_s ( _Buffer, _Size ); }}
#line 151 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
__wchar_t *__cdecl _wstrtime(__wchar_t * _Buffer); 
#line 186 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
static __inline __wchar_t *__cdecl _wctime(const time_t *const 
#line 187
_Time) 
#line 188
{ 
#line 189
return _wctime64(_Time); 
#line 190
} 
#line 193
static __inline errno_t __cdecl _wctime_s(__wchar_t *const 
#line 194
_Buffer, const size_t 
#line 195
_SizeInWords, const time_t *const 
#line 196
_Time) 
#line 198
{ 
#line 199
return _wctime64_s(_Buffer, _SizeInWords, _Time); 
#line 200
} 
#line 205 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_wtime.h"
}__pragma( pack ( pop )) 
#line 207
#pragma warning(pop)
#line 15 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 19
__pragma( pack ( push, 8 )) extern "C" {
#line 30 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
typedef long clock_t; 
#line 32
struct _timespec32 { 
#line 34
__time32_t tv_sec; 
#line 35
long tv_nsec; 
#line 36
}; 
#line 38
struct _timespec64 { 
#line 40
__time64_t tv_sec; 
#line 41
long tv_nsec; 
#line 42
}; 
#line 45
struct timespec { 
#line 47
time_t tv_sec; 
#line 48
long tv_nsec; 
#line 49
}; 
#line 68 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
int *__cdecl __daylight(); 
#line 74
long *__cdecl __dstbias(); 
#line 80
long *__cdecl __timezone(); 
#line 86
char **__cdecl __tzname(); 
#line 91
errno_t __cdecl _get_daylight(int * _Daylight); 
#line 96
errno_t __cdecl _get_dstbias(long * _DaylightSavingsBias); 
#line 101
errno_t __cdecl _get_timezone(long * _TimeZone); 
#line 106
errno_t __cdecl _get_tzname(size_t * _ReturnValue, char * _Buffer, size_t _SizeInBytes, int _Index); 
#line 123
char *__cdecl asctime(const tm * _Tm); 
#line 130
errno_t __cdecl asctime_s(char * _Buffer, size_t _SizeInBytes, const tm * _Tm); 
#line 137 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl asctime_s ( char ( & _Buffer ) [ _Size ], struct tm const * _Time ) throw ( ) { return asctime_s ( _Buffer, _Size, _Time ); }}
#line 144 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
clock_t __cdecl clock(); 
#line 149
char *__cdecl _ctime32(const __time32_t * _Time); 
#line 154
errno_t __cdecl _ctime32_s(char * _Buffer, size_t _SizeInBytes, const __time32_t * _Time); 
#line 160
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ctime32_s ( char ( & _Buffer ) [ _Size ], __time32_t const * _Time ) throw ( ) { return _ctime32_s ( _Buffer, _Size, _Time ); }}
#line 169 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
char *__cdecl _ctime64(const __time64_t * _Time); 
#line 174
errno_t __cdecl _ctime64_s(char * _Buffer, size_t _SizeInBytes, const __time64_t * _Time); 
#line 180
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ctime64_s ( char ( & _Buffer ) [ _Size ], __time64_t const * _Time ) throw ( ) { return _ctime64_s ( _Buffer, _Size, _Time ); }}
#line 187 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
double __cdecl _difftime32(__time32_t _Time1, __time32_t _Time2); 
#line 193
double __cdecl _difftime64(__time64_t _Time1, __time64_t _Time2); 
#line 200
tm *__cdecl _gmtime32(const __time32_t * _Time); 
#line 205
errno_t __cdecl _gmtime32_s(tm * _Tm, const __time32_t * _Time); 
#line 212
tm *__cdecl _gmtime64(const __time64_t * _Time); 
#line 217
errno_t __cdecl _gmtime64_s(tm * _Tm, const __time64_t * _Time); 
#line 224
tm *__cdecl _localtime32(const __time32_t * _Time); 
#line 229
errno_t __cdecl _localtime32_s(tm * _Tm, const __time32_t * _Time); 
#line 236
tm *__cdecl _localtime64(const __time64_t * _Time); 
#line 241
errno_t __cdecl _localtime64_s(tm * _Tm, const __time64_t * _Time); 
#line 247
__time32_t __cdecl _mkgmtime32(tm * _Tm); 
#line 252
__time64_t __cdecl _mkgmtime64(tm * _Tm); 
#line 257
__time32_t __cdecl _mktime32(tm * _Tm); 
#line 262
__time64_t __cdecl _mktime64(tm * _Tm); 
#line 268
size_t __cdecl strftime(char * _Buffer, size_t _SizeInBytes, const char * _Format, const tm * _Tm); 
#line 277
size_t __cdecl _strftime_l(char * _Buffer, size_t _MaxSize, const char * _Format, const tm * _Tm, _locale_t _Locale); 
#line 286
errno_t __cdecl _strdate_s(char * _Buffer, size_t _SizeInBytes); 
#line 291
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strdate_s ( char ( & _Buffer ) [ _Size ] ) throw ( ) { return _strdate_s ( _Buffer, _Size ); }}
#line 296 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
char *__cdecl _strdate(char * _Buffer); 
#line 302 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
errno_t __cdecl _strtime_s(char * _Buffer, size_t _SizeInBytes); 
#line 307
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strtime_s ( char ( & _Buffer ) [ _Size ] ) throw ( ) { return _strtime_s ( _Buffer, _Size ); }}
#line 312 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
char *__cdecl _strtime(char * _Buffer); 
#line 317 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
__time32_t __cdecl _time32(__time32_t * _Time); 
#line 321
__time64_t __cdecl _time64(__time64_t * _Time); 
#line 327
int __cdecl _timespec32_get(_timespec32 * _Ts, int _Base); 
#line 334
int __cdecl _timespec64_get(_timespec64 * _Ts, int _Base); 
#line 348
void __cdecl _tzset(); 
#line 351
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using GetLocalTime in" "stead. See online help for details.")) unsigned __cdecl 
#line 352
_getsystime(tm * _Tm); 
#line 356
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetLocalTime in" "stead. See online help for details.")) unsigned __cdecl 
#line 357
_setsystime(tm * _Tm, unsigned _Milliseconds); 
#line 501 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
static __inline char *__cdecl ctime(const time_t *const 
#line 502
_Time) 
#line 504
{ 
#line 505
return _ctime64(_Time); 
#line 506
} 
#line 509
static __inline double __cdecl difftime(const time_t 
#line 510
_Time1, const time_t 
#line 511
_Time2) 
#line 513
{ 
#line 514
return _difftime64(_Time1, _Time2); 
#line 515
} 
#line 518
static __inline tm *__cdecl gmtime(const time_t *const 
#line 519
_Time) 
#line 520
{ 
#line 521
return _gmtime64(_Time); 
#line 522
} 
#line 525
static __inline tm *__cdecl localtime(const time_t *const 
#line 526
_Time) 
#line 528
{ 
#line 529
return _localtime64(_Time); 
#line 530
} 
#line 533
static __inline time_t __cdecl _mkgmtime(tm *const 
#line 534
_Tm) 
#line 536
{ 
#line 537
return _mkgmtime64(_Tm); 
#line 538
} 
#line 541
static __inline time_t __cdecl mktime(tm *const 
#line 542
_Tm) 
#line 544
{ 
#line 545
return _mktime64(_Tm); 
#line 546
} 
#line 548
static __inline time_t __cdecl time(time_t *const 
#line 549
_Time) 
#line 551
{ 
#line 552
return _time64(_Time); 
#line 553
} 
#line 556
static __inline int __cdecl timespec_get(timespec *const 
#line 557
_Ts, const int 
#line 558
_Base) 
#line 560
{ 
#line 561
return _timespec64_get((_timespec64 *)_Ts, _Base); 
#line 562
} 
#line 566
static __inline errno_t __cdecl ctime_s(char *const 
#line 567
_Buffer, const size_t 
#line 568
_SizeInBytes, const time_t *const 
#line 569
_Time) 
#line 571
{ 
#line 572
return _ctime64_s(_Buffer, _SizeInBytes, _Time); 
#line 573
} 
#line 603 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
static __inline errno_t __cdecl gmtime_s(tm *const 
#line 604
_Tm, const time_t *const 
#line 605
_Time) 
#line 607
{ 
#line 608
return _gmtime64_s(_Tm, _Time); 
#line 609
} 
#line 612
static __inline errno_t __cdecl localtime_s(tm *const 
#line 613
_Tm, const time_t *const 
#line 614
_Time) 
#line 616
{ 
#line 617
return _localtime64_s(_Tm, _Time); 
#line 618
} 
#line 638 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
void __cdecl tzset(); 
#line 645 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\time.h"
}__pragma( pack ( pop )) 
#line 647
#pragma warning(pop)
#line 88 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/common_functions.h"
extern "C" {
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/common_functions.h"
extern clock_t __cdecl clock(); 
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/common_functions.h"
extern void *__cdecl memset(void *, int, size_t); 
#line 97
extern void *__cdecl memcpy(void *, const void *, size_t); 
#line 99
}
#line 158 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern "C" {
#line 265 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __cdecl abs(int a); 
#line 276
extern long __cdecl labs(long a); 
#line 287
extern __int64 llabs(__int64 a); 
#line 315 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl fabs(double x); 
#line 338 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern __inline float fabsf(float x); 
#line 349 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline int min(const int a, const int b); 
#line 356
extern inline unsigned umin(const unsigned a, const unsigned b); 
#line 363
extern inline __int64 llmin(const __int64 a, const __int64 b); 
#line 370
extern inline unsigned __int64 ullmin(const unsigned __int64 a, const unsigned __int64 b); 
#line 393 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl fminf(float x, float y); 
#line 413 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl fmin(double x, double y); 
#line 424 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline int max(const int a, const int b); 
#line 432
extern inline unsigned umax(const unsigned a, const unsigned b); 
#line 439
extern inline __int64 llmax(const __int64 a, const __int64 b); 
#line 446
extern inline unsigned __int64 ullmax(const unsigned __int64 a, const unsigned __int64 b); 
#line 469 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl fmaxf(float x, float y); 
#line 489 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl fmax(double, double); 
#line 509 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl sin(double x); 
#line 527
extern double __cdecl cos(double x); 
#line 543 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern void sincos(double x, double * sptr, double * cptr); 
#line 556
extern void sincosf(float x, float * sptr, float * cptr); 
#line 579 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl tan(double x); 
#line 603
extern double __cdecl sqrt(double x); 
#line 629 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double rsqrt(double x); 
#line 653
extern float rsqrtf(float x); 
#line 682 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl log2(double x); 
#line 711 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl exp2(double x); 
#line 740 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl exp2f(float x); 
#line 769 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double exp10(double x); 
#line 796
extern float exp10f(float x); 
#line 832 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl expm1(double x); 
#line 865 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl expm1f(float x); 
#line 892 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl log2f(float x); 
#line 915 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl log10(double x); 
#line 941
extern double __cdecl log(double x); 
#line 970 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl log1p(double x); 
#line 1000 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl log1pf(float x); 
#line 1024 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl floor(double x); 
#line 1053
extern double __cdecl exp(double x); 
#line 1072
extern double __cdecl cosh(double x); 
#line 1092
extern double __cdecl sinh(double x); 
#line 1112
extern double __cdecl tanh(double x); 
#line 1138 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl acosh(double x); 
#line 1165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl acoshf(float x); 
#line 1189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl asinh(double x); 
#line 1213 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl asinhf(float x); 
#line 1238 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl atanh(double x); 
#line 1263 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl atanhf(float x); 
#line 1279 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl ldexp(double x, int exp); 
#line 1294
extern __inline float ldexpf(float x, int exp); 
#line 1317 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl logb(double x); 
#line 1341 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl logbf(float x); 
#line 1365 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __cdecl ilogb(double x); 
#line 1389 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __cdecl ilogbf(float x); 
#line 1417 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl scalbn(double x, int n); 
#line 1445 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl scalbnf(float x, int n); 
#line 1473 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl scalbln(double x, long n); 
#line 1501 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl scalblnf(float x, long n); 
#line 1531 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl frexp(double x, int * nptr); 
#line 1560
extern __inline float frexpf(float x, int * nptr); 
#line 1585 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl round(double x); 
#line 1611 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl roundf(float x); 
#line 1629 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern long __cdecl lround(double x); 
#line 1647 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern long __cdecl lroundf(float x); 
#line 1665 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llround(double x); 
#line 1683 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llroundf(float x); 
#line 1753 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl rintf(float x); 
#line 1770 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern long __cdecl lrint(double x); 
#line 1787 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern long __cdecl lrintf(float x); 
#line 1804 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llrint(double x); 
#line 1821 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llrintf(float x); 
#line 1845 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl nearbyint(double x); 
#line 1869 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl nearbyintf(float x); 
#line 1891 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl ceil(double x); 
#line 1916 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl trunc(double x); 
#line 1942 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl truncf(float x); 
#line 1964 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl fdim(double x, double y); 
#line 1985 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl fdimf(float x, float y); 
#line 2066 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl atan2(double y, double x); 
#line 2092
extern double __cdecl atan(double x); 
#line 2109
extern double __cdecl acos(double x); 
#line 2131
extern double __cdecl asin(double x); 
#line 2159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl hypot(double x, double y); 
#line 2217 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline float __cdecl hypotf(float x, float y); 
#line 2493 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl cbrt(double x); 
#line 2520 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl cbrtf(float x); 
#line 2544 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double rcbrt(double x); 
#line 2565
extern float rcbrtf(float x); 
#line 2594 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double sinpi(double x); 
#line 2617
extern float sinpif(float x); 
#line 2639
extern double cospi(double x); 
#line 2661
extern float cospif(float x); 
#line 2676
extern void sincospi(double x, double * sptr, double * cptr); 
#line 2689
extern void sincospif(float x, float * sptr, float * cptr); 
#line 2775 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl pow(double x, double y); 
#line 2799
extern double __cdecl modf(double x, double * iptr); 
#line 2826
extern double __cdecl fmod(double x, double y); 
#line 2858 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl remainder(double x, double y); 
#line 2891 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl remainderf(float x, float y); 
#line 2929 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl remquo(double x, double y, int * quo); 
#line 2967 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl remquof(float x, float y, int * quo); 
#line 2986 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl j0(double x); 
#line 3008 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float j0f(float x); 
#line 3035 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl j1(double x); 
#line 3062 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float j1f(float x); 
#line 3085 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl jn(int n, double x); 
#line 3108 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float jnf(int n, float x); 
#line 3135 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl y0(double x); 
#line 3162 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float y0f(float x); 
#line 3189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl y1(double x); 
#line 3216 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float y1f(float x); 
#line 3244 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl yn(int n, double x); 
#line 3272 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float ynf(int n, float x); 
#line 3370 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl erf(double x); 
#line 3395 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl erff(float x); 
#line 3423 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double erfinv(double x); 
#line 3446
extern float erfinvf(float x); 
#line 3472 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl erfc(double x); 
#line 3495 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl erfcf(float x); 
#line 3527 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl lgamma(double x); 
#line 3553 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double erfcinv(double x); 
#line 3574
extern float erfcinvf(float x); 
#line 3596
extern double normcdfinv(double x); 
#line 3618
extern float normcdfinvf(float x); 
#line 3637
extern double normcdf(double x); 
#line 3656
extern float normcdff(float x); 
#line 3676
extern double erfcx(double x); 
#line 3696
extern float erfcxf(float x); 
#line 3731 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl lgammaf(float x); 
#line 3760 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl tgamma(double x); 
#line 3789 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl tgammaf(float x); 
#line 3803 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl copysign(double x, double y); 
#line 3817 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl copysignf(float x, float y); 
#line 3836 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl nextafter(double x, double y); 
#line 3855 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl nextafterf(float x, float y); 
#line 3871 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl nan(const char * tagp); 
#line 3887 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl nanf(const char * tagp); 
#line 3892 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __isinff(float); 
#line 3893
extern int __isnanf(float); 
#line 3903 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __finite(double); 
#line 3904
extern int __finitef(float); 
#line 3905
extern int __signbit(double); 
#line 3906
extern int __isnan(double); 
#line 3907
extern int __isinf(double); 
#line 3910 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __signbitf(float); 
#line 3963 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern double __cdecl fma(double x, double y, double z); 
#line 4013 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl fmaf(float x, float y, float z); 
#line 4022 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __signbitl(long double); 
#line 4028 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern int __finitel(long double); 
#line 4029
extern int __isinfl(long double); 
#line 4030
extern int __isnanl(long double); 
#line 4034 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern float __cdecl acosf(float); 
#line 4035
extern float __cdecl asinf(float); 
#line 4036
extern float __cdecl atanf(float); 
#line 4037
extern float __cdecl atan2f(float, float); 
#line 4038
extern float __cdecl cosf(float); 
#line 4039
extern float __cdecl sinf(float); 
#line 4040
extern float __cdecl tanf(float); 
#line 4041
extern float __cdecl coshf(float); 
#line 4042
extern float __cdecl sinhf(float); 
#line 4043
extern float __cdecl tanhf(float); 
#line 4044
extern float __cdecl expf(float); 
#line 4045
extern float __cdecl logf(float); 
#line 4046
extern float __cdecl log10f(float); 
#line 4047
extern float __cdecl modff(float, float *); 
#line 4048
extern float __cdecl powf(float, float); 
#line 4049
extern float __cdecl sqrtf(float); 
#line 4050
extern float __cdecl ceilf(float); 
#line 4051
extern float __cdecl floorf(float); 
#line 4052
extern float __cdecl fmodf(float, float); 
#line 4614 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
}
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 23
struct _exception { 
#line 25
int type; 
#line 26
char *name; 
#line 27
double arg1; 
#line 28
double arg2; 
#line 29
double retval; 
#line 30
}; 
#line 37
struct _complex { 
#line 39
double x, y; 
#line 40
}; 
#line 59 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
typedef float float_t; 
#line 60
typedef double double_t; 
#line 78 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
extern const double _HUGE; 
#line 189 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
void __cdecl _fperrraise(int _Except); 
#line 191
short __cdecl _dclass(double _X); 
#line 192
short __cdecl _ldclass(long double _X); 
#line 193
short __cdecl _fdclass(float _X); 
#line 195
int __cdecl _dsign(double _X); 
#line 196
int __cdecl _ldsign(long double _X); 
#line 197
int __cdecl _fdsign(float _X); 
#line 199
int __cdecl _dpcomp(double _X, double _Y); 
#line 200
int __cdecl _ldpcomp(long double _X, long double _Y); 
#line 201
int __cdecl _fdpcomp(float _X, float _Y); 
#line 203
short __cdecl _dtest(double * _Px); 
#line 204
short __cdecl _ldtest(long double * _Px); 
#line 205
short __cdecl _fdtest(float * _Px); 
#line 207
short __cdecl _d_int(double * _Px, short _Xexp); 
#line 208
short __cdecl _ld_int(long double * _Px, short _Xexp); 
#line 209
short __cdecl _fd_int(float * _Px, short _Xexp); 
#line 211
short __cdecl _dscale(double * _Px, long _Lexp); 
#line 212
short __cdecl _ldscale(long double * _Px, long _Lexp); 
#line 213
short __cdecl _fdscale(float * _Px, long _Lexp); 
#line 215
short __cdecl _dunscale(short * _Pex, double * _Px); 
#line 216
short __cdecl _ldunscale(short * _Pex, long double * _Px); 
#line 217
short __cdecl _fdunscale(short * _Pex, float * _Px); 
#line 219
short __cdecl _dexp(double * _Px, double _Y, long _Eoff); 
#line 220
short __cdecl _ldexp(long double * _Px, long double _Y, long _Eoff); 
#line 221
short __cdecl _fdexp(float * _Px, float _Y, long _Eoff); 
#line 223
short __cdecl _dnorm(unsigned short * _Ps); 
#line 224
short __cdecl _fdnorm(unsigned short * _Ps); 
#line 226
double __cdecl _dpoly(double _X, const double * _Tab, int _N); 
#line 227
long double __cdecl _ldpoly(long double _X, const long double * _Tab, int _N); 
#line 228
float __cdecl _fdpoly(float _X, const float * _Tab, int _N); 
#line 230
double __cdecl _dlog(double _X, int _Baseflag); 
#line 231
long double __cdecl _ldlog(long double _X, int _Baseflag); 
#line 232
float __cdecl _fdlog(float _X, int _Baseflag); 
#line 234
double __cdecl _dsin(double _X, unsigned _Qoff); 
#line 235
long double __cdecl _ldsin(long double _X, unsigned _Qoff); 
#line 236
float __cdecl _fdsin(float _X, unsigned _Qoff); 
#line 243
typedef 
#line 240
union { 
#line 241
unsigned short _Sh[4]; 
#line 242
double _Val; 
#line 243
} _double_val; 
#line 250
typedef 
#line 247
union { 
#line 248
unsigned short _Sh[2]; 
#line 249
float _Val; 
#line 250
} _float_val; 
#line 257
typedef 
#line 254
union { 
#line 255
unsigned short _Sh[4]; 
#line 256
long double _Val; 
#line 257
} _ldouble_val; 
#line 265
typedef 
#line 260
union { 
#line 261
unsigned short _Word[4]; 
#line 262
float _Float; 
#line 263
double _Double; 
#line 264
long double _Long_double; 
#line 265
} _float_const; 
#line 267
extern const _float_const _Denorm_C, _Inf_C, _Nan_C, _Snan_C, _Hugeval_C; 
#line 268
extern const _float_const _FDenorm_C, _FInf_C, _FNan_C, _FSnan_C; 
#line 269
extern const _float_const _LDenorm_C, _LInf_C, _LNan_C, _LSnan_C; 
#line 271
extern const _float_const _Eps_C, _Rteps_C; 
#line 272
extern const _float_const _FEps_C, _FRteps_C; 
#line 273
extern const _float_const _LEps_C, _LRteps_C; 
#line 275
extern const double _Zero_C, _Xbig_C; 
#line 276
extern const float _FZero_C, _FXbig_C; 
#line 277
extern const long double _LZero_C, _LXbig_C; 
#line 310
extern "C++" {
#line 312
inline int fpclassify(float _X) throw() 
#line 313
{ 
#line 317 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
return _fdtest(&_X); 
#line 319 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
} 
#line 321
inline int fpclassify(double _X) throw() 
#line 322
{ 
#line 326 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
return _dtest(&_X); 
#line 328 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
} 
#line 330
inline int fpclassify(long double _X) throw() 
#line 331
{ 
#line 335 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
return _ldtest(&_X); 
#line 337 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
} 
#line 339
inline bool signbit(float _X) throw() 
#line 340
{ 
#line 341
return _fdsign(_X) != 0; 
#line 342
} 
#line 344
inline bool signbit(double _X) throw() 
#line 345
{ 
#line 346
return _dsign(_X) != 0; 
#line 347
} 
#line 349
inline bool signbit(long double _X) throw() 
#line 350
{ 
#line 351
return _ldsign(_X) != 0; 
#line 352
} 
#line 354
inline int _fpcomp(float _X, float _Y) throw() 
#line 355
{ 
#line 356
return _fdpcomp(_X, _Y); 
#line 357
} 
#line 359
inline int _fpcomp(double _X, double _Y) throw() 
#line 360
{ 
#line 361
return _dpcomp(_X, _Y); 
#line 362
} 
#line 364
inline int _fpcomp(long double _X, long double _Y) throw() 
#line 365
{ 
#line 366
return _ldpcomp(_X, _Y); 
#line 367
} 
#line 369
template< class _Trc, class _Tre> struct _Combined_type { 
#line 371
typedef float _Type; 
#line 372
}; 
#line 374
template<> struct _Combined_type< float, double>  { 
#line 376
typedef double _Type; 
#line 377
}; 
#line 379
template<> struct _Combined_type< float, long double>  { 
#line 381
typedef long double _Type; 
#line 382
}; 
#line 384
template< class _Ty, class _T2> struct _Real_widened { 
#line 386
typedef long double _Type; 
#line 387
}; 
#line 389
template<> struct _Real_widened< float, float>  { 
#line 391
typedef float _Type; 
#line 392
}; 
#line 394
template<> struct _Real_widened< float, double>  { 
#line 396
typedef double _Type; 
#line 397
}; 
#line 399
template<> struct _Real_widened< double, float>  { 
#line 401
typedef double _Type; 
#line 402
}; 
#line 404
template<> struct _Real_widened< double, double>  { 
#line 406
typedef double _Type; 
#line 407
}; 
#line 409
template< class _Ty> struct _Real_type { 
#line 411
typedef double _Type; 
#line 412
}; 
#line 414
template<> struct _Real_type< float>  { 
#line 416
typedef float _Type; 
#line 417
}; 
#line 419
template<> struct _Real_type< long double>  { 
#line 421
typedef long double _Type; 
#line 422
}; 
#line 424
template < class _T1, class _T2 >
      inline int _fpcomp ( _T1 _X, _T2 _Y ) throw ( )
    {
        typedef typename _Combined_type < float,
            typename _Real_widened <
            typename _Real_type < _T1 > :: _Type,
            typename _Real_type < _T2 > :: _Type > :: _Type > :: _Type _Tw;
        return _fpcomp ( ( _Tw ) _X, ( _Tw ) _Y );
    }
#line 434
template < class _Ty >
      inline bool isfinite ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) <= 0;
    }
#line 440
template < class _Ty >
      inline bool isinf ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) == 1;
    }
#line 446
template < class _Ty >
      inline bool isnan ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) == 2;
    }
#line 452
template < class _Ty >
      inline bool isnormal ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) == ( - 1 );
    }
#line 458
template < class _Ty1, class _Ty2 >
      inline bool isgreater ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & 4 ) != 0;
    }
#line 464
template < class _Ty1, class _Ty2 >
      inline bool isgreaterequal ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & ( 2 | 4 ) ) != 0;
    }
#line 470
template < class _Ty1, class _Ty2 >
      inline bool isless ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & 1 ) != 0;
    }
#line 476
template < class _Ty1, class _Ty2 >
      inline bool islessequal ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & ( 1 | 2 ) ) != 0;
    }
#line 482
template < class _Ty1, class _Ty2 >
      inline bool islessgreater ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & ( 1 | 4 ) ) != 0;
    }
#line 488
template < class _Ty1, class _Ty2 >
      inline bool isunordered ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return _fpcomp ( _X, _Y ) == 0;
    }
#line 493
}
#line 500 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
int __cdecl abs(int _X); 
#line 501
long __cdecl labs(long _X); 
#line 502
__int64 __cdecl llabs(__int64 _X); 
#line 504
double __cdecl acos(double _X); 
#line 505
double __cdecl asin(double _X); 
#line 506
double __cdecl atan(double _X); 
#line 507
double __cdecl atan2(double _Y, double _X); 
#line 509
double __cdecl cos(double _X); 
#line 510
double __cdecl cosh(double _X); 
#line 511
double __cdecl exp(double _X); 
#line 512
double __cdecl fabs(double _X); 
#line 513
double __cdecl fmod(double _X, double _Y); 
#line 514
double __cdecl log(double _X); 
#line 515
double __cdecl log10(double _X); 
#line 516
double __cdecl pow(double _X, double _Y); 
#line 517
double __cdecl sin(double _X); 
#line 518
double __cdecl sinh(double _X); 
#line 519
double __cdecl sqrt(double _X); 
#line 520
double __cdecl tan(double _X); 
#line 521
double __cdecl tanh(double _X); 
#line 523
double __cdecl acosh(double _X); 
#line 524
double __cdecl asinh(double _X); 
#line 525
double __cdecl atanh(double _X); 
#line 526
double __cdecl atof(const char * _String); 
#line 527
double __cdecl _atof_l(const char * _String, _locale_t _Locale); 
#line 528
double __cdecl _cabs(_complex _Complex_value); 
#line 529
double __cdecl cbrt(double _X); 
#line 530
double __cdecl ceil(double _X); 
#line 531
double __cdecl _chgsign(double _X); 
#line 532
double __cdecl copysign(double _Number, double _Sign); 
#line 533
double __cdecl _copysign(double _Number, double _Sign); 
#line 534
double __cdecl erf(double _X); 
#line 535
double __cdecl erfc(double _X); 
#line 536
double __cdecl exp2(double _X); 
#line 537
double __cdecl expm1(double _X); 
#line 538
double __cdecl fdim(double _X, double _Y); 
#line 539
double __cdecl floor(double _X); 
#line 540
double __cdecl fma(double _X, double _Y, double _Z); 
#line 541
double __cdecl fmax(double _X, double _Y); 
#line 542
double __cdecl fmin(double _X, double _Y); 
#line 543
double __cdecl frexp(double _X, int * _Y); 
#line 544
double __cdecl hypot(double _X, double _Y); 
#line 545
double __cdecl _hypot(double _X, double _Y); 
#line 546
int __cdecl ilogb(double _X); 
#line 547
double __cdecl ldexp(double _X, int _Y); 
#line 548
double __cdecl lgamma(double _X); 
#line 549
__int64 __cdecl llrint(double _X); 
#line 550
__int64 __cdecl llround(double _X); 
#line 551
double __cdecl log1p(double _X); 
#line 552
double __cdecl log2(double _X); 
#line 553
double __cdecl logb(double _X); 
#line 554
long __cdecl lrint(double _X); 
#line 555
long __cdecl lround(double _X); 
#line 557
int __cdecl _matherr(_exception * _Except); 
#line 559
double __cdecl modf(double _X, double * _Y); 
#line 560
double __cdecl nan(const char * _X); 
#line 561
double __cdecl nearbyint(double _X); 
#line 562
double __cdecl nextafter(double _X, double _Y); 
#line 563
double __cdecl nexttoward(double _X, long double _Y); 
#line 564
double __cdecl remainder(double _X, double _Y); 
#line 565
double __cdecl remquo(double _X, double _Y, int * _Z); 
#line 566
double __cdecl rint(double _X); 
#line 567
double __cdecl round(double _X); 
#line 568
double __cdecl scalbln(double _X, long _Y); 
#line 569
double __cdecl scalbn(double _X, int _Y); 
#line 570
double __cdecl tgamma(double _X); 
#line 571
double __cdecl trunc(double _X); 
#line 572
double __cdecl _j0(double _X); 
#line 573
double __cdecl _j1(double _X); 
#line 574
double __cdecl _jn(int _X, double _Y); 
#line 575
double __cdecl _y0(double _X); 
#line 576
double __cdecl _y1(double _X); 
#line 577
double __cdecl _yn(int _X, double _Y); 
#line 579
float __cdecl acoshf(float _X); 
#line 580
float __cdecl asinhf(float _X); 
#line 581
float __cdecl atanhf(float _X); 
#line 582
float __cdecl cbrtf(float _X); 
#line 583
float __cdecl _chgsignf(float _X); 
#line 584
float __cdecl copysignf(float _Number, float _Sign); 
#line 585
float __cdecl _copysignf(float _Number, float _Sign); 
#line 586
float __cdecl erff(float _X); 
#line 587
float __cdecl erfcf(float _X); 
#line 588
float __cdecl expm1f(float _X); 
#line 589
float __cdecl exp2f(float _X); 
#line 590
float __cdecl fdimf(float _X, float _Y); 
#line 591
float __cdecl fmaf(float _X, float _Y, float _Z); 
#line 592
float __cdecl fmaxf(float _X, float _Y); 
#line 593
float __cdecl fminf(float _X, float _Y); 
#line 594
float __cdecl _hypotf(float _X, float _Y); 
#line 595
int __cdecl ilogbf(float _X); 
#line 596
float __cdecl lgammaf(float _X); 
#line 597
__int64 __cdecl llrintf(float _X); 
#line 598
__int64 __cdecl llroundf(float _X); 
#line 599
float __cdecl log1pf(float _X); 
#line 600
float __cdecl log2f(float _X); 
#line 601
float __cdecl logbf(float _X); 
#line 602
long __cdecl lrintf(float _X); 
#line 603
long __cdecl lroundf(float _X); 
#line 604
float __cdecl nanf(const char * _X); 
#line 605
float __cdecl nearbyintf(float _X); 
#line 606
float __cdecl nextafterf(float _X, float _Y); 
#line 607
float __cdecl nexttowardf(float _X, long double _Y); 
#line 608
float __cdecl remainderf(float _X, float _Y); 
#line 609
float __cdecl remquof(float _X, float _Y, int * _Z); 
#line 610
float __cdecl rintf(float _X); 
#line 611
float __cdecl roundf(float _X); 
#line 612
float __cdecl scalblnf(float _X, long _Y); 
#line 613
float __cdecl scalbnf(float _X, int _Y); 
#line 614
float __cdecl tgammaf(float _X); 
#line 615
float __cdecl truncf(float _X); 
#line 625 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
float __cdecl _logbf(float _X); 
#line 626
float __cdecl _nextafterf(float _X, float _Y); 
#line 627
int __cdecl _finitef(float _X); 
#line 628
int __cdecl _isnanf(float _X); 
#line 629
int __cdecl _fpclassf(float _X); 
#line 631
int __cdecl _set_FMA3_enable(int _Flag); 
#line 632
int __cdecl _get_FMA3_enable(); 
#line 645 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
float __cdecl acosf(float _X); 
#line 646
float __cdecl asinf(float _X); 
#line 647
float __cdecl atan2f(float _Y, float _X); 
#line 648
float __cdecl atanf(float _X); 
#line 649
float __cdecl ceilf(float _X); 
#line 650
float __cdecl cosf(float _X); 
#line 651
float __cdecl coshf(float _X); 
#line 652
float __cdecl expf(float _X); 
#line 709 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
__inline float __cdecl fabsf(float _X) 
#line 710
{ 
#line 711
return (float)fabs(_X); 
#line 712
} 
#line 718 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
float __cdecl floorf(float _X); 
#line 719
float __cdecl fmodf(float _X, float _Y); 
#line 735 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
__inline float __cdecl frexpf(float _X, int *_Y) 
#line 736
{ 
#line 737
return (float)frexp(_X, _Y); 
#line 738
} 
#line 740
__inline float __cdecl hypotf(float _X, float _Y) 
#line 741
{ 
#line 742
return _hypotf(_X, _Y); 
#line 743
} 
#line 745
__inline float __cdecl ldexpf(float _X, int _Y) 
#line 746
{ 
#line 747
return (float)ldexp(_X, _Y); 
#line 748
} 
#line 752
float __cdecl log10f(float _X); 
#line 753
float __cdecl logf(float _X); 
#line 754
float __cdecl modff(float _X, float * _Y); 
#line 755
float __cdecl powf(float _X, float _Y); 
#line 756
float __cdecl sinf(float _X); 
#line 757
float __cdecl sinhf(float _X); 
#line 758
float __cdecl sqrtf(float _X); 
#line 759
float __cdecl tanf(float _X); 
#line 760
float __cdecl tanhf(float _X); 
#line 814 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
long double __cdecl acoshl(long double _X); 
#line 816
__inline long double __cdecl acosl(long double _X) 
#line 817
{ 
#line 818
return acos((double)_X); 
#line 819
} 
#line 821
long double __cdecl asinhl(long double _X); 
#line 823
__inline long double __cdecl asinl(long double _X) 
#line 824
{ 
#line 825
return asin((double)_X); 
#line 826
} 
#line 828
__inline long double __cdecl atan2l(long double _Y, long double _X) 
#line 829
{ 
#line 830
return atan2((double)_Y, (double)_X); 
#line 831
} 
#line 833
long double __cdecl atanhl(long double _X); 
#line 835
__inline long double __cdecl atanl(long double _X) 
#line 836
{ 
#line 837
return atan((double)_X); 
#line 838
} 
#line 840
long double __cdecl cbrtl(long double _X); 
#line 842
__inline long double __cdecl ceill(long double _X) 
#line 843
{ 
#line 844
return ceil((double)_X); 
#line 845
} 
#line 847
__inline long double __cdecl _chgsignl(long double _X) 
#line 848
{ 
#line 849
return _chgsign((double)_X); 
#line 850
} 
#line 852
long double __cdecl copysignl(long double _Number, long double _Sign); 
#line 854
__inline long double __cdecl _copysignl(long double _Number, long double _Sign) 
#line 855
{ 
#line 856
return _copysign((double)_Number, (double)_Sign); 
#line 857
} 
#line 859
__inline long double __cdecl coshl(long double _X) 
#line 860
{ 
#line 861
return cosh((double)_X); 
#line 862
} 
#line 864
__inline long double __cdecl cosl(long double _X) 
#line 865
{ 
#line 866
return cos((double)_X); 
#line 867
} 
#line 869
long double __cdecl erfl(long double _X); 
#line 870
long double __cdecl erfcl(long double _X); 
#line 872
__inline long double __cdecl expl(long double _X) 
#line 873
{ 
#line 874
return exp((double)_X); 
#line 875
} 
#line 877
long double __cdecl exp2l(long double _X); 
#line 878
long double __cdecl expm1l(long double _X); 
#line 880
__inline long double __cdecl fabsl(long double _X) 
#line 881
{ 
#line 882
return fabs((double)_X); 
#line 883
} 
#line 885
long double __cdecl fdiml(long double _X, long double _Y); 
#line 887
__inline long double __cdecl floorl(long double _X) 
#line 888
{ 
#line 889
return floor((double)_X); 
#line 890
} 
#line 892
long double __cdecl fmal(long double _X, long double _Y, long double _Z); 
#line 893
long double __cdecl fmaxl(long double _X, long double _Y); 
#line 894
long double __cdecl fminl(long double _X, long double _Y); 
#line 896
__inline long double __cdecl fmodl(long double _X, long double _Y) 
#line 897
{ 
#line 898
return fmod((double)_X, (double)_Y); 
#line 899
} 
#line 901
__inline long double __cdecl frexpl(long double _X, int *_Y) 
#line 902
{ 
#line 903
return frexp((double)_X, _Y); 
#line 904
} 
#line 906
int __cdecl ilogbl(long double _X); 
#line 908
__inline long double __cdecl _hypotl(long double _X, long double _Y) 
#line 909
{ 
#line 910
return _hypot((double)_X, (double)_Y); 
#line 911
} 
#line 913
__inline long double __cdecl hypotl(long double _X, long double _Y) 
#line 914
{ 
#line 915
return _hypot((double)_X, (double)_Y); 
#line 916
} 
#line 918
__inline long double __cdecl ldexpl(long double _X, int _Y) 
#line 919
{ 
#line 920
return ldexp((double)_X, _Y); 
#line 921
} 
#line 923
long double __cdecl lgammal(long double _X); 
#line 924
__int64 __cdecl llrintl(long double _X); 
#line 925
__int64 __cdecl llroundl(long double _X); 
#line 927
__inline long double __cdecl logl(long double _X) 
#line 928
{ 
#line 929
return log((double)_X); 
#line 930
} 
#line 932
__inline long double __cdecl log10l(long double _X) 
#line 933
{ 
#line 934
return log10((double)_X); 
#line 935
} 
#line 937
long double __cdecl log1pl(long double _X); 
#line 938
long double __cdecl log2l(long double _X); 
#line 939
long double __cdecl logbl(long double _X); 
#line 940
long __cdecl lrintl(long double _X); 
#line 941
long __cdecl lroundl(long double _X); 
#line 943
__inline long double __cdecl modfl(long double _X, long double *_Y) 
#line 944
{ 
#line 945
double _F, _I; 
#line 946
_F = modf((double)_X, &_I); 
#line 947
(*_Y) = _I; 
#line 948
return _F; 
#line 949
} 
#line 951
long double __cdecl nanl(const char * _X); 
#line 952
long double __cdecl nearbyintl(long double _X); 
#line 953
long double __cdecl nextafterl(long double _X, long double _Y); 
#line 954
long double __cdecl nexttowardl(long double _X, long double _Y); 
#line 956
__inline long double __cdecl powl(long double _X, long double _Y) 
#line 957
{ 
#line 958
return pow((double)_X, (double)_Y); 
#line 959
} 
#line 961
long double __cdecl remainderl(long double _X, long double _Y); 
#line 962
long double __cdecl remquol(long double _X, long double _Y, int * _Z); 
#line 963
long double __cdecl rintl(long double _X); 
#line 964
long double __cdecl roundl(long double _X); 
#line 965
long double __cdecl scalblnl(long double _X, long _Y); 
#line 966
long double __cdecl scalbnl(long double _X, int _Y); 
#line 968
__inline long double __cdecl sinhl(long double _X) 
#line 969
{ 
#line 970
return sinh((double)_X); 
#line 971
} 
#line 973
__inline long double __cdecl sinl(long double _X) 
#line 974
{ 
#line 975
return sin((double)_X); 
#line 976
} 
#line 978
__inline long double __cdecl sqrtl(long double _X) 
#line 979
{ 
#line 980
return sqrt((double)_X); 
#line 981
} 
#line 983
__inline long double __cdecl tanhl(long double _X) 
#line 984
{ 
#line 985
return tanh((double)_X); 
#line 986
} 
#line 988
__inline long double __cdecl tanl(long double _X) 
#line 989
{ 
#line 990
return tan((double)_X); 
#line 991
} 
#line 993
long double __cdecl tgammal(long double _X); 
#line 994
long double __cdecl truncl(long double _X); 
#line 1015 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
extern double HUGE; 
#line 1020 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
double __cdecl j0(double _X); 
#line 1021
double __cdecl j1(double _X); 
#line 1022
double __cdecl jn(int _X, double _Y); 
#line 1023
double __cdecl y0(double _X); 
#line 1024
double __cdecl y1(double _X); 
#line 1025
double __cdecl yn(int _X, double _Y); 
#line 1030 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\corecrt_math.h"
}__pragma( pack ( pop )) 
#line 1032
#pragma warning(pop)
#line 12 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#pragma warning(disable: 4985)
#line 17
extern "C++" {
#line 19
#pragma pack ( push, 8 )
#line 33
namespace std { 
#line 35
struct nothrow_t { 
#line 36
explicit nothrow_t() = default;
#line 37
}; 
#line 39
extern const nothrow_t nothrow; 
#line 40
}
#line 43 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new.h"
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 44
operator new(size_t _Size); 
#line 48
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 49
operator new(size_t _Size, const std::nothrow_t &) noexcept; 
#line 54
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 55
operator new[](size_t _Size); 
#line 59
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 60
operator new[](size_t _Size, const std::nothrow_t &) noexcept; 
#line 65
void __cdecl operator delete(void * _Block) noexcept; 
#line 69
void __cdecl operator delete(void * _Block, const std::nothrow_t &) noexcept; 
#line 74
void __cdecl operator delete[](void * _Block) noexcept; 
#line 78
void __cdecl operator delete[](void * _Block, const std::nothrow_t &) noexcept; 
#line 83
void __cdecl operator delete(void * _Block, size_t _Size) noexcept; 
#line 88
void __cdecl operator delete[](void * _Block, size_t _Size) noexcept; 
#line 156
#pragma warning(push)
#pragma warning(disable: 4577)
#pragma warning(disable: 4514)
#line 161
[[nodiscard]] [[msvc::constexpr]] inline void *__cdecl 
#line 162
operator new(size_t _Size, void *
#line 163
_Where) noexcept 
#line 164
{ 
#line 165
(void)_Size; 
#line 166
return _Where; 
#line 167
} 
#line 169
inline void __cdecl operator delete(void *, void *) noexcept 
#line 170
{ 
#line 172
} 
#line 177 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new.h"
[[nodiscard]] inline void *__cdecl 
#line 178
operator new[](size_t _Size, void *
#line 179
_Where) noexcept 
#line 180
{ 
#line 181
(void)_Size; 
#line 182
return _Where; 
#line 183
} 
#line 185
inline void __cdecl operator delete[](void *, void *) noexcept 
#line 186
{ 
#line 187
} 
#line 195 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new.h"
}
#line 189
#pragma warning(pop)
#line 193
#pragma pack ( pop )
#line 198 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new.h"
#pragma warning(pop)
#line 12 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new_debug.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 16
extern "C++" {
#line 18
#pragma pack ( push, 8 )
#line 25
[[nodiscard]] 
#line 26
__declspec(allocator) void *__cdecl operator new(size_t _Size, int _BlockUse, const char * _FileName, int _LineNumber); 
#line 33
[[nodiscard]] 
#line 34
__declspec(allocator) void *__cdecl operator new[](size_t _Size, int _BlockUse, const char * _FileName, int _LineNumber); 
#line 41
void __cdecl operator delete(void * _Block, int _BlockUse, const char * _FileName, int _LineNumber) noexcept; 
#line 48
void __cdecl operator delete[](void * _Block, int _BlockUse, const char * _FileName, int _LineNumber) noexcept; 
#line 61 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new_debug.h"
}
#line 59
#pragma pack ( pop )
#line 64 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime_new_debug.h"
#pragma warning(pop)
#line 15 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\crtdbg.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 19
__pragma( pack ( push, 8 )) extern "C" {
#line 23
typedef void *_HFILE; 
#line 49
typedef int (__cdecl *_CRT_REPORT_HOOK)(int, char *, int *); 
#line 50
typedef int (__cdecl *_CRT_REPORT_HOOKW)(int, __wchar_t *, int *); 
#line 56
typedef int (__cdecl *_CRT_ALLOC_HOOK)(int, void *, size_t, int, long, const unsigned char *, int); 
#line 112
typedef void (__cdecl *_CRT_DUMP_CLIENT)(void *, size_t); 
#line 118
struct _CrtMemBlockHeader; 
#line 127
typedef 
#line 120
struct _CrtMemState { 
#line 122
_CrtMemBlockHeader *pBlockHeader; 
#line 123
size_t lCounts[5]; 
#line 124
size_t lSizes[5]; 
#line 125
size_t lHighWaterCount; 
#line 126
size_t lTotalCount; 
#line 127
} _CrtMemState; 
#line 813 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.26100.0\\ucrt\\crtdbg.h"
}__pragma( pack ( pop )) 
#line 815
#pragma warning(pop)
#line 23 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\yvals.h"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 141 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\yvals.h"
#pragma detect_mismatch("_MSC_VER", "1900")
#line 145 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\yvals.h"
#pragma detect_mismatch("_ITERATOR_DEBUG_LEVEL", "0")
#line 150 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\yvals.h"
#pragma detect_mismatch("RuntimeLibrary", "MT_StaticRelease")
#line 46 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\use_ansi.h"
#pragma comment(lib, "libcpmt")
#line 361 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\yvals.h"
namespace std { 
#line 362
enum _Uninitialized { 
#line 363
_Noinit
#line 364
}; 
#line 366
class _Lockit { 
#line 381
public: __thiscall _Lockit() noexcept; 
#line 382
explicit __thiscall _Lockit(int) noexcept; 
#line 383
__thiscall ~_Lockit() noexcept; 
#line 386 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\yvals.h"
static void __cdecl _Lockit_ctor(int) noexcept; 
#line 387
static void __cdecl _Lockit_dtor(int) noexcept; 
#line 390
private: static void __cdecl _Lockit_ctor(_Lockit *) noexcept; 
#line 391
static void __cdecl _Lockit_ctor(_Lockit *, int) noexcept; 
#line 392
static void __cdecl _Lockit_dtor(_Lockit *) noexcept; 
#line 395
public: _Lockit(const _Lockit &) = delete;
#line 396
_Lockit &operator=(const _Lockit &) = delete;
#line 399
private: int _Locktype; 
#line 400
}; 
#line 502 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\yvals.h"
}
#line 506
#pragma warning(pop)
#pragma pack ( pop )
#line 14 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cstdlib"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 23
[[nodiscard]] inline double abs(double _Xx) noexcept { 
#line 24
return ::fabs(_Xx); 
#line 25
} 
#line 27
[[nodiscard]] inline float abs(float _Xx) noexcept { 
#line 28
return ::fabsf(_Xx); 
#line 29
} 
#line 31
[[nodiscard]] inline long double abs(long double _Xx) noexcept { 
#line 32
return ::fabsl(_Xx); 
#line 33
} 
#line 36
namespace std { 
#line 37
using ::size_t;
#line 38
using ::div_t;
#line 39
using ::ldiv_t;
#line 40
using ::abort;
#line 41
using ::abs;
#line 42
using ::atexit;
#line 43
using ::atof;
#line 44
using ::atoi;
#line 45
using ::atol;
#line 46
using ::bsearch;
#line 47
using ::calloc;
#line 48
using ::div;
#line 49
using ::exit;
#line 50
using ::free;
#line 51
using ::labs;
#line 52
using ::ldiv;
#line 53
using ::malloc;
#line 54
using ::mblen;
#line 55
using ::mbstowcs;
#line 56
using ::mbtowc;
#line 57
using ::qsort;
#line 58
using ::rand;
#line 59
using ::realloc;
#line 60
using ::srand;
#line 61
using ::strtod;
#line 62
using ::strtol;
#line 63
using ::strtoul;
#line 64
using ::wcstombs;
#line 65
using ::wctomb;
#line 67
using ::lldiv_t;
#line 69
using ::getenv;
#line 70
using ::system;
#line 72
using ::atoll;
#line 73
using ::llabs;
#line 74
using ::lldiv;
#line 75
using ::strtof;
#line 76
using ::strtold;
#line 77
using ::strtoll;
#line 78
using ::strtoull;
#line 80
using ::_Exit;
#line 81
using ::at_quick_exit;
#line 82
using ::quick_exit;
#line 83
}
#line 87
#pragma warning(pop)
#pragma pack ( pop )
#line 11 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\xtr1common"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 24
namespace std { 
#line 25
template < class _Ty, _Ty _Val >
struct integral_constant {
    static constexpr _Ty value = _Val;

    using value_type = _Ty;
    using type = integral_constant;

    constexpr operator value_type ( ) const noexcept {
        return value;
    }

    [ [ nodiscard ] ] constexpr value_type operator ( ) ( ) const noexcept {
        return value;
    }
};
#line 41
template< bool _Val> using bool_constant = integral_constant< bool, _Val> ; 
#line 44
using true_type = bool_constant< true> ; 
#line 45
using false_type = bool_constant< false> ; 
#line 47
template< bool _Test, class _Ty = void> 
#line 48
struct enable_if { }; 
#line 50
template< class _Ty> 
#line 51
struct enable_if< true, _Ty>  { 
#line 52
using type = _Ty; 
#line 53
}; 
#line 55
template< bool _Test, class _Ty = void> using enable_if_t = typename enable_if< _Test, _Ty> ::type; 
#line 58
template< bool _Test, class _Ty1, class _Ty2> 
#line 59
struct conditional { 
#line 60
using type = _Ty1; 
#line 61
}; 
#line 63
template< class _Ty1, class _Ty2> 
#line 64
struct conditional< false, _Ty1, _Ty2>  { 
#line 65
using type = _Ty2; 
#line 66
}; 
#line 68
template< bool _Test, class _Ty1, class _Ty2> using conditional_t = typename conditional< _Test, _Ty1, _Ty2> ::type; 
#line 78
template< class , class > constexpr bool 
#line 79
is_same_v = false; 
#line 80
template< class _Ty> constexpr bool 
#line 81
is_same_v< _Ty, _Ty>  = true; 
#line 83
template< class _Ty1, class _Ty2> 
#line 84
struct is_same : public bool_constant< is_same_v< _Ty1, _Ty2> >  { }; 
#line 87 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\xtr1common"
template< class _Ty> 
#line 88
struct remove_const { 
#line 89
using type = _Ty; 
#line 90
}; 
#line 92
template< class _Ty> 
#line 93
struct remove_const< const _Ty>  { 
#line 94
using type = _Ty; 
#line 95
}; 
#line 97
template< class _Ty> using remove_const_t = typename remove_const< _Ty> ::type; 
#line 100
template< class _Ty> 
#line 101
struct remove_volatile { 
#line 102
using type = _Ty; 
#line 103
}; 
#line 105
template< class _Ty> 
#line 106
struct remove_volatile< volatile _Ty>  { 
#line 107
using type = _Ty; 
#line 108
}; 
#line 110
template< class _Ty> using remove_volatile_t = typename remove_volatile< _Ty> ::type; 
#line 113
template< class _Ty> 
#line 114
struct remove_cv { 
#line 115
using type = _Ty; 
#line 117
template< template< class >  class _Fn> using _Apply = _Fn< _Ty> ; 
#line 119
}; 
#line 121
template< class _Ty> 
#line 122
struct remove_cv< const _Ty>  { 
#line 123
using type = _Ty; 
#line 125
template< template< class >  class _Fn> using _Apply = const _Fn< _Ty> ; 
#line 127
}; 
#line 129
template< class _Ty> 
#line 130
struct remove_cv< volatile _Ty>  { 
#line 131
using type = _Ty; 
#line 133
template< template< class >  class _Fn> using _Apply = volatile _Fn< _Ty> ; 
#line 135
}; 
#line 137
template< class _Ty> 
#line 138
struct remove_cv< const volatile _Ty>  { 
#line 139
using type = _Ty; 
#line 141
template< template< class >  class _Fn> using _Apply = const volatile _Fn< _Ty> ; 
#line 143
}; 
#line 145
template< class _Ty> using remove_cv_t = typename remove_cv< _Ty> ::type; 
#line 148
template< bool _First_value, class _First, class ..._Rest> 
#line 149
struct _Disjunction { 
#line 150
using type = _First; 
#line 151
}; 
#line 153
template< class _False, class _Next, class ..._Rest> 
#line 154
struct _Disjunction< false, _False, _Next, _Rest...>  { 
#line 155
using type = typename std::_Disjunction< static_cast< bool>(_Next::value), _Next, _Rest...> ::type; 
#line 156
}; 
#line 158
template< class ..._Traits> 
#line 159
struct disjunction : public false_type { }; 
#line 161
template< class _First, class ..._Rest> 
#line 162
struct disjunction< _First, _Rest...>  : public _Disjunction< static_cast< bool>(_First::value), _First, _Rest...> ::type { 
#line 164
}; 
#line 166
template< class ..._Traits> constexpr bool 
#line 167
disjunction_v = (disjunction< _Traits...> ::value); 
#line 169
template< class _Ty, class ..._Types> constexpr bool 
#line 170
_Is_any_of_v = disjunction_v< is_same< _Ty, _Types> ...> ; 
#line 177 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\xtr1common"
[[nodiscard]] constexpr bool _Is_constant_evaluated() noexcept { 
#line 178
return __builtin_is_constant_evaluated(); 
#line 179
} 
#line 187 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\xtr1common"
template< class _Ty> constexpr bool 
#line 188
is_integral_v = _Is_any_of_v< remove_cv_t< _Ty> , bool, char, signed char, unsigned char, __wchar_t, char16_t, char32_t, short, unsigned short, int, unsigned, long, unsigned long, __int64, unsigned __int64> ; 
#line 194
template< class _Ty> 
#line 195
struct is_integral : public bool_constant< is_integral_v< _Ty> >  { }; 
#line 197
template< class _Ty> constexpr bool 
#line 198
is_floating_point_v = _Is_any_of_v< remove_cv_t< _Ty> , float, double, long double> ; 
#line 200
template< class _Ty> 
#line 201
struct is_floating_point : public bool_constant< is_floating_point_v< _Ty> >  { }; 
#line 203
template< class _Ty> constexpr bool 
#line 204
is_arithmetic_v = is_integral_v< _Ty>  || is_floating_point_v< _Ty> ; 
#line 207
template< class _Ty> 
#line 208
struct is_arithmetic : public bool_constant< is_arithmetic_v< _Ty> >  { }; 
#line 210
template< class _Ty> 
#line 211
struct remove_reference { 
#line 212
using type = _Ty; 
#line 213
using _Const_thru_ref_type = const _Ty; 
#line 214
}; 
#line 216
template< class _Ty> 
#line 217
struct remove_reference< _Ty &>  { 
#line 218
using type = _Ty; 
#line 219
using _Const_thru_ref_type = const _Ty &; 
#line 220
}; 
#line 222
template< class _Ty> 
#line 223
struct remove_reference< _Ty &&>  { 
#line 224
using type = _Ty; 
#line 225
using _Const_thru_ref_type = const _Ty &&; 
#line 226
}; 
#line 228
template< class _Ty> using remove_reference_t = typename remove_reference< _Ty> ::type; 
#line 231
template< class _Ty> using _Const_thru_ref = typename remove_reference< _Ty> ::_Const_thru_ref_type; 
#line 234
template< class _Ty> using _Remove_cvref_t
#line 235
 [[msvc::known_semantics]] = remove_cv_t< remove_reference_t< _Ty> > ; 
#line 247 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\xtr1common"
}
#line 255
#pragma warning(pop)
#pragma pack ( pop )
#line 28 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 36
[[nodiscard]] inline float acos(float _Xx) noexcept { 
#line 37
return ::acosf(_Xx); 
#line 38
} 
#line 40
[[nodiscard]] inline float acosh(float _Xx) noexcept { 
#line 41
return ::acoshf(_Xx); 
#line 42
} 
#line 44
[[nodiscard]] inline float asin(float _Xx) noexcept { 
#line 45
return ::asinf(_Xx); 
#line 46
} 
#line 48
[[nodiscard]] inline float asinh(float _Xx) noexcept { 
#line 49
return ::asinhf(_Xx); 
#line 50
} 
#line 52
[[nodiscard]] inline float atan(float _Xx) noexcept { 
#line 53
return ::atanf(_Xx); 
#line 54
} 
#line 56
[[nodiscard]] inline float atanh(float _Xx) noexcept { 
#line 57
return ::atanhf(_Xx); 
#line 58
} 
#line 60
[[nodiscard]] inline float atan2(float _Yx, float _Xx) noexcept { 
#line 61
return ::atan2f(_Yx, _Xx); 
#line 62
} 
#line 64
[[nodiscard]] inline float cbrt(float _Xx) noexcept { 
#line 65
return ::cbrtf(_Xx); 
#line 66
} 
#line 68
[[nodiscard]] inline float ceil(float _Xx) noexcept { 
#line 74 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::ceilf(_Xx); 
#line 76 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 78
[[nodiscard]] inline float copysign(float _Number, float _Sign) noexcept { 
#line 84 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::copysignf(_Number, _Sign); 
#line 86 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 88
[[nodiscard]] inline float cos(float _Xx) noexcept { 
#line 89
return ::cosf(_Xx); 
#line 90
} 
#line 92
[[nodiscard]] inline float cosh(float _Xx) noexcept { 
#line 93
return ::coshf(_Xx); 
#line 94
} 
#line 96
[[nodiscard]] inline float erf(float _Xx) noexcept { 
#line 97
return ::erff(_Xx); 
#line 98
} 
#line 100
[[nodiscard]] inline float erfc(float _Xx) noexcept { 
#line 101
return ::erfcf(_Xx); 
#line 102
} 
#line 104
[[nodiscard]] inline float exp(float _Xx) noexcept { 
#line 105
return ::expf(_Xx); 
#line 106
} 
#line 108
[[nodiscard]] inline float exp2(float _Xx) noexcept { 
#line 109
return ::exp2f(_Xx); 
#line 110
} 
#line 112
[[nodiscard]] inline float expm1(float _Xx) noexcept { 
#line 113
return ::expm1f(_Xx); 
#line 114
} 
#line 116
[[nodiscard]] inline float fabs(float _Xx) noexcept { 
#line 117
return ::fabsf(_Xx); 
#line 118
} 
#line 120
[[nodiscard]] inline float fdim(float _Xx, float _Yx) noexcept { 
#line 121
return ::fdimf(_Xx, _Yx); 
#line 122
} 
#line 124
[[nodiscard]] inline float floor(float _Xx) noexcept { 
#line 130 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::floorf(_Xx); 
#line 132 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 134
[[nodiscard]] inline float fma(float _Xx, float _Yx, float _Zx) noexcept { 
#line 135
return ::fmaf(_Xx, _Yx, _Zx); 
#line 136
} 
#line 138
[[nodiscard]] inline float fmax(float _Xx, float _Yx) noexcept { 
#line 139
return ::fmaxf(_Xx, _Yx); 
#line 140
} 
#line 142
[[nodiscard]] inline float fmin(float _Xx, float _Yx) noexcept { 
#line 143
return ::fminf(_Xx, _Yx); 
#line 144
} 
#line 146
[[nodiscard]] inline float fmod(float _Xx, float _Yx) noexcept { 
#line 147
return ::fmodf(_Xx, _Yx); 
#line 148
} 
#line 150
inline float frexp(float _Xx, int *_Yx) noexcept { 
#line 151
return ::frexpf(_Xx, _Yx); 
#line 152
} 
#line 154
[[nodiscard]] inline float hypot(float _Xx, float _Yx) noexcept { 
#line 155
return ::hypotf(_Xx, _Yx); 
#line 156
} 
#line 158
[[nodiscard]] inline int ilogb(float _Xx) noexcept { 
#line 159
return ::ilogbf(_Xx); 
#line 160
} 
#line 162
[[nodiscard]] inline float ldexp(float _Xx, int _Yx) noexcept { 
#line 163
return ::ldexpf(_Xx, _Yx); 
#line 164
} 
#line 166
[[nodiscard]] inline float lgamma(float _Xx) noexcept { 
#line 167
return ::lgammaf(_Xx); 
#line 168
} 
#line 170
[[nodiscard]] inline __int64 llrint(float _Xx) noexcept { 
#line 171
return ::llrintf(_Xx); 
#line 172
} 
#line 174
[[nodiscard]] inline __int64 llround(float _Xx) noexcept { 
#line 175
return ::llroundf(_Xx); 
#line 176
} 
#line 178
[[nodiscard]] inline float log(float _Xx) noexcept { 
#line 179
return ::logf(_Xx); 
#line 180
} 
#line 182
[[nodiscard]] inline float log10(float _Xx) noexcept { 
#line 183
return ::log10f(_Xx); 
#line 184
} 
#line 186
[[nodiscard]] inline float log1p(float _Xx) noexcept { 
#line 187
return ::log1pf(_Xx); 
#line 188
} 
#line 190
[[nodiscard]] inline float log2(float _Xx) noexcept { 
#line 191
return ::log2f(_Xx); 
#line 192
} 
#line 194
[[nodiscard]] inline float logb(float _Xx) noexcept { 
#line 195
return ::logbf(_Xx); 
#line 196
} 
#line 198
[[nodiscard]] inline long lrint(float _Xx) noexcept { 
#line 199
return ::lrintf(_Xx); 
#line 200
} 
#line 202
[[nodiscard]] inline long lround(float _Xx) noexcept { 
#line 203
return ::lroundf(_Xx); 
#line 204
} 
#line 206
inline float modf(float _Xx, float *_Yx) noexcept { 
#line 207
return ::modff(_Xx, _Yx); 
#line 208
} 
#line 210
[[nodiscard]] inline float nearbyint(float _Xx) noexcept { 
#line 211
return ::nearbyintf(_Xx); 
#line 212
} 
#line 214
[[nodiscard]] inline float nextafter(float _Xx, float _Yx) noexcept { 
#line 215
return ::nextafterf(_Xx, _Yx); 
#line 216
} 
#line 218
[[nodiscard]] inline float nexttoward(float _Xx, long double _Yx) noexcept { 
#line 219
return ::nexttowardf(_Xx, _Yx); 
#line 220
} 
#line 222
[[nodiscard]] inline float pow(float _Xx, float _Yx) noexcept { 
#line 223
return ::powf(_Xx, _Yx); 
#line 224
} 
#line 226
[[nodiscard]] inline float remainder(float _Xx, float _Yx) noexcept { 
#line 227
return ::remainderf(_Xx, _Yx); 
#line 228
} 
#line 230
inline float remquo(float _Xx, float _Yx, int *_Zx) noexcept { 
#line 231
return ::remquof(_Xx, _Yx, _Zx); 
#line 232
} 
#line 234
[[nodiscard]] inline float rint(float _Xx) noexcept { 
#line 235
return ::rintf(_Xx); 
#line 236
} 
#line 238
[[nodiscard]] inline float round(float _Xx) noexcept { 
#line 244 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::roundf(_Xx); 
#line 246 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 248
[[nodiscard]] inline float scalbln(float _Xx, long _Yx) noexcept { 
#line 249
return ::scalblnf(_Xx, _Yx); 
#line 250
} 
#line 252
[[nodiscard]] inline float scalbn(float _Xx, int _Yx) noexcept { 
#line 253
return ::scalbnf(_Xx, _Yx); 
#line 254
} 
#line 256
[[nodiscard]] inline float sin(float _Xx) noexcept { 
#line 257
return ::sinf(_Xx); 
#line 258
} 
#line 260
[[nodiscard]] inline float sinh(float _Xx) noexcept { 
#line 261
return ::sinhf(_Xx); 
#line 262
} 
#line 264
[[nodiscard]] inline float sqrt(float _Xx) noexcept { 
#line 265
return ::sqrtf(_Xx); 
#line 266
} 
#line 268
[[nodiscard]] inline float tan(float _Xx) noexcept { 
#line 269
return ::tanf(_Xx); 
#line 270
} 
#line 272
[[nodiscard]] inline float tanh(float _Xx) noexcept { 
#line 273
return ::tanhf(_Xx); 
#line 274
} 
#line 276
[[nodiscard]] inline float tgamma(float _Xx) noexcept { 
#line 277
return ::tgammaf(_Xx); 
#line 278
} 
#line 280
[[nodiscard]] inline float trunc(float _Xx) noexcept { 
#line 286 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::truncf(_Xx); 
#line 288 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 290
[[nodiscard]] inline long double acos(long double _Xx) noexcept { 
#line 291
return ::acosl(_Xx); 
#line 292
} 
#line 294
[[nodiscard]] inline long double acosh(long double _Xx) noexcept { 
#line 295
return ::acoshl(_Xx); 
#line 296
} 
#line 298
[[nodiscard]] inline long double asin(long double _Xx) noexcept { 
#line 299
return ::asinl(_Xx); 
#line 300
} 
#line 302
[[nodiscard]] inline long double asinh(long double _Xx) noexcept { 
#line 303
return ::asinhl(_Xx); 
#line 304
} 
#line 306
[[nodiscard]] inline long double atan(long double _Xx) noexcept { 
#line 307
return ::atanl(_Xx); 
#line 308
} 
#line 310
[[nodiscard]] inline long double atanh(long double _Xx) noexcept { 
#line 311
return ::atanhl(_Xx); 
#line 312
} 
#line 314
[[nodiscard]] inline long double atan2(long double _Yx, long double _Xx) noexcept 
#line 315
{ 
#line 316
return ::atan2l(_Yx, _Xx); 
#line 317
} 
#line 319
[[nodiscard]] inline long double cbrt(long double _Xx) noexcept { 
#line 320
return ::cbrtl(_Xx); 
#line 321
} 
#line 323
[[nodiscard]] inline long double ceil(long double _Xx) noexcept { 
#line 329 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::ceill(_Xx); 
#line 331 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 333
[[nodiscard]] inline long double copysign(long double _Number, long double _Sign) noexcept 
#line 334
{ 
#line 340 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::copysignl(_Number, _Sign); 
#line 342 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 344
[[nodiscard]] inline long double cos(long double _Xx) noexcept { 
#line 345
return ::cosl(_Xx); 
#line 346
} 
#line 348
[[nodiscard]] inline long double cosh(long double _Xx) noexcept { 
#line 349
return ::coshl(_Xx); 
#line 350
} 
#line 352
[[nodiscard]] inline long double erf(long double _Xx) noexcept { 
#line 353
return ::erfl(_Xx); 
#line 354
} 
#line 356
[[nodiscard]] inline long double erfc(long double _Xx) noexcept { 
#line 357
return ::erfcl(_Xx); 
#line 358
} 
#line 360
[[nodiscard]] inline long double exp(long double _Xx) noexcept { 
#line 361
return ::expl(_Xx); 
#line 362
} 
#line 364
[[nodiscard]] inline long double exp2(long double _Xx) noexcept { 
#line 365
return ::exp2l(_Xx); 
#line 366
} 
#line 368
[[nodiscard]] inline long double expm1(long double _Xx) noexcept { 
#line 369
return ::expm1l(_Xx); 
#line 370
} 
#line 372
[[nodiscard]] inline long double fabs(long double _Xx) noexcept { 
#line 373
return ::fabsl(_Xx); 
#line 374
} 
#line 376
[[nodiscard]] inline long double fdim(long double _Xx, long double _Yx) noexcept 
#line 377
{ 
#line 378
return ::fdiml(_Xx, _Yx); 
#line 379
} 
#line 381
[[nodiscard]] inline long double floor(long double _Xx) noexcept { 
#line 387 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::floorl(_Xx); 
#line 389 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 391
[[nodiscard]] inline long double fma(long double 
#line 392
_Xx, long double _Yx, long double _Zx) noexcept { 
#line 393
return ::fmal(_Xx, _Yx, _Zx); 
#line 394
} 
#line 396
[[nodiscard]] inline long double fmax(long double _Xx, long double _Yx) noexcept 
#line 397
{ 
#line 398
return ::fmaxl(_Xx, _Yx); 
#line 399
} 
#line 401
[[nodiscard]] inline long double fmin(long double _Xx, long double _Yx) noexcept 
#line 402
{ 
#line 403
return ::fminl(_Xx, _Yx); 
#line 404
} 
#line 406
[[nodiscard]] inline long double fmod(long double _Xx, long double _Yx) noexcept 
#line 407
{ 
#line 408
return ::fmodl(_Xx, _Yx); 
#line 409
} 
#line 411
inline long double frexp(long double _Xx, int *_Yx) noexcept { 
#line 412
return ::frexpl(_Xx, _Yx); 
#line 413
} 
#line 415
[[nodiscard]] inline long double hypot(long double _Xx, long double _Yx) noexcept 
#line 416
{ 
#line 417
return ::hypotl(_Xx, _Yx); 
#line 418
} 
#line 420
[[nodiscard]] inline int ilogb(long double _Xx) noexcept { 
#line 421
return ::ilogbl(_Xx); 
#line 422
} 
#line 424
[[nodiscard]] inline long double ldexp(long double _Xx, int _Yx) noexcept { 
#line 425
return ::ldexpl(_Xx, _Yx); 
#line 426
} 
#line 428
[[nodiscard]] inline long double lgamma(long double _Xx) noexcept { 
#line 429
return ::lgammal(_Xx); 
#line 430
} 
#line 432
[[nodiscard]] inline __int64 llrint(long double _Xx) noexcept { 
#line 433
return ::llrintl(_Xx); 
#line 434
} 
#line 436
[[nodiscard]] inline __int64 llround(long double _Xx) noexcept { 
#line 437
return ::llroundl(_Xx); 
#line 438
} 
#line 440
[[nodiscard]] inline long double log(long double _Xx) noexcept { 
#line 441
return ::logl(_Xx); 
#line 442
} 
#line 444
[[nodiscard]] inline long double log10(long double _Xx) noexcept { 
#line 445
return ::log10l(_Xx); 
#line 446
} 
#line 448
[[nodiscard]] inline long double log1p(long double _Xx) noexcept { 
#line 449
return ::log1pl(_Xx); 
#line 450
} 
#line 452
[[nodiscard]] inline long double log2(long double _Xx) noexcept { 
#line 453
return ::log2l(_Xx); 
#line 454
} 
#line 456
[[nodiscard]] inline long double logb(long double _Xx) noexcept { 
#line 457
return ::logbl(_Xx); 
#line 458
} 
#line 460
[[nodiscard]] inline long lrint(long double _Xx) noexcept { 
#line 461
return ::lrintl(_Xx); 
#line 462
} 
#line 464
[[nodiscard]] inline long lround(long double _Xx) noexcept { 
#line 465
return ::lroundl(_Xx); 
#line 466
} 
#line 468
inline long double modf(long double _Xx, long double *_Yx) noexcept { 
#line 469
return ::modfl(_Xx, _Yx); 
#line 470
} 
#line 472
[[nodiscard]] inline long double nearbyint(long double _Xx) noexcept { 
#line 473
return ::nearbyintl(_Xx); 
#line 474
} 
#line 476
[[nodiscard]] inline long double nextafter(long double _Xx, long double _Yx) noexcept 
#line 477
{ 
#line 478
return ::nextafterl(_Xx, _Yx); 
#line 479
} 
#line 481
[[nodiscard]] inline long double nexttoward(long double _Xx, long double _Yx) noexcept 
#line 482
{ 
#line 483
return ::nexttowardl(_Xx, _Yx); 
#line 484
} 
#line 486
[[nodiscard]] inline long double pow(long double _Xx, long double _Yx) noexcept 
#line 487
{ 
#line 488
return ::powl(_Xx, _Yx); 
#line 489
} 
#line 491
[[nodiscard]] inline long double remainder(long double _Xx, long double _Yx) noexcept 
#line 492
{ 
#line 493
return ::remainderl(_Xx, _Yx); 
#line 494
} 
#line 496
inline long double remquo(long double _Xx, long double _Yx, int *_Zx) noexcept { 
#line 497
return ::remquol(_Xx, _Yx, _Zx); 
#line 498
} 
#line 500
[[nodiscard]] inline long double rint(long double _Xx) noexcept { 
#line 501
return ::rintl(_Xx); 
#line 502
} 
#line 504
[[nodiscard]] inline long double round(long double _Xx) noexcept { 
#line 510 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::roundl(_Xx); 
#line 512 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 514
[[nodiscard]] inline long double scalbln(long double _Xx, long _Yx) noexcept { 
#line 515
return ::scalblnl(_Xx, _Yx); 
#line 516
} 
#line 518
[[nodiscard]] inline long double scalbn(long double _Xx, int _Yx) noexcept { 
#line 519
return ::scalbnl(_Xx, _Yx); 
#line 520
} 
#line 522
[[nodiscard]] inline long double sin(long double _Xx) noexcept { 
#line 523
return ::sinl(_Xx); 
#line 524
} 
#line 526
[[nodiscard]] inline long double sinh(long double _Xx) noexcept { 
#line 527
return ::sinhl(_Xx); 
#line 528
} 
#line 530
[[nodiscard]] inline long double sqrt(long double _Xx) noexcept { 
#line 531
return ::sqrtl(_Xx); 
#line 532
} 
#line 534
[[nodiscard]] inline long double tan(long double _Xx) noexcept { 
#line 535
return ::tanl(_Xx); 
#line 536
} 
#line 538
[[nodiscard]] inline long double tanh(long double _Xx) noexcept { 
#line 539
return ::tanhl(_Xx); 
#line 540
} 
#line 542
[[nodiscard]] inline long double tgamma(long double _Xx) noexcept { 
#line 543
return ::tgammal(_Xx); 
#line 544
} 
#line 546
[[nodiscard]] inline long double trunc(long double _Xx) noexcept { 
#line 552 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
return ::truncl(_Xx); 
#line 554 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
} 
#line 557
namespace std { 
#line 558
template< class _Ty1, class _Ty2> using _Common_float_type_t = conditional_t< is_same_v< _Ty1, long double>  || is_same_v< _Ty2, long double> , long double, conditional_t< is_same_v< _Ty1, float>  && is_same_v< _Ty2, float> , float, double> > ; 
#line 562
}
#line 565
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 >
double frexp ( _Ty _Value, int * const _Exp ) noexcept {
    return :: frexp ( static_cast < double > ( _Value ), _Exp );
}
#line 570
template < class _Ty1, class _Ty2, class _Ty3,
    :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 > && :: std :: is_arithmetic_v < _Ty3 >, int > = 0 >
[ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, :: std :: _Common_float_type_t < _Ty2, _Ty3 > > fma (
    _Ty1 _Left, _Ty2 _Middle, _Ty3 _Right ) noexcept {
    using _Common = :: std :: _Common_float_type_t < _Ty1, :: std :: _Common_float_type_t < _Ty2, _Ty3 >>;
    if constexpr ( :: std :: is_same_v < _Common, float > ) {
        return :: fmaf ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Middle ), static_cast < _Common > ( _Right ) );
    } else if constexpr ( :: std :: is_same_v < _Common, double > ) {
        return :: fma ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Middle ), static_cast < _Common > ( _Right ) );
    } else {
        return :: fmal ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Middle ), static_cast < _Common > ( _Right ) );
    }
}
#line 584
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 >
:: std :: _Common_float_type_t < _Ty1, _Ty2 > remquo ( _Ty1 _Left, _Ty2 _Right, int * _Pquo ) noexcept {
    using _Common = :: std :: _Common_float_type_t < _Ty1, _Ty2 >;
    if constexpr ( :: std :: is_same_v < _Common, float > ) {
        return :: remquof ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Right ), _Pquo );
    } else if constexpr ( :: std :: is_same_v < _Common, double > ) {
        return :: remquo ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Right ), _Pquo );
    } else {
        return :: remquol ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Right ), _Pquo );
    }
}
#line 707
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 >
[ [ nodiscard ] ] inline int fpclassify ( const _Ty _Ix ) noexcept {
    return _Ix == 0 ? 0 : ( - 1 );
}
#line 713
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 >
[ [ nodiscard ] ] inline bool signbit ( const _Ty _Ix ) noexcept {
    if constexpr ( static_cast < _Ty > ( - 1 ) < _Ty { } ) {
        return _Ix < 0;
    } else {
        return false;
    }
}
#line 728
[[nodiscard]] inline bool isnormal(const signed char _Ix) noexcept { return _Ix != 0; } 
#line 729
[[nodiscard]] inline bool isnormal(const unsigned char _Ix) noexcept { return _Ix != 0; } 
#line 730
[[nodiscard]] inline bool isnormal(const short _Ix) noexcept { return _Ix != 0; } 
#line 731
[[nodiscard]] inline bool isnormal(const unsigned short _Ix) noexcept { return _Ix != 0; } 
#line 732
[[nodiscard]] inline bool isnormal(const int _Ix) noexcept { return _Ix != 0; } 
#line 733
[[nodiscard]] inline bool isnormal(const unsigned _Ix) noexcept { return _Ix != (0); } 
#line 734
[[nodiscard]] inline bool isnormal(const long _Ix) noexcept { return _Ix != (0); } 
#line 735
[[nodiscard]] inline bool isnormal(const unsigned long _Ix) noexcept { return _Ix != (0); } 
#line 736
[[nodiscard]] inline bool isnormal(const __int64 _Ix) noexcept { return _Ix != (0); } 
#line 737
[[nodiscard]] inline bool isnormal(const unsigned __int64 _Ix) noexcept { return _Ix != (0); } 
#line 738
[[nodiscard]] inline bool isnormal(const bool _Ix) noexcept { return _Ix != 0; } 
#line 739
[[nodiscard]] inline bool isnormal(const char _Ix) noexcept { return _Ix != 0; } 
#line 743
[[nodiscard]] inline bool isnormal(const char16_t _Ix) noexcept { return _Ix != 0; } 
#line 744
[[nodiscard]] inline bool isnormal(const char32_t _Ix) noexcept { return _Ix != (0); } 
#line 746
[[nodiscard]] inline bool isnormal(const __wchar_t _Ix) noexcept { return _Ix != 0; } 
#line 833 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double acos ( _Ty _Left ) noexcept { return :: acos ( static_cast < double > ( _Left ) ); }
#line 834
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double asin ( _Ty _Left ) noexcept { return :: asin ( static_cast < double > ( _Left ) ); }
#line 835
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double atan ( _Ty _Left ) noexcept { return :: atan ( static_cast < double > ( _Left ) ); }
#line 836
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > atan2 ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: atan2 ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 837
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double cos ( _Ty _Left ) noexcept { return :: cos ( static_cast < double > ( _Left ) ); }
#line 838
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double sin ( _Ty _Left ) noexcept { return :: sin ( static_cast < double > ( _Left ) ); }
#line 839
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double tan ( _Ty _Left ) noexcept { return :: tan ( static_cast < double > ( _Left ) ); }
#line 840
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double acosh ( _Ty _Left ) noexcept { return :: acosh ( static_cast < double > ( _Left ) ); }
#line 841
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double asinh ( _Ty _Left ) noexcept { return :: asinh ( static_cast < double > ( _Left ) ); }
#line 842
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double atanh ( _Ty _Left ) noexcept { return :: atanh ( static_cast < double > ( _Left ) ); }
#line 843
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double cosh ( _Ty _Left ) noexcept { return :: cosh ( static_cast < double > ( _Left ) ); }
#line 844
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double sinh ( _Ty _Left ) noexcept { return :: sinh ( static_cast < double > ( _Left ) ); }
#line 845
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double tanh ( _Ty _Left ) noexcept { return :: tanh ( static_cast < double > ( _Left ) ); }
#line 846
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double exp ( _Ty _Left ) noexcept { return :: exp ( static_cast < double > ( _Left ) ); }
#line 847
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double exp2 ( _Ty _Left ) noexcept { return :: exp2 ( static_cast < double > ( _Left ) ); }
#line 848
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double expm1 ( _Ty _Left ) noexcept { return :: expm1 ( static_cast < double > ( _Left ) ); }
#line 850
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] int ilogb ( _Ty _Left ) noexcept { return :: ilogb ( static_cast < double > ( _Left ) ); }
#line 851
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double ldexp ( _Ty _Left, int _Arg2 ) noexcept { return :: ldexp ( static_cast < double > ( _Left ), _Arg2 ); }
#line 852
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log ( _Ty _Left ) noexcept { return :: log ( static_cast < double > ( _Left ) ); }
#line 853
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log10 ( _Ty _Left ) noexcept { return :: log10 ( static_cast < double > ( _Left ) ); }
#line 854
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log1p ( _Ty _Left ) noexcept { return :: log1p ( static_cast < double > ( _Left ) ); }
#line 855
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log2 ( _Ty _Left ) noexcept { return :: log2 ( static_cast < double > ( _Left ) ); }
#line 856
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double logb ( _Ty _Left ) noexcept { return :: logb ( static_cast < double > ( _Left ) ); }
#line 858
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double scalbn ( _Ty _Left, int _Arg2 ) noexcept { return :: scalbn ( static_cast < double > ( _Left ), _Arg2 ); }
#line 859
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double scalbln ( _Ty _Left, long _Arg2 ) noexcept { return :: scalbln ( static_cast < double > ( _Left ), _Arg2 ); }
#line 860
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double cbrt ( _Ty _Left ) noexcept { return :: cbrt ( static_cast < double > ( _Left ) ); }
#line 862
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double fabs ( _Ty _Left ) noexcept { return :: fabs ( static_cast < double > ( _Left ) ); }
#line 863
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > hypot ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: hypot ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 865
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > pow ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: pow ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 866
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double sqrt ( _Ty _Left ) noexcept { return :: sqrt ( static_cast < double > ( _Left ) ); }
#line 867
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double erf ( _Ty _Left ) noexcept { return :: erf ( static_cast < double > ( _Left ) ); }
#line 868
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double erfc ( _Ty _Left ) noexcept { return :: erfc ( static_cast < double > ( _Left ) ); }
#line 869
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double lgamma ( _Ty _Left ) noexcept { return :: lgamma ( static_cast < double > ( _Left ) ); }
#line 870
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double tgamma ( _Ty _Left ) noexcept { return :: tgamma ( static_cast < double > ( _Left ) ); }
#line 871
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double ceil ( _Ty _Left ) noexcept { return :: ceil ( static_cast < double > ( _Left ) ); }
#line 872
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double floor ( _Ty _Left ) noexcept { return :: floor ( static_cast < double > ( _Left ) ); }
#line 873
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double nearbyint ( _Ty _Left ) noexcept { return :: nearbyint ( static_cast < double > ( _Left ) ); }
#line 874
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double rint ( _Ty _Left ) noexcept { return :: rint ( static_cast < double > ( _Left ) ); }
#line 875
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long lrint ( _Ty _Left ) noexcept { return :: lrint ( static_cast < double > ( _Left ) ); }
#line 876
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long long llrint ( _Ty _Left ) noexcept { return :: llrint ( static_cast < double > ( _Left ) ); }
#line 877
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double round ( _Ty _Left ) noexcept { return :: round ( static_cast < double > ( _Left ) ); }
#line 878
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long lround ( _Ty _Left ) noexcept { return :: lround ( static_cast < double > ( _Left ) ); }
#line 879
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long long llround ( _Ty _Left ) noexcept { return :: llround ( static_cast < double > ( _Left ) ); }
#line 880
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double trunc ( _Ty _Left ) noexcept { return :: trunc ( static_cast < double > ( _Left ) ); }
#line 881
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fmod ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fmod ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 882
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > remainder ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: remainder ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 884
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > copysign ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: copysign ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 886
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > nextafter ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: nextafter ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 887
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double nexttoward ( _Ty _Left, long double _Arg2 ) noexcept { return :: nexttoward ( static_cast < double > ( _Left ), _Arg2 ); }
#line 888
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fdim ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fdim ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 889
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fmax ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fmax ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 890
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fmin ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fmin ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 894
[[nodiscard]] inline bool isfinite(signed char) noexcept { return true; } [[nodiscard]] inline bool isfinite(unsigned char) noexcept { return true; } [[nodiscard]] inline bool isfinite(short) noexcept { return true; } [[nodiscard]] inline bool isfinite(unsigned short) noexcept { return true; } [[nodiscard]] inline bool isfinite(int) noexcept { return true; } [[nodiscard]] inline bool isfinite(unsigned) noexcept { return true; } [[nodiscard]] inline bool isfinite(long) noexcept { return true; } [[nodiscard]] inline bool isfinite(unsigned long) noexcept { return true; } [[nodiscard]] inline bool isfinite(__int64) noexcept { return true; } [[nodiscard]] inline bool isfinite(unsigned __int64) noexcept { return true; } [[nodiscard]] inline bool isfinite(bool) noexcept { return true; } [[nodiscard]] inline bool isfinite(char) noexcept { return true; } [[nodiscard]] inline bool isfinite(char16_t) noexcept { return true; } [[nodiscard]] inline bool isfinite(char32_t) noexcept { return true; } [[nodiscard]] inline bool isfinite(__wchar_t) noexcept { return true; } 
#line 895
[[nodiscard]] inline bool isinf(signed char) noexcept { return false; } [[nodiscard]] inline bool isinf(unsigned char) noexcept { return false; } [[nodiscard]] inline bool isinf(short) noexcept { return false; } [[nodiscard]] inline bool isinf(unsigned short) noexcept { return false; } [[nodiscard]] inline bool isinf(int) noexcept { return false; } [[nodiscard]] inline bool isinf(unsigned) noexcept { return false; } [[nodiscard]] inline bool isinf(long) noexcept { return false; } [[nodiscard]] inline bool isinf(unsigned long) noexcept { return false; } [[nodiscard]] inline bool isinf(__int64) noexcept { return false; } [[nodiscard]] inline bool isinf(unsigned __int64) noexcept { return false; } [[nodiscard]] inline bool isinf(bool) noexcept { return false; } [[nodiscard]] inline bool isinf(char) noexcept { return false; } [[nodiscard]] inline bool isinf(char16_t) noexcept { return false; } [[nodiscard]] inline bool isinf(char32_t) noexcept { return false; } [[nodiscard]] inline bool isinf(__wchar_t) noexcept { return false; } 
#line 896
[[nodiscard]] inline bool isnan(signed char) noexcept { return false; } [[nodiscard]] inline bool isnan(unsigned char) noexcept { return false; } [[nodiscard]] inline bool isnan(short) noexcept { return false; } [[nodiscard]] inline bool isnan(unsigned short) noexcept { return false; } [[nodiscard]] inline bool isnan(int) noexcept { return false; } [[nodiscard]] inline bool isnan(unsigned) noexcept { return false; } [[nodiscard]] inline bool isnan(long) noexcept { return false; } [[nodiscard]] inline bool isnan(unsigned long) noexcept { return false; } [[nodiscard]] inline bool isnan(__int64) noexcept { return false; } [[nodiscard]] inline bool isnan(unsigned __int64) noexcept { return false; } [[nodiscard]] inline bool isnan(bool) noexcept { return false; } [[nodiscard]] inline bool isnan(char) noexcept { return false; } [[nodiscard]] inline bool isnan(char16_t) noexcept { return false; } [[nodiscard]] inline bool isnan(char32_t) noexcept { return false; } [[nodiscard]] inline bool isnan(__wchar_t) noexcept { return false; } 
#line 915
namespace std { 
#line 916
using ::abs;
#line 917
using ::acos;
#line 918
using ::asin;
#line 919
using ::atan;
#line 920
using ::atan2;
#line 921
using ::ceil;
#line 922
using ::cos;
#line 923
using ::cosh;
#line 924
using ::exp;
#line 925
using ::fabs;
#line 926
using ::floor;
#line 927
using ::fmod;
#line 928
using ::frexp;
#line 929
using ::ldexp;
#line 930
using ::log;
#line 931
using ::log10;
#line 932
using ::modf;
#line 933
using ::pow;
#line 934
using ::sin;
#line 935
using ::sinh;
#line 936
using ::sqrt;
#line 937
using ::tan;
#line 938
using ::tanh;
#line 940
using ::acosf;
#line 941
using ::asinf;
#line 942
using ::atanf;
#line 943
using ::atan2f;
#line 944
using ::ceilf;
#line 945
using ::cosf;
#line 946
using ::coshf;
#line 947
using ::expf;
#line 948
using ::fabsf;
#line 949
using ::floorf;
#line 950
using ::fmodf;
#line 951
using ::frexpf;
#line 952
using ::ldexpf;
#line 953
using ::logf;
#line 954
using ::log10f;
#line 955
using ::modff;
#line 956
using ::powf;
#line 957
using ::sinf;
#line 958
using ::sinhf;
#line 959
using ::sqrtf;
#line 960
using ::tanf;
#line 961
using ::tanhf;
#line 963
using ::acosl;
#line 964
using ::asinl;
#line 965
using ::atanl;
#line 966
using ::atan2l;
#line 967
using ::ceill;
#line 968
using ::cosl;
#line 969
using ::coshl;
#line 970
using ::expl;
#line 971
using ::fabsl;
#line 972
using ::floorl;
#line 973
using ::fmodl;
#line 974
using ::frexpl;
#line 975
using ::ldexpl;
#line 976
using ::logl;
#line 977
using ::log10l;
#line 978
using ::modfl;
#line 979
using ::powl;
#line 980
using ::sinl;
#line 981
using ::sinhl;
#line 982
using ::sqrtl;
#line 983
using ::tanl;
#line 984
using ::tanhl;
#line 986
using ::float_t;
#line 987
using ::double_t;
#line 989
using ::acosh;
#line 990
using ::asinh;
#line 991
using ::atanh;
#line 992
using ::cbrt;
#line 993
using ::erf;
#line 994
using ::erfc;
#line 995
using ::expm1;
#line 996
using ::exp2;
#line 998
inline namespace _Binary_hypot { 
#line 999
using ::hypot;
#line 1000
}
#line 1002
using ::ilogb;
#line 1003
using ::lgamma;
#line 1004
using ::log1p;
#line 1005
using ::log2;
#line 1006
using ::logb;
#line 1007
using ::llrint;
#line 1008
using ::lrint;
#line 1009
using ::nearbyint;
#line 1010
using ::rint;
#line 1011
using ::llround;
#line 1012
using ::lround;
#line 1013
using ::fdim;
#line 1014
using ::fma;
#line 1015
using ::fmax;
#line 1016
using ::fmin;
#line 1017
using ::round;
#line 1018
using ::trunc;
#line 1019
using ::remainder;
#line 1020
using ::remquo;
#line 1021
using ::copysign;
#line 1022
using ::nan;
#line 1023
using ::nextafter;
#line 1024
using ::scalbn;
#line 1025
using ::scalbln;
#line 1026
using ::nexttoward;
#line 1027
using ::tgamma;
#line 1029
using ::acoshf;
#line 1030
using ::asinhf;
#line 1031
using ::atanhf;
#line 1032
using ::cbrtf;
#line 1033
using ::erff;
#line 1034
using ::erfcf;
#line 1035
using ::expm1f;
#line 1036
using ::exp2f;
#line 1037
using ::hypotf;
#line 1038
using ::ilogbf;
#line 1039
using ::lgammaf;
#line 1040
using ::log1pf;
#line 1041
using ::log2f;
#line 1042
using ::logbf;
#line 1043
using ::llrintf;
#line 1044
using ::lrintf;
#line 1045
using ::nearbyintf;
#line 1046
using ::rintf;
#line 1047
using ::llroundf;
#line 1048
using ::lroundf;
#line 1049
using ::fdimf;
#line 1050
using ::fmaf;
#line 1051
using ::fmaxf;
#line 1052
using ::fminf;
#line 1053
using ::roundf;
#line 1054
using ::truncf;
#line 1055
using ::remainderf;
#line 1056
using ::remquof;
#line 1057
using ::copysignf;
#line 1058
using ::nanf;
#line 1059
using ::nextafterf;
#line 1060
using ::scalbnf;
#line 1061
using ::scalblnf;
#line 1062
using ::nexttowardf;
#line 1063
using ::tgammaf;
#line 1065
using ::acoshl;
#line 1066
using ::asinhl;
#line 1067
using ::atanhl;
#line 1068
using ::cbrtl;
#line 1069
using ::erfl;
#line 1070
using ::erfcl;
#line 1071
using ::expm1l;
#line 1072
using ::exp2l;
#line 1073
using ::hypotl;
#line 1074
using ::ilogbl;
#line 1075
using ::lgammal;
#line 1076
using ::log1pl;
#line 1077
using ::log2l;
#line 1078
using ::logbl;
#line 1079
using ::llrintl;
#line 1080
using ::lrintl;
#line 1081
using ::nearbyintl;
#line 1082
using ::rintl;
#line 1083
using ::llroundl;
#line 1084
using ::lroundl;
#line 1085
using ::fdiml;
#line 1086
using ::fmal;
#line 1087
using ::fmaxl;
#line 1088
using ::fminl;
#line 1089
using ::roundl;
#line 1090
using ::truncl;
#line 1091
using ::remainderl;
#line 1092
using ::remquol;
#line 1093
using ::copysignl;
#line 1094
using ::nanl;
#line 1095
using ::nextafterl;
#line 1096
using ::scalbnl;
#line 1097
using ::scalblnl;
#line 1098
using ::nexttowardl;
#line 1099
using ::tgammal;
#line 1101
using ::fpclassify;
#line 1102
using ::signbit;
#line 1103
using ::isfinite;
#line 1104
using ::isinf;
#line 1105
using ::isnan;
#line 1106
using ::isnormal;
#line 1107
using ::isgreater;
#line 1108
using ::isgreaterequal;
#line 1109
using ::isless;
#line 1110
using ::islessequal;
#line 1111
using ::islessgreater;
#line 1112
using ::isunordered;
#line 1113
}
#line 1696 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cmath"
#pragma warning(pop)
#pragma pack ( pop )
#line 4915 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern "C" double __cdecl _hypot(double x, double y); 
#line 4916
extern "C" float __cdecl _hypotf(float x, float y); 
#line 4926 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline bool signbit(long double) throw(); 
#line 4927
extern "C" int _ldsign(long double); 
#line 4970 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline bool signbit(double) throw(); 
#line 4971
extern "C" int _dsign(double); 
#line 5015 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline bool signbit(float) throw(); 
#line 5016
extern "C" int _fdsign(float); 
#line 5024 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isinf(long double a); 
#line 5059 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isinf(double a); 
#line 5097 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isinf(float a); 
#line 5104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isnan(long double a); 
#line 5137 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isnan(double a); 
#line 5173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isnan(float a); 
#line 5180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isfinite(long double a); 
#line 5217 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isfinite(double a); 
#line 5253 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static __inline bool isfinite(float a); 
#line 5271 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
template< class T> extern T _Pow_int(T, int) throw(); 
#line 5272
extern inline __int64 abs(__int64) throw(); 
#line 5363 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline long __cdecl abs(long) throw(); 
#line 5367 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline float __cdecl abs(float) throw(); 
#line 5368
extern inline double __cdecl abs(double) throw(); 
#line 5370
extern inline float __cdecl fabs(float) throw(); 
#line 5371
extern inline float __cdecl ceil(float) throw(); 
#line 5372
extern inline float __cdecl floor(float) throw(); 
#line 5373
extern inline float __cdecl sqrt(float) throw(); 
#line 5374
extern inline float __cdecl pow(float, float) throw(); 
#line 5420 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
template< class _Ty1, class _Ty2, std::enable_if_t< std::is_arithmetic_v< _Ty1>  && std::is_arithmetic_v< _Ty2> , int>  > [[nodiscard]] std::_Common_float_type_t< _Ty1, _Ty2>  __cdecl pow(_Ty1 _Left, _Ty2 _Right) noexcept; 
#line 5427 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline float __cdecl log(float) throw(); 
#line 5428
extern inline float __cdecl log10(float) throw(); 
#line 5429
extern inline float __cdecl fmod(float, float) throw(); 
#line 5430
extern inline float __cdecl modf(float, float *) throw(); 
#line 5431
extern inline float __cdecl exp(float) throw(); 
#line 5432
extern inline float __cdecl frexp(float, int *) throw(); 
#line 5433
extern inline float __cdecl ldexp(float, int) throw(); 
#line 5434
extern inline float __cdecl asin(float) throw(); 
#line 5435
extern inline float __cdecl sin(float) throw(); 
#line 5436
extern inline float __cdecl sinh(float) throw(); 
#line 5437
extern inline float __cdecl acos(float) throw(); 
#line 5438
extern inline float __cdecl cos(float) throw(); 
#line 5439
extern inline float __cdecl cosh(float) throw(); 
#line 5440
extern inline float __cdecl atan(float) throw(); 
#line 5441
extern inline float __cdecl atan2(float, float) throw(); 
#line 5442
extern inline float __cdecl tan(float) throw(); 
#line 5443
extern inline float __cdecl tanh(float) throw(); 
#line 5669 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
extern inline float __cdecl logb(float) throw(); 
#line 5670
extern inline int __cdecl ilogb(float) throw(); 
#line 5671
extern float __cdecl scalbn(float, float) throw(); 
#line 5672
extern inline float __cdecl scalbln(float, long) throw(); 
#line 5673
extern inline float __cdecl exp2(float) throw(); 
#line 5674
extern inline float __cdecl expm1(float) throw(); 
#line 5675
extern inline float __cdecl log2(float) throw(); 
#line 5676
extern inline float __cdecl log1p(float) throw(); 
#line 5677
extern inline float __cdecl acosh(float) throw(); 
#line 5678
extern inline float __cdecl asinh(float) throw(); 
#line 5679
extern inline float __cdecl atanh(float) throw(); 
#line 5680
extern inline float __cdecl hypot(float, float) throw(); 
#line 5681
extern inline float __cdecl cbrt(float) throw(); 
#line 5682
extern inline float __cdecl erf(float) throw(); 
#line 5683
extern inline float __cdecl erfc(float) throw(); 
#line 5684
extern inline float __cdecl lgamma(float) throw(); 
#line 5685
extern inline float __cdecl tgamma(float) throw(); 
#line 5686
extern inline float __cdecl copysign(float, float) throw(); 
#line 5687
extern inline float __cdecl nextafter(float, float) throw(); 
#line 5688
extern inline float __cdecl remainder(float, float) throw(); 
#line 5689
extern inline float __cdecl remquo(float, float, int *) throw(); 
#line 5690
extern inline float __cdecl round(float) throw(); 
#line 5691
extern inline long __cdecl lround(float) throw(); 
#line 5692
extern inline __int64 __cdecl llround(float) throw(); 
#line 5693
extern inline float __cdecl trunc(float) throw(); 
#line 5694
extern inline float __cdecl rint(float) throw(); 
#line 5695
extern inline long __cdecl lrint(float) throw(); 
#line 5696
extern inline __int64 __cdecl llrint(float) throw(); 
#line 5697
extern inline float __cdecl nearbyint(float) throw(); 
#line 5698
extern inline float __cdecl fdim(float, float) throw(); 
#line 5699
extern inline float __cdecl fma(float, float, float) throw(); 
#line 5700
extern inline float __cdecl fmax(float, float) throw(); 
#line 5701
extern inline float __cdecl fmin(float, float) throw(); 
#line 5704 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
static inline float exp10(const float a); 
#line 5706
static inline float rsqrt(const float a); 
#line 5708
static inline float rcbrt(const float a); 
#line 5710
static inline float sinpi(const float a); 
#line 5712
static inline float cospi(const float a); 
#line 5714
static inline void sincospi(const float a, float *const sptr, float *const cptr); 
#line 5716
static inline void sincos(const float a, float *const sptr, float *const cptr); 
#line 5718
static inline float j0(const float a); 
#line 5720
static inline float j1(const float a); 
#line 5722
static inline float jn(const int n, const float a); 
#line 5724
static inline float y0(const float a); 
#line 5726
static inline float y1(const float a); 
#line 5728
static inline float yn(const int n, const float a); 
#line 5730
static inline float cyl_bessel_i0(const float a); 
#line 5732
static inline float cyl_bessel_i1(const float a); 
#line 5734
static inline float erfinv(const float a); 
#line 5736
static inline float erfcinv(const float a); 
#line 5738
static inline float normcdfinv(const float a); 
#line 5740
static inline float normcdf(const float a); 
#line 5742
static inline float erfcx(const float a); 
#line 5744
static inline double copysign(const double a, const float b); 
#line 5746
static inline double copysign(const float a, const double b); 
#line 5754
static inline unsigned min(const unsigned a, const unsigned b); 
#line 5762
static inline unsigned min(const int a, const unsigned b); 
#line 5770
static inline unsigned min(const unsigned a, const int b); 
#line 5778
static inline long min(const long a, const long b); 
#line 5786
static inline unsigned long min(const unsigned long a, const unsigned long b); 
#line 5794
static inline unsigned long min(const long a, const unsigned long b); 
#line 5802
static inline unsigned long min(const unsigned long a, const long b); 
#line 5810
static inline __int64 min(const __int64 a, const __int64 b); 
#line 5818
static inline unsigned __int64 min(const unsigned __int64 a, const unsigned __int64 b); 
#line 5826
static inline unsigned __int64 min(const __int64 a, const unsigned __int64 b); 
#line 5834
static inline unsigned __int64 min(const unsigned __int64 a, const __int64 b); 
#line 5845
static inline float min(const float a, const float b); 
#line 5856
static inline double min(const double a, const double b); 
#line 5866
static inline double min(const float a, const double b); 
#line 5876
static inline double min(const double a, const float b); 
#line 5884
static inline unsigned max(const unsigned a, const unsigned b); 
#line 5892
static inline unsigned max(const int a, const unsigned b); 
#line 5900
static inline unsigned max(const unsigned a, const int b); 
#line 5908
static inline long max(const long a, const long b); 
#line 5916
static inline unsigned long max(const unsigned long a, const unsigned long b); 
#line 5924
static inline unsigned long max(const long a, const unsigned long b); 
#line 5932
static inline unsigned long max(const unsigned long a, const long b); 
#line 5940
static inline __int64 max(const __int64 a, const __int64 b); 
#line 5948
static inline unsigned __int64 max(const unsigned __int64 a, const unsigned __int64 b); 
#line 5956
static inline unsigned __int64 max(const __int64 a, const unsigned __int64 b); 
#line 5964
static inline unsigned __int64 max(const unsigned __int64 a, const __int64 b); 
#line 5975
static inline float max(const float a, const float b); 
#line 5986
static inline double max(const double a, const double b); 
#line 5996
static inline double max(const float a, const double b); 
#line 6006
static inline double max(const double a, const float b); 
#line 6018
extern "C" {
#line 6019
inline void *__nv_aligned_device_malloc(size_t size, size_t align) {int volatile ___ = 1;(void)size;(void)align;::exit(___);}
#if 0
#line 6020
{ 
#line 6021
void *__nv_aligned_device_malloc_impl(size_t, size_t); 
#line 6022
return __nv_aligned_device_malloc_impl(size, align); 
#line 6023
} 
#endif
#line 6024 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.h"
}
#line 459 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isinf(const long double a) 
#line 460
{ 
#line 464 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isinf< long double> (a); 
#line 466 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 475 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isinf(const double a) 
#line 476
{ 
#line 480 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isinf< double> (a); 
#line 482 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 491 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isinf(const float a) 
#line 492
{ 
#line 496 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isinf< float> (a); 
#line 498 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 507 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isnan(const long double a) 
#line 508
{ 
#line 512 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isnan< long double> (a); 
#line 514 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 523 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isnan(const double a) 
#line 524
{ 
#line 528 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isnan< double> (a); 
#line 530 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 539 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isnan(const float a) 
#line 540
{ 
#line 544 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isnan< float> (a); 
#line 546 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 555 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isfinite(const long double a) 
#line 556
{ 
#line 560 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isfinite< long double> (a); 
#line 562 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 571 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isfinite(const double a) 
#line 572
{ 
#line 576 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isfinite< double> (a); 
#line 578 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 587 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static __inline bool isfinite(const float a) 
#line 588
{ 
#line 592 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
return isfinite< float> (a); 
#line 594 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
} 
#line 784 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static inline float exp10(const float a) 
#line 785
{ 
#line 786
return exp10f(a); 
#line 787
} 
#line 789
static inline float rsqrt(const float a) 
#line 790
{ 
#line 791
return rsqrtf(a); 
#line 792
} 
#line 794
static inline float rcbrt(const float a) 
#line 795
{ 
#line 796
return rcbrtf(a); 
#line 797
} 
#line 799
static inline float sinpi(const float a) 
#line 800
{ 
#line 801
return sinpif(a); 
#line 802
} 
#line 804
static inline float cospi(const float a) 
#line 805
{ 
#line 806
return cospif(a); 
#line 807
} 
#line 809
static inline void sincospi(const float a, float *const sptr, float *const cptr) 
#line 810
{ 
#line 811
sincospif(a, sptr, cptr); 
#line 812
} 
#line 814
static inline void sincos(const float a, float *const sptr, float *const cptr) 
#line 815
{ 
#line 816
sincosf(a, sptr, cptr); 
#line 817
} 
#line 819
static inline float j0(const float a) 
#line 820
{ 
#line 821
return j0f(a); 
#line 822
} 
#line 824
static inline float j1(const float a) 
#line 825
{ 
#line 826
return j1f(a); 
#line 827
} 
#line 829
static inline float jn(const int n, const float a) 
#line 830
{ 
#line 831
return jnf(n, a); 
#line 832
} 
#line 834
static inline float y0(const float a) 
#line 835
{ 
#line 836
return y0f(a); 
#line 837
} 
#line 839
static inline float y1(const float a) 
#line 840
{ 
#line 841
return y1f(a); 
#line 842
} 
#line 844
static inline float yn(const int n, const float a) 
#line 845
{ 
#line 846
return ynf(n, a); 
#line 847
} 
#line 849
static inline float cyl_bessel_i0(const float a) {int volatile ___ = 1;(void)a;::exit(___);}
#if 0
#line 850
{ 
#line 851
return cyl_bessel_i0f(a); 
#line 852
} 
#endif
#line 854 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static inline float cyl_bessel_i1(const float a) {int volatile ___ = 1;(void)a;::exit(___);}
#if 0
#line 855
{ 
#line 856
return cyl_bessel_i1f(a); 
#line 857
} 
#endif
#line 859 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static inline float erfinv(const float a) 
#line 860
{ 
#line 861
return erfinvf(a); 
#line 862
} 
#line 864
static inline float erfcinv(const float a) 
#line 865
{ 
#line 866
return erfcinvf(a); 
#line 867
} 
#line 869
static inline float normcdfinv(const float a) 
#line 870
{ 
#line 871
return normcdfinvf(a); 
#line 872
} 
#line 874
static inline float normcdf(const float a) 
#line 875
{ 
#line 876
return normcdff(a); 
#line 877
} 
#line 879
static inline float erfcx(const float a) 
#line 880
{ 
#line 881
return erfcxf(a); 
#line 882
} 
#line 884
static inline double copysign(const double a, const float b) 
#line 885
{ 
#line 886
return copysign(a, static_cast< double>(b)); 
#line 887
} 
#line 889
static inline double copysign(const float a, const double b) 
#line 890
{ 
#line 891
return copysign(static_cast< double>(a), b); 
#line 892
} 
#line 894
static inline unsigned min(const unsigned a, const unsigned b) 
#line 895
{ 
#line 896
return umin(a, b); 
#line 897
} 
#line 899
static inline unsigned min(const int a, const unsigned b) 
#line 900
{ 
#line 901
return umin(static_cast< unsigned>(a), b); 
#line 902
} 
#line 904
static inline unsigned min(const unsigned a, const int b) 
#line 905
{ 
#line 906
return umin(a, static_cast< unsigned>(b)); 
#line 907
} 
#line 909
static inline long min(const long a, const long b) 
#line 910
{ 
#line 911
long retval; 
#line 914
#pragma warning (push)
#pragma warning (disable: 4127)
#line 918 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(long) == sizeof(int)) { 
#line 920
#pragma warning (pop)
#line 922 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< long>(::min(static_cast< int>(a), static_cast< int>(b)))); 
#line 923
} else { 
#line 924
retval = (static_cast< long>(llmin(static_cast< __int64>(a), static_cast< __int64>(b)))); 
#line 925
}  
#line 926
return retval; 
#line 927
} 
#line 929
static inline unsigned long min(const unsigned long a, const unsigned long b) 
#line 930
{ 
#line 931
unsigned long retval; 
#line 933
#pragma warning (push)
#pragma warning (disable: 4127)
#line 936 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 938
#pragma warning (pop)
#line 940 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 941
} else { 
#line 942
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 943
}  
#line 944
return retval; 
#line 945
} 
#line 947
static inline unsigned long min(const long a, const unsigned long b) 
#line 948
{ 
#line 949
unsigned long retval; 
#line 951
#pragma warning (push)
#pragma warning (disable: 4127)
#line 954 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 956
#pragma warning (pop)
#line 958 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 959
} else { 
#line 960
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 961
}  
#line 962
return retval; 
#line 963
} 
#line 965
static inline unsigned long min(const unsigned long a, const long b) 
#line 966
{ 
#line 967
unsigned long retval; 
#line 969
#pragma warning (push)
#pragma warning (disable: 4127)
#line 972 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 974
#pragma warning (pop)
#line 976 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 977
} else { 
#line 978
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 979
}  
#line 980
return retval; 
#line 981
} 
#line 983
static inline __int64 min(const __int64 a, const __int64 b) 
#line 984
{ 
#line 985
return llmin(a, b); 
#line 986
} 
#line 988
static inline unsigned __int64 min(const unsigned __int64 a, const unsigned __int64 b) 
#line 989
{ 
#line 990
return ullmin(a, b); 
#line 991
} 
#line 993
static inline unsigned __int64 min(const __int64 a, const unsigned __int64 b) 
#line 994
{ 
#line 995
return ullmin(static_cast< unsigned __int64>(a), b); 
#line 996
} 
#line 998
static inline unsigned __int64 min(const unsigned __int64 a, const __int64 b) 
#line 999
{ 
#line 1000
return ullmin(a, static_cast< unsigned __int64>(b)); 
#line 1001
} 
#line 1003
static inline float min(const float a, const float b) 
#line 1004
{ 
#line 1005
return fminf(a, b); 
#line 1006
} 
#line 1008
static inline double min(const double a, const double b) 
#line 1009
{ 
#line 1010
return fmin(a, b); 
#line 1011
} 
#line 1013
static inline double min(const float a, const double b) 
#line 1014
{ 
#line 1015
return fmin(static_cast< double>(a), b); 
#line 1016
} 
#line 1018
static inline double min(const double a, const float b) 
#line 1019
{ 
#line 1020
return fmin(a, static_cast< double>(b)); 
#line 1021
} 
#line 1023
static inline unsigned max(const unsigned a, const unsigned b) 
#line 1024
{ 
#line 1025
return umax(a, b); 
#line 1026
} 
#line 1028
static inline unsigned max(const int a, const unsigned b) 
#line 1029
{ 
#line 1030
return umax(static_cast< unsigned>(a), b); 
#line 1031
} 
#line 1033
static inline unsigned max(const unsigned a, const int b) 
#line 1034
{ 
#line 1035
return umax(a, static_cast< unsigned>(b)); 
#line 1036
} 
#line 1038
static inline long max(const long a, const long b) 
#line 1039
{ 
#line 1040
long retval; 
#line 1043
#pragma warning (push)
#pragma warning (disable: 4127)
#line 1046 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(long) == sizeof(int)) { 
#line 1048
#pragma warning (pop)
#line 1050 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< long>(::max(static_cast< int>(a), static_cast< int>(b)))); 
#line 1051
} else { 
#line 1052
retval = (static_cast< long>(llmax(static_cast< __int64>(a), static_cast< __int64>(b)))); 
#line 1053
}  
#line 1054
return retval; 
#line 1055
} 
#line 1057
static inline unsigned long max(const unsigned long a, const unsigned long b) 
#line 1058
{ 
#line 1059
unsigned long retval; 
#line 1061
#pragma warning (push)
#pragma warning (disable: 4127)
#line 1064 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 1066
#pragma warning (pop)
#line 1068 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 1069
} else { 
#line 1070
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 1071
}  
#line 1072
return retval; 
#line 1073
} 
#line 1075
static inline unsigned long max(const long a, const unsigned long b) 
#line 1076
{ 
#line 1077
unsigned long retval; 
#line 1079
#pragma warning (push)
#pragma warning (disable: 4127)
#line 1082 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 1084
#pragma warning (pop)
#line 1086 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 1087
} else { 
#line 1088
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 1089
}  
#line 1090
return retval; 
#line 1091
} 
#line 1093
static inline unsigned long max(const unsigned long a, const long b) 
#line 1094
{ 
#line 1095
unsigned long retval; 
#line 1097
#pragma warning (push)
#pragma warning (disable: 4127)
#line 1100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 1102
#pragma warning (pop)
#line 1104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 1105
} else { 
#line 1106
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 1107
}  
#line 1108
return retval; 
#line 1109
} 
#line 1111
static inline __int64 max(const __int64 a, const __int64 b) 
#line 1112
{ 
#line 1113
return llmax(a, b); 
#line 1114
} 
#line 1116
static inline unsigned __int64 max(const unsigned __int64 a, const unsigned __int64 b) 
#line 1117
{ 
#line 1118
return ullmax(a, b); 
#line 1119
} 
#line 1121
static inline unsigned __int64 max(const __int64 a, const unsigned __int64 b) 
#line 1122
{ 
#line 1123
return ullmax(static_cast< unsigned __int64>(a), b); 
#line 1124
} 
#line 1126
static inline unsigned __int64 max(const unsigned __int64 a, const __int64 b) 
#line 1127
{ 
#line 1128
return ullmax(a, static_cast< unsigned __int64>(b)); 
#line 1129
} 
#line 1131
static inline float max(const float a, const float b) 
#line 1132
{ 
#line 1133
return fmaxf(a, b); 
#line 1134
} 
#line 1136
static inline double max(const double a, const double b) 
#line 1137
{ 
#line 1138
return fmax(a, b); 
#line 1139
} 
#line 1141
static inline double max(const float a, const double b) 
#line 1142
{ 
#line 1143
return fmax(static_cast< double>(a), b); 
#line 1144
} 
#line 1146
static inline double max(const double a, const float b) 
#line 1147
{ 
#line 1148
return fmax(a, static_cast< double>(b)); 
#line 1149
} 
#line 1155
#pragma warning (push)
#pragma warning (disable : 4211)
#line 1161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\math_functions.hpp"
static inline int min(const int a, const int b) 
#line 1162
{ 
#line 1163
if (a < b) { return a; }  
#line 1164
return b; 
#line 1165
} 
#line 1167
static inline unsigned umin(const unsigned a, const unsigned b) 
#line 1168
{ 
#line 1169
if (a < b) { return a; }  
#line 1170
return b; 
#line 1171
} 
#line 1173
static inline __int64 llmin(const __int64 a, const __int64 b) 
#line 1174
{ 
#line 1175
if (a < b) { return a; }  
#line 1176
return b; 
#line 1177
} 
#line 1179
static inline unsigned __int64 ullmin(const unsigned __int64 a, const unsigned __int64 
#line 1180
b) 
#line 1181
{ 
#line 1182
if (a < b) { return a; }  
#line 1183
return b; 
#line 1184
} 
#line 1186
static inline int max(const int a, const int b) 
#line 1187
{ 
#line 1188
if (a > b) { return a; }  
#line 1189
return b; 
#line 1190
} 
#line 1192
static inline unsigned umax(const unsigned a, const unsigned b) 
#line 1193
{ 
#line 1194
if (a > b) { return a; }  
#line 1195
return b; 
#line 1196
} 
#line 1198
static inline __int64 llmax(const __int64 a, const __int64 b) 
#line 1199
{ 
#line 1200
if (a > b) { return a; }  
#line 1201
return b; 
#line 1202
} 
#line 1204
static inline unsigned __int64 ullmax(const unsigned __int64 a, const unsigned __int64 
#line 1205
b) 
#line 1206
{ 
#line 1207
if (a > b) { return a; }  
#line 1208
return b; 
#line 1209
} 
#line 1212
#pragma warning (pop)
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/device_functions.h"
extern "C" {
#line 2497 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/device_functions.h"
static __inline int __vimax_s32_relu(const int a, const int b); 
#line 2509
static __inline unsigned __vimax_s16x2_relu(const unsigned a, const unsigned b); 
#line 2518
static __inline int __vimin_s32_relu(const int a, const int b); 
#line 2530
static __inline unsigned __vimin_s16x2_relu(const unsigned a, const unsigned b); 
#line 2539
static __inline int __vimax3_s32(const int a, const int b, const int c); 
#line 2551
static __inline unsigned __vimax3_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2560
static __inline unsigned __vimax3_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 2572
static __inline unsigned __vimax3_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2581
static __inline int __vimin3_s32(const int a, const int b, const int c); 
#line 2593
static __inline unsigned __vimin3_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2602
static __inline unsigned __vimin3_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 2614
static __inline unsigned __vimin3_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2623
static __inline int __vimax3_s32_relu(const int a, const int b, const int c); 
#line 2635
static __inline unsigned __vimax3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 2644
static __inline int __vimin3_s32_relu(const int a, const int b, const int c); 
#line 2656
static __inline unsigned __vimin3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 2665
static __inline int __viaddmax_s32(const int a, const int b, const int c); 
#line 2677
static __inline unsigned __viaddmax_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2686
static __inline unsigned __viaddmax_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 2698
static __inline unsigned __viaddmax_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2707
static __inline int __viaddmin_s32(const int a, const int b, const int c); 
#line 2719
static __inline unsigned __viaddmin_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2728
static __inline unsigned __viaddmin_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 2740
static __inline unsigned __viaddmin_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 2750
static __inline int __viaddmax_s32_relu(const int a, const int b, const int c); 
#line 2762
static __inline unsigned __viaddmax_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 2772
static __inline int __viaddmin_s32_relu(const int a, const int b, const int c); 
#line 2784
static __inline unsigned __viaddmin_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 2793
static __inline int __vibmax_s32(const int a, const int b, bool *const pred); 
#line 2802
static __inline unsigned __vibmax_u32(const unsigned a, const unsigned b, bool *const pred); 
#line 2811
static __inline int __vibmin_s32(const int a, const int b, bool *const pred); 
#line 2820
static __inline unsigned __vibmin_u32(const unsigned a, const unsigned b, bool *const pred); 
#line 2834
static __inline unsigned __vibmax_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 2848
static __inline unsigned __vibmax_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 2862
static __inline unsigned __vibmin_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 2876
static __inline unsigned __vibmin_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 2883
}
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
static short __internal_cast_u2s(unsigned short x) 
#line 118
{ 
#line 119
short res; 
#line 121
(void)memcpy(&res, &x, sizeof x); 
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 126
} 
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
static __inline int __vimax_s32_relu(const int a, const int b) { 
#line 136
int ans = max(a, b); 
#line 138
return (ans > 0) ? ans : 0; 
#line 140 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 142
static __inline unsigned __vimax_s16x2_relu(const unsigned a, const unsigned b) { 
#line 143
unsigned res; 
#line 151 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 152
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 154
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 155
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 158
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 159
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 161
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 162
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 165
int ansI_lo = max(aS_lo, bS_lo); 
#line 166
int ansI_hi = max(aS_hi, bS_hi); 
#line 169
if (ansI_lo < 0) { ansI_lo = 0; }  
#line 170
if (ansI_hi < 0) { ansI_hi = 0; }  
#line 173
unsigned ansU_lo = (unsigned)ansI_lo; 
#line 174
unsigned ansU_hi = (unsigned)ansI_hi; 
#line 177
res = (ansU_lo | (ansU_hi << 16)); 
#line 180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 181
} 
#line 183
static __inline int __vimin_s32_relu(const int a, const int b) { 
#line 190
int ans = min(a, b); 
#line 192
return (ans > 0) ? ans : 0; 
#line 194 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 196
static __inline unsigned __vimin_s16x2_relu(const unsigned a, const unsigned b) { 
#line 197
unsigned res; 
#line 205 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 206
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 208
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 209
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 212
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 213
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 215
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 216
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 219
int ansI_lo = min(aS_lo, bS_lo); 
#line 220
int ansI_hi = min(aS_hi, bS_hi); 
#line 223
if (ansI_lo < 0) { ansI_lo = 0; }  
#line 224
if (ansI_hi < 0) { ansI_hi = 0; }  
#line 227
unsigned ansU_lo = (unsigned)ansI_lo; 
#line 228
unsigned ansU_hi = (unsigned)ansI_hi; 
#line 231
res = (ansU_lo | (ansU_hi << 16)); 
#line 234 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 235
} 
#line 237
static __inline int __vimax3_s32(const int a, const int b, const int c) { 
#line 247
return max(max(a, b), c); 
#line 249 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 251
static __inline unsigned __vimax3_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 252
unsigned res; 
#line 264 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 265
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 267
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 268
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 270
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 271
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 274
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 275
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 277
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 278
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 280
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 281
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 284
unsigned ansU_lo = (unsigned)max(max(aS_lo, bS_lo), cS_lo); 
#line 285
unsigned ansU_hi = (unsigned)max(max(aS_hi, bS_hi), cS_hi); 
#line 288
res = ((ansU_lo & 65535U) | (ansU_hi << 16)); 
#line 290 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 291
} 
#line 293
static __inline unsigned __vimax3_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 303
return max(max(a, b), c); 
#line 305 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 307
static __inline unsigned __vimax3_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 308
unsigned res; 
#line 319 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 320
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 322
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 323
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 325
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 326
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 329
unsigned short ansU_lo = (unsigned short)max(max(aU_lo, bU_lo), cU_lo); 
#line 330
unsigned short ansU_hi = (unsigned short)max(max(aU_hi, bU_hi), cU_hi); 
#line 333
res = (((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16)); 
#line 336 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 337
} 
#line 339
static __inline int __vimin3_s32(const int a, const int b, const int c) { 
#line 349
return min(min(a, b), c); 
#line 351 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 353
static __inline unsigned __vimin3_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 354
unsigned res; 
#line 365 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 366
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 368
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 369
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 371
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 372
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 375
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 376
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 378
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 379
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 381
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 382
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 385
unsigned ansU_lo = (unsigned)min(min(aS_lo, bS_lo), cS_lo); 
#line 386
unsigned ansU_hi = (unsigned)min(min(aS_hi, bS_hi), cS_hi); 
#line 389
res = ((ansU_lo & 65535U) | (ansU_hi << 16)); 
#line 392 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 393
} 
#line 395
static __inline unsigned __vimin3_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 405
return min(min(a, b), c); 
#line 407 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 409
static __inline unsigned __vimin3_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 410
unsigned res; 
#line 421 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 422
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 424
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 425
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 427
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 428
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 431
unsigned short ansU_lo = (unsigned short)min(min(aU_lo, bU_lo), cU_lo); 
#line 432
unsigned short ansU_hi = (unsigned short)min(min(aU_hi, bU_hi), cU_hi); 
#line 435
res = (((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16)); 
#line 438 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 439
} 
#line 441
static __inline int __vimax3_s32_relu(const int a, const int b, const int c) { 
#line 451
int ans = max(max(a, b), c); 
#line 453
return (ans > 0) ? ans : 0; 
#line 455 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 457
static __inline unsigned __vimax3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 458
unsigned res; 
#line 469 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 470
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 472
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 473
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 475
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 476
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 479
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 480
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 482
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 483
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 485
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 486
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 489
unsigned ansU_lo = (unsigned)max(0, max(max(aS_lo, bS_lo), cS_lo)); 
#line 490
unsigned ansU_hi = (unsigned)max(0, max(max(aS_hi, bS_hi), cS_hi)); 
#line 493
res = (ansU_lo | (ansU_hi << 16)); 
#line 496 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 497
} 
#line 499
static __inline int __vimin3_s32_relu(const int a, const int b, const int c) { 
#line 509
int ans = min(min(a, b), c); 
#line 511
return (ans > 0) ? ans : 0; 
#line 513 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 515
static __inline unsigned __vimin3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 516
unsigned res; 
#line 527 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 528
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 530
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 531
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 533
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 534
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 537
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 538
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 540
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 541
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 543
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 544
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 547
unsigned ansU_lo = (unsigned)max(0, min(min(aS_lo, bS_lo), cS_lo)); 
#line 548
unsigned ansU_hi = (unsigned)max(0, min(min(aS_hi, bS_hi), cS_hi)); 
#line 551
res = (ansU_lo | (ansU_hi << 16)); 
#line 555 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 556
} 
#line 558
static __inline int __viaddmax_s32(const int a, const int b, const int c) { 
#line 568
return max(a + b, c); 
#line 570 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 572
static __inline unsigned __viaddmax_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 573
unsigned res; 
#line 584 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 585
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 587
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 588
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 590
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 591
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 593
aU_lo += bU_lo; 
#line 594
aU_hi += bU_hi; 
#line 597
short sS_lo = __internal_cast_u2s(aU_lo); 
#line 598
short sS_hi = __internal_cast_u2s(aU_hi); 
#line 600
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 601
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 604
unsigned ansU_lo = (unsigned)max(sS_lo, cS_lo); 
#line 605
unsigned ansU_hi = (unsigned)max(sS_hi, cS_hi); 
#line 608
res = ((ansU_lo & 65535U) | (ansU_hi << 16)); 
#line 611 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 612
} 
#line 614
static __inline unsigned __viaddmax_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 624
return max(a + b, c); 
#line 626 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 628
static __inline unsigned __viaddmax_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 629
unsigned res; 
#line 640 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 641
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 643
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 644
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 646
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 647
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 650
unsigned short ansU_lo = (unsigned short)max((unsigned short)(aU_lo + bU_lo), cU_lo); 
#line 651
unsigned short ansU_hi = (unsigned short)max((unsigned short)(aU_hi + bU_hi), cU_hi); 
#line 654
res = (((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16)); 
#line 657 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 658
} 
#line 660
static __inline int __viaddmin_s32(const int a, const int b, const int c) { 
#line 670
return min(a + b, c); 
#line 672 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 674
static __inline unsigned __viaddmin_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 675
unsigned res; 
#line 686 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 687
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 689
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 690
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 692
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 693
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 695
aU_lo += bU_lo; 
#line 696
aU_hi += bU_hi; 
#line 699
short sS_lo = __internal_cast_u2s(aU_lo); 
#line 700
short sS_hi = __internal_cast_u2s(aU_hi); 
#line 702
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 703
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 706
unsigned ansU_lo = (unsigned)min(sS_lo, cS_lo); 
#line 707
unsigned ansU_hi = (unsigned)min(sS_hi, cS_hi); 
#line 710
res = ((ansU_lo & 65535U) | (ansU_hi << 16)); 
#line 713 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 714
} 
#line 716
static __inline unsigned __viaddmin_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 726
return min(a + b, c); 
#line 728 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 730
static __inline unsigned __viaddmin_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 731
unsigned res; 
#line 742 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 743
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 745
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 746
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 748
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 749
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 752
unsigned short ansU_lo = (unsigned short)min((unsigned short)(aU_lo + bU_lo), cU_lo); 
#line 753
unsigned short ansU_hi = (unsigned short)min((unsigned short)(aU_hi + bU_hi), cU_hi); 
#line 756
res = (((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16)); 
#line 759 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 760
} 
#line 762
static __inline int __viaddmax_s32_relu(const int a, const int b, const int c) { 
#line 772
int ans = max(a + b, c); 
#line 774
return (ans > 0) ? ans : 0; 
#line 776 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 778
static __inline unsigned __viaddmax_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 779
unsigned res; 
#line 790 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 791
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 793
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 794
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 796
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 797
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 799
aU_lo += bU_lo; 
#line 800
aU_hi += bU_hi; 
#line 803
short sS_lo = __internal_cast_u2s(aU_lo); 
#line 804
short sS_hi = __internal_cast_u2s(aU_hi); 
#line 806
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 807
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 810
unsigned ansU_lo = (unsigned)max(0, max(sS_lo, cS_lo)); 
#line 811
unsigned ansU_hi = (unsigned)max(0, max(sS_hi, cS_hi)); 
#line 814
res = (ansU_lo | (ansU_hi << 16)); 
#line 817 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 818
} 
#line 820
static __inline int __viaddmin_s32_relu(const int a, const int b, const int c) { 
#line 830
int ans = min(a + b, c); 
#line 832
return (ans > 0) ? ans : 0; 
#line 834 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 836
static __inline unsigned __viaddmin_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 837
unsigned res; 
#line 848 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 849
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 851
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 852
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 854
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 855
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 857
aU_lo += bU_lo; 
#line 858
aU_hi += bU_hi; 
#line 861
short sS_lo = __internal_cast_u2s(aU_lo); 
#line 862
short sS_hi = __internal_cast_u2s(aU_hi); 
#line 864
short cS_lo = __internal_cast_u2s(cU_lo); 
#line 865
short cS_hi = __internal_cast_u2s(cU_hi); 
#line 868
unsigned ansU_lo = (unsigned)max(0, min(sS_lo, cS_lo)); 
#line 869
unsigned ansU_hi = (unsigned)max(0, min(sS_hi, cS_hi)); 
#line 872
res = (ansU_lo | (ansU_hi << 16)); 
#line 875 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
return res; 
#line 876
} 
#line 880
static __inline int __vibmax_s32(const int a, const int b, bool *const pred) { 
#line 894
int ans = max(a, b); 
#line 896
(*pred) = (a >= b); 
#line 897
return ans; 
#line 899 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 901
static __inline unsigned __vibmax_u32(const unsigned a, const unsigned b, bool *const pred) { 
#line 915
unsigned ans = max(a, b); 
#line 917
(*pred) = (a >= b); 
#line 918
return ans; 
#line 920 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 923
static __inline int __vibmin_s32(const int a, const int b, bool *const pred) { 
#line 937
int ans = min(a, b); 
#line 939
(*pred) = (a <= b); 
#line 940
return ans; 
#line 942 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 945
static __inline unsigned __vibmin_u32(const unsigned a, const unsigned b, bool *const pred) { 
#line 959
unsigned ans = min(a, b); 
#line 961
(*pred) = (a <= b); 
#line 962
return ans; 
#line 964 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 966
static __inline unsigned __vibmax_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 988
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 989
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 991
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 992
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 995
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 996
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 998
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 999
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 1002
unsigned ansU_lo = (unsigned)max(aS_lo, bS_lo); 
#line 1003
unsigned ansU_hi = (unsigned)max(aS_hi, bS_hi); 
#line 1005
(*pred_hi) = (aS_hi >= bS_hi); 
#line 1006
(*pred_lo) = (aS_lo >= bS_lo); 
#line 1009
unsigned ans = (ansU_lo & 65535U) | (ansU_hi << 16); 
#line 1011
return ans; 
#line 1013 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 1015
static __inline unsigned __vibmax_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 1037
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 1038
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 1040
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 1041
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 1044
unsigned short ansU_lo = (unsigned short)max(aU_lo, bU_lo); 
#line 1045
unsigned short ansU_hi = (unsigned short)max(aU_hi, bU_hi); 
#line 1047
(*pred_hi) = (aU_hi >= bU_hi); 
#line 1048
(*pred_lo) = (aU_lo >= bU_lo); 
#line 1051
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 1053
return ans; 
#line 1055 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 1057
static __inline unsigned __vibmin_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 1079
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 1080
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 1082
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 1083
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 1086
short aS_lo = __internal_cast_u2s(aU_lo); 
#line 1087
short aS_hi = __internal_cast_u2s(aU_hi); 
#line 1089
short bS_lo = __internal_cast_u2s(bU_lo); 
#line 1090
short bS_hi = __internal_cast_u2s(bU_hi); 
#line 1093
unsigned ansU_lo = (unsigned)min(aS_lo, bS_lo); 
#line 1094
unsigned ansU_hi = (unsigned)min(aS_hi, bS_hi); 
#line 1096
(*pred_hi) = (aS_hi <= bS_hi); 
#line 1097
(*pred_lo) = (aS_lo <= bS_lo); 
#line 1100
unsigned ans = (ansU_lo & 65535U) | (ansU_hi << 16); 
#line 1102
return ans; 
#line 1104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 1106
static __inline unsigned __vibmin_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 1128
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 1129
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 1131
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 1132
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 1135
unsigned short ansU_lo = (unsigned short)min(aU_lo, bU_lo); 
#line 1136
unsigned short ansU_hi = (unsigned short)min(aU_hi, bU_hi); 
#line 1138
(*pred_hi) = (aU_hi <= bU_hi); 
#line 1139
(*pred_lo) = (aU_lo <= bU_lo); 
#line 1142
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 1144
return ans; 
#line 1146 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_functions.hpp"
} 
#line 89 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicAdd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 89
{ } 
#endif
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicAdd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 91
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicSub(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicSub(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicExch(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicExch(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline float atomicExch(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicMin(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicMin(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicMax(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicMax(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicInc(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicDec(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 115 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicAnd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 115
{ } 
#endif
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicAnd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 117
{ } 
#endif
#line 119 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicOr(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 119
{ } 
#endif
#line 121 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicOr(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 121
{ } 
#endif
#line 123 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicXor(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 123
{ } 
#endif
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicXor(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 125
{ } 
#endif
#line 127 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline int atomicCAS(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 127
{ } 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 129
{ } 
#endif
#line 156 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
extern "C" {
#line 160
}
#line 169
static __inline unsigned __int64 atomicAdd(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 169
{ } 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned __int64 atomicExch(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 171
{ } 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
static __inline unsigned __int64 atomicCAS(unsigned __int64 *address, unsigned __int64 compare, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 173
{ } 
#endif
#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
__declspec(deprecated("__any() is deprecated in favor of __any_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to suppr" "ess this warning).")) static __inline bool any(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
#line 175
{ } 
#endif
#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_atomic_functions.h"
__declspec(deprecated("__all() is deprecated in favor of __all_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to suppr" "ess this warning).")) static __inline bool all(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
#line 177
{ } 
#endif
#line 90 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.h"
extern "C" {
#line 1142
}
#line 1150
static __inline double fma(double a, double b, double c, cudaRoundMode mode); 
#line 1154
static __inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
#line 1156
static __inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
#line 1158
static __inline double dsub(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
#line 1160
static __inline int double2int(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1162
static __inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1164
static __inline __int64 double2ll(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1166
static __inline unsigned __int64 double2ull(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1168
static __inline double ll2double(__int64 a, cudaRoundMode mode = cudaRoundNearest); 
#line 1170
static __inline double ull2double(unsigned __int64 a, cudaRoundMode mode = cudaRoundNearest); 
#line 1172
static __inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest); 
#line 1174
static __inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest); 
#line 1176
static __inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest); 
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double fma(double a, double b, double c, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)c;(void)mode;::exit(___);}
#if 0
#line 94
{ 
#line 95
return (mode == (cudaRoundZero)) ? __fma_rz(a, b, c) : ((mode == (cudaRoundPosInf)) ? __fma_ru(a, b, c) : ((mode == (cudaRoundMinInf)) ? __fma_rd(a, b, c) : __fma_rn(a, b, c))); 
#line 99
} 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double dmul(double a, double b, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)mode;::exit(___);}
#if 0
#line 102
{ 
#line 103
return (mode == (cudaRoundZero)) ? __dmul_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dmul_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dmul_rd(a, b) : __dmul_rn(a, b))); 
#line 107
} 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double dadd(double a, double b, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)mode;::exit(___);}
#if 0
#line 110
{ 
#line 111
return (mode == (cudaRoundZero)) ? __dadd_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dadd_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dadd_rd(a, b) : __dadd_rn(a, b))); 
#line 115
} 
#endif
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double dsub(double a, double b, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)mode;::exit(___);}
#if 0
#line 118
{ 
#line 119
return (mode == (cudaRoundZero)) ? __dsub_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dsub_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dsub_rd(a, b) : __dsub_rn(a, b))); 
#line 123
} 
#endif
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline int double2int(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 126
{ 
#line 127
return (mode == (cudaRoundNearest)) ? __double2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2int_rd(a) : __double2int_rz(a))); 
#line 131
} 
#endif
#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline unsigned double2uint(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 134
{ 
#line 135
return (mode == (cudaRoundNearest)) ? __double2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2uint_rd(a) : __double2uint_rz(a))); 
#line 139
} 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline __int64 double2ll(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 142
{ 
#line 143
return (mode == (cudaRoundNearest)) ? __double2ll_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ll_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ll_rd(a) : __double2ll_rz(a))); 
#line 147
} 
#endif
#line 149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline unsigned __int64 double2ull(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 150
{ 
#line 151
return (mode == (cudaRoundNearest)) ? __double2ull_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ull_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ull_rd(a) : __double2ull_rz(a))); 
#line 155
} 
#endif
#line 157 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double ll2double(__int64 a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 158
{ 
#line 159
return (mode == (cudaRoundZero)) ? __ll2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ll2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ll2double_rd(a) : __ll2double_rn(a))); 
#line 163
} 
#endif
#line 165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double ull2double(unsigned __int64 a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 166
{ 
#line 167
return (mode == (cudaRoundZero)) ? __ull2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ull2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ull2double_rd(a) : __ull2double_rn(a))); 
#line 171
} 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double int2double(int a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 174
{ 
#line 175
return (double)a; 
#line 176
} 
#endif
#line 178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double uint2double(unsigned a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 179
{ 
#line 180
return (double)a; 
#line 181
} 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\device_double_functions.hpp"
static __inline double float2double(float a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 184
{ 
#line 185
return (double)a; 
#line 186
} 
#endif
#line 88 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_atomic_functions.h"
static __inline float atomicAdd(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 88
{ } 
#endif
#line 89 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicMin(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 89
{ } 
#endif
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicMax(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 91
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicAnd(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicOr(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicXor(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicMin(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicMax(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicAnd(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicOr(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicXor(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline double atomicAdd(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAdd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 96
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAdd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAdd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAdd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 108 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAdd_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 108
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAdd_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicAdd_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 114
{ } 
#endif
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicAdd_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 117
{ } 
#endif
#line 120 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline double atomicAdd_block(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 120
{ } 
#endif
#line 123 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline double atomicAdd_system(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 123
{ } 
#endif
#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicSub_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 126
{ } 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicSub_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 129
{ } 
#endif
#line 132 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicSub_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 132
{ } 
#endif
#line 135 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicSub_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 135
{ } 
#endif
#line 138 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicExch_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 138
{ } 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicExch_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 141
{ } 
#endif
#line 144 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicExch_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 144
{ } 
#endif
#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicExch_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 147
{ } 
#endif
#line 150 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicExch_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 150
{ } 
#endif
#line 153 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicExch_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 153
{ } 
#endif
#line 156 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicExch_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 156
{ } 
#endif
#line 159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicExch_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 159
{ } 
#endif
#line 162 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMin_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 162
{ } 
#endif
#line 165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMin_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 165
{ } 
#endif
#line 168 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMin_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 168
{ } 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMin_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 171
{ } 
#endif
#line 174 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMin_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 174
{ } 
#endif
#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMin_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 177
{ } 
#endif
#line 180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMin_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 180
{ } 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMin_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 183
{ } 
#endif
#line 186 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMax_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 186
{ } 
#endif
#line 189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMax_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 189
{ } 
#endif
#line 192 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMax_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 192
{ } 
#endif
#line 195 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMax_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 195
{ } 
#endif
#line 198 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMax_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 198
{ } 
#endif
#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMax_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 201
{ } 
#endif
#line 204 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMax_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 204
{ } 
#endif
#line 207 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMax_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 207
{ } 
#endif
#line 210 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicInc_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 210
{ } 
#endif
#line 213 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicInc_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 213
{ } 
#endif
#line 216 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicDec_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 216
{ } 
#endif
#line 219 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicDec_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 219
{ } 
#endif
#line 222 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicCAS_block(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 222
{ } 
#endif
#line 225 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicCAS_system(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 225
{ } 
#endif
#line 228 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicCAS_block(unsigned *address, unsigned compare, unsigned 
#line 229
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 229
{ } 
#endif
#line 232 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicCAS_system(unsigned *address, unsigned compare, unsigned 
#line 233
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 233
{ } 
#endif
#line 236 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicCAS_block(unsigned __int64 *address, unsigned __int64 
#line 237
compare, unsigned __int64 
#line 238
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 238
{ } 
#endif
#line 241 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicCAS_system(unsigned __int64 *address, unsigned __int64 
#line 242
compare, unsigned __int64 
#line 243
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 243
{ } 
#endif
#line 246 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAnd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 246
{ } 
#endif
#line 249 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAnd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 249
{ } 
#endif
#line 252 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicAnd_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 252
{ } 
#endif
#line 255 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicAnd_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 255
{ } 
#endif
#line 258 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAnd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 258
{ } 
#endif
#line 261 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAnd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 261
{ } 
#endif
#line 264 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAnd_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 264
{ } 
#endif
#line 267 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAnd_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 267
{ } 
#endif
#line 270 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicOr_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 270
{ } 
#endif
#line 273 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicOr_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 273
{ } 
#endif
#line 276 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicOr_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 276
{ } 
#endif
#line 279 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicOr_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 279
{ } 
#endif
#line 282 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicOr_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 282
{ } 
#endif
#line 285 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicOr_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 285
{ } 
#endif
#line 288 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicOr_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 288
{ } 
#endif
#line 291 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicOr_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 291
{ } 
#endif
#line 294 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicXor_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 294
{ } 
#endif
#line 297 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicXor_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 297
{ } 
#endif
#line 300 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicXor_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 300
{ } 
#endif
#line 303 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicXor_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 303
{ } 
#endif
#line 306 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicXor_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 306
{ } 
#endif
#line 309 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicXor_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 309
{ } 
#endif
#line 312 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicXor_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 312
{ } 
#endif
#line 315 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicXor_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 315
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
extern "C" {
#line 1038
}
#line 1045
__declspec(deprecated("__ballot() is deprecated in favor of __ballot_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to" " suppress this warning).")) static __inline unsigned ballot(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1045
{ } 
#endif
#line 1047 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline int syncthreads_count(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1047
{ } 
#endif
#line 1049 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline bool syncthreads_and(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1049
{ } 
#endif
#line 1051 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline bool syncthreads_or(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1051
{ } 
#endif
#line 1056 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isGlobal(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1056
{ } 
#endif
#line 1057 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isShared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1057
{ } 
#endif
#line 1058 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isConstant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1058
{ } 
#endif
#line 1059 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isLocal(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1059
{ } 
#endif
#line 1061 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isGridConstant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1061
{ } 
#endif
#line 1063 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_global(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1063
{ } 
#endif
#line 1064 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_shared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1064
{ } 
#endif
#line 1065 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_constant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1065
{ } 
#endif
#line 1066 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_local(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1066
{ } 
#endif
#line 1068 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_grid_constant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1068
{ } 
#endif
#line 1071 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_global_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1071
{ } 
#endif
#line 1072 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_shared_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1072
{ } 
#endif
#line 1073 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_constant_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1073
{ } 
#endif
#line 1074 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_local_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1074
{ } 
#endif
#line 1076 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_grid_constant_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1076
{ } 
#endif
#line 1090 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
static __inline unsigned short __nv_bswap16(unsigned short x) { 
#line 1094 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
return _byteswap_ushort(x); 
#line 1098 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
} 
#line 1109
static __inline unsigned __nv_bswap32(unsigned x) { 
#line 1113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
unsigned long ret = _byteswap_ulong(static_cast< unsigned long>(x)); 
#line 1114
return static_cast< unsigned>(ret); 
#line 1118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
} 
#line 1129
static __inline unsigned __int64 __nv_bswap64(unsigned __int64 x) { 
#line 1133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
unsigned __int64 ret = _byteswap_uint64(x); 
#line 1134
return ret; 
#line 1138 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_20_intrinsics.h"
} 
#line 123 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __fns(unsigned mask, unsigned base, int offset) {int volatile ___ = 1;(void)mask;(void)base;(void)offset;::exit(___);}
#if 0
#line 123
{ } 
#endif
#line 124 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline void __barrier_sync(unsigned id) {int volatile ___ = 1;(void)id;::exit(___);}
#if 0
#line 124
{ } 
#endif
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline void __barrier_sync_count(unsigned id, unsigned cnt) {int volatile ___ = 1;(void)id;(void)cnt;::exit(___);}
#if 0
#line 125
{ } 
#endif
#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline void __syncwarp(unsigned mask = 4294967295U) {int volatile ___ = 1;(void)mask;::exit(___);}
#if 0
#line 126
{ } 
#endif
#line 127 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline int __all_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 127
{ } 
#endif
#line 128 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline int __any_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 128
{ } 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline int __uni_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 129
{ } 
#endif
#line 130 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __ballot_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 130
{ } 
#endif
#line 131 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __activemask() {int volatile ___ = 1;::exit(___);}
#if 0
#line 131
{ } 
#endif
#line 140 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline int __shfl(int var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 140
{ } 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline unsigned __shfl(unsigned var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 141
{ } 
#endif
#line 142 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline int __shfl_up(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 142
{ } 
#endif
#line 143 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline unsigned __shfl_up(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 143
{ } 
#endif
#line 144 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline int __shfl_down(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 144
{ } 
#endif
#line 145 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline unsigned __shfl_down(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 145
{ } 
#endif
#line 146 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline int __shfl_xor(int var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 146
{ } 
#endif
#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline unsigned __shfl_xor(unsigned var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 147
{ } 
#endif
#line 148 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline float __shfl(float var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 148
{ } 
#endif
#line 149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline float __shfl_up(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 149
{ } 
#endif
#line 150 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline float __shfl_down(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 150
{ } 
#endif
#line 151 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline float __shfl_xor(float var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 151
{ } 
#endif
#line 154 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_sync(unsigned mask, int var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 154
{ } 
#endif
#line 155 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_sync(unsigned mask, unsigned var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 155
{ } 
#endif
#line 156 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_up_sync(unsigned mask, int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 156
{ } 
#endif
#line 157 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_up_sync(unsigned mask, unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 157
{ } 
#endif
#line 158 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_down_sync(unsigned mask, int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 158
{ } 
#endif
#line 159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_down_sync(unsigned mask, unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 159
{ } 
#endif
#line 160 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_xor_sync(unsigned mask, int var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 160
{ } 
#endif
#line 161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_xor_sync(unsigned mask, unsigned var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 161
{ } 
#endif
#line 162 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_sync(unsigned mask, float var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 162
{ } 
#endif
#line 163 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_up_sync(unsigned mask, float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 163
{ } 
#endif
#line 164 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_down_sync(unsigned mask, float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 164
{ } 
#endif
#line 165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_xor_sync(unsigned mask, float var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 165
{ } 
#endif
#line 169 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline unsigned __int64 __shfl(unsigned __int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 169
{ } 
#endif
#line 170 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline __int64 __shfl(__int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 170
{ } 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline __int64 __shfl_up(__int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 171
{ } 
#endif
#line 172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline unsigned __int64 __shfl_up(unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 172
{ } 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline __int64 __shfl_down(__int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 173
{ } 
#endif
#line 174 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline unsigned __int64 __shfl_down(unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 174
{ } 
#endif
#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline __int64 __shfl_xor(__int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 175
{ } 
#endif
#line 176 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline unsigned __int64 __shfl_xor(unsigned __int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 176
{ } 
#endif
#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline double __shfl(double var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 177
{ } 
#endif
#line 178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline double __shfl_up(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 178
{ } 
#endif
#line 179 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline double __shfl_down(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 179
{ } 
#endif
#line 180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline double __shfl_xor(double var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 180
{ } 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_sync(unsigned mask, __int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 183
{ } 
#endif
#line 184 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_sync(unsigned mask, unsigned __int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 184
{ } 
#endif
#line 185 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_up_sync(unsigned mask, __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 185
{ } 
#endif
#line 186 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_up_sync(unsigned mask, unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 186
{ } 
#endif
#line 187 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_down_sync(unsigned mask, __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 187
{ } 
#endif
#line 188 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_down_sync(unsigned mask, unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 188
{ } 
#endif
#line 189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_xor_sync(unsigned mask, __int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 189
{ } 
#endif
#line 190 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_xor_sync(unsigned mask, unsigned __int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 190
{ } 
#endif
#line 191 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_sync(unsigned mask, double var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 191
{ } 
#endif
#line 192 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_up_sync(unsigned mask, double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 192
{ } 
#endif
#line 193 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_down_sync(unsigned mask, double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 193
{ } 
#endif
#line 194 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_xor_sync(unsigned mask, double var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 194
{ } 
#endif
#line 198 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline long __shfl(long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 198
{ } 
#endif
#line 199 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline unsigned long __shfl(unsigned long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 199
{ } 
#endif
#line 200 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline long __shfl_up(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 200
{ } 
#endif
#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline unsigned long __shfl_up(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 201
{ } 
#endif
#line 202 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline long __shfl_down(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 202
{ } 
#endif
#line 203 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline unsigned long __shfl_down(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 203
{ } 
#endif
#line 204 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline long __shfl_xor(long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 204
{ } 
#endif
#line 205 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline unsigned long __shfl_xor(unsigned long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 205
{ } 
#endif
#line 208 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_sync(unsigned mask, long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 208
{ } 
#endif
#line 209 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_sync(unsigned mask, unsigned long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 209
{ } 
#endif
#line 210 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_up_sync(unsigned mask, long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 210
{ } 
#endif
#line 211 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_up_sync(unsigned mask, unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 211
{ } 
#endif
#line 212 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_down_sync(unsigned mask, long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 212
{ } 
#endif
#line 213 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_down_sync(unsigned mask, unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 213
{ } 
#endif
#line 214 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_xor_sync(unsigned mask, long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 214
{ } 
#endif
#line 215 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_xor_sync(unsigned mask, unsigned long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 215
{ } 
#endif
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline long __ldg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 91
{ } 
#endif
#line 92 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 92
{ } 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char __ldg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 94
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short __ldg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 96
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int __ldg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldg(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 100
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 104
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 108 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 108
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldg(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 114
{ } 
#endif
#line 115 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 115
{ } 
#endif
#line 116 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 116
{ } 
#endif
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 117
{ } 
#endif
#line 119 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float __ldg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 119
{ } 
#endif
#line 120 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double __ldg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 120
{ } 
#endif
#line 121 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 121
{ } 
#endif
#line 122 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 122
{ } 
#endif
#line 123 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 123
{ } 
#endif
#line 128 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline long __ldcg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 128
{ } 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldcg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 129
{ } 
#endif
#line 131 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char __ldcg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 131
{ } 
#endif
#line 132 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldcg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 132
{ } 
#endif
#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short __ldcg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 133
{ } 
#endif
#line 134 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int __ldcg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 134
{ } 
#endif
#line 135 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldcg(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 135
{ } 
#endif
#line 136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldcg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 136
{ } 
#endif
#line 137 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldcg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 137
{ } 
#endif
#line 138 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldcg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 138
{ } 
#endif
#line 139 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldcg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 139
{ } 
#endif
#line 140 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldcg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 140
{ } 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldcg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 141
{ } 
#endif
#line 142 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldcg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 142
{ } 
#endif
#line 144 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldcg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 144
{ } 
#endif
#line 145 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldcg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 145
{ } 
#endif
#line 146 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldcg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 146
{ } 
#endif
#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldcg(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 147
{ } 
#endif
#line 148 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldcg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 148
{ } 
#endif
#line 149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldcg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 149
{ } 
#endif
#line 150 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldcg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 150
{ } 
#endif
#line 151 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldcg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 151
{ } 
#endif
#line 152 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldcg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 152
{ } 
#endif
#line 153 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldcg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 153
{ } 
#endif
#line 154 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldcg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 154
{ } 
#endif
#line 156 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float __ldcg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 156
{ } 
#endif
#line 157 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double __ldcg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 157
{ } 
#endif
#line 158 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldcg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 158
{ } 
#endif
#line 159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldcg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 159
{ } 
#endif
#line 160 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldcg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 160
{ } 
#endif
#line 164 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline long __ldca(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 164
{ } 
#endif
#line 165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldca(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 165
{ } 
#endif
#line 167 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char __ldca(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 167
{ } 
#endif
#line 168 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldca(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 168
{ } 
#endif
#line 169 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short __ldca(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 169
{ } 
#endif
#line 170 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int __ldca(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 170
{ } 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldca(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 171
{ } 
#endif
#line 172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldca(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 172
{ } 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldca(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 173
{ } 
#endif
#line 174 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldca(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 174
{ } 
#endif
#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldca(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 175
{ } 
#endif
#line 176 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldca(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 176
{ } 
#endif
#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldca(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 177
{ } 
#endif
#line 178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldca(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 178
{ } 
#endif
#line 180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldca(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 180
{ } 
#endif
#line 181 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldca(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 181
{ } 
#endif
#line 182 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldca(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 182
{ } 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldca(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 183
{ } 
#endif
#line 184 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldca(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 184
{ } 
#endif
#line 185 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldca(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 185
{ } 
#endif
#line 186 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldca(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 186
{ } 
#endif
#line 187 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldca(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 187
{ } 
#endif
#line 188 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldca(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 188
{ } 
#endif
#line 189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldca(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 189
{ } 
#endif
#line 190 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldca(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 190
{ } 
#endif
#line 192 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float __ldca(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 192
{ } 
#endif
#line 193 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double __ldca(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 193
{ } 
#endif
#line 194 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldca(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 194
{ } 
#endif
#line 195 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldca(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 195
{ } 
#endif
#line 196 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldca(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 196
{ } 
#endif
#line 200 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline long __ldcs(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 200
{ } 
#endif
#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldcs(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 201
{ } 
#endif
#line 203 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char __ldcs(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 203
{ } 
#endif
#line 204 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldcs(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 204
{ } 
#endif
#line 205 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short __ldcs(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 205
{ } 
#endif
#line 206 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int __ldcs(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 206
{ } 
#endif
#line 207 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldcs(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 207
{ } 
#endif
#line 208 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldcs(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 208
{ } 
#endif
#line 209 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldcs(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 209
{ } 
#endif
#line 210 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldcs(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 210
{ } 
#endif
#line 211 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldcs(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 211
{ } 
#endif
#line 212 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldcs(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 212
{ } 
#endif
#line 213 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldcs(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 213
{ } 
#endif
#line 214 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldcs(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 214
{ } 
#endif
#line 216 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldcs(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 216
{ } 
#endif
#line 217 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldcs(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 217
{ } 
#endif
#line 218 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldcs(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 218
{ } 
#endif
#line 219 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldcs(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 219
{ } 
#endif
#line 220 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldcs(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 220
{ } 
#endif
#line 221 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldcs(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 221
{ } 
#endif
#line 222 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldcs(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 222
{ } 
#endif
#line 223 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldcs(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 223
{ } 
#endif
#line 224 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldcs(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 224
{ } 
#endif
#line 225 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldcs(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 225
{ } 
#endif
#line 226 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldcs(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 226
{ } 
#endif
#line 228 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float __ldcs(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 228
{ } 
#endif
#line 229 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double __ldcs(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 229
{ } 
#endif
#line 230 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldcs(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 230
{ } 
#endif
#line 231 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldcs(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 231
{ } 
#endif
#line 232 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldcs(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 232
{ } 
#endif
#line 236 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline long __ldlu(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 236
{ } 
#endif
#line 237 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldlu(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 237
{ } 
#endif
#line 239 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char __ldlu(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 239
{ } 
#endif
#line 240 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldlu(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 240
{ } 
#endif
#line 241 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short __ldlu(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 241
{ } 
#endif
#line 242 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int __ldlu(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 242
{ } 
#endif
#line 243 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldlu(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 243
{ } 
#endif
#line 244 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldlu(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 244
{ } 
#endif
#line 245 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldlu(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 245
{ } 
#endif
#line 246 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldlu(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 246
{ } 
#endif
#line 247 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldlu(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 247
{ } 
#endif
#line 248 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldlu(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 248
{ } 
#endif
#line 249 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldlu(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 249
{ } 
#endif
#line 250 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldlu(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 250
{ } 
#endif
#line 252 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldlu(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 252
{ } 
#endif
#line 253 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldlu(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 253
{ } 
#endif
#line 254 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldlu(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 254
{ } 
#endif
#line 255 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldlu(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 255
{ } 
#endif
#line 256 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldlu(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 256
{ } 
#endif
#line 257 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldlu(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 257
{ } 
#endif
#line 258 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldlu(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 258
{ } 
#endif
#line 259 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldlu(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 259
{ } 
#endif
#line 260 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldlu(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 260
{ } 
#endif
#line 261 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldlu(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 261
{ } 
#endif
#line 262 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldlu(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 262
{ } 
#endif
#line 264 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float __ldlu(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 264
{ } 
#endif
#line 265 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double __ldlu(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 265
{ } 
#endif
#line 266 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldlu(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 266
{ } 
#endif
#line 267 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldlu(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 267
{ } 
#endif
#line 268 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldlu(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 268
{ } 
#endif
#line 272 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline long __ldcv(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 272
{ } 
#endif
#line 273 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldcv(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 273
{ } 
#endif
#line 275 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char __ldcv(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 275
{ } 
#endif
#line 276 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldcv(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 276
{ } 
#endif
#line 277 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short __ldcv(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 277
{ } 
#endif
#line 278 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int __ldcv(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 278
{ } 
#endif
#line 279 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldcv(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 279
{ } 
#endif
#line 280 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldcv(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 280
{ } 
#endif
#line 281 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldcv(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 281
{ } 
#endif
#line 282 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldcv(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 282
{ } 
#endif
#line 283 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldcv(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 283
{ } 
#endif
#line 284 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldcv(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 284
{ } 
#endif
#line 285 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldcv(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 285
{ } 
#endif
#line 286 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldcv(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 286
{ } 
#endif
#line 288 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldcv(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 288
{ } 
#endif
#line 289 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldcv(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 289
{ } 
#endif
#line 290 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldcv(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 290
{ } 
#endif
#line 291 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldcv(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 291
{ } 
#endif
#line 292 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldcv(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 292
{ } 
#endif
#line 293 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldcv(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 293
{ } 
#endif
#line 294 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldcv(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 294
{ } 
#endif
#line 295 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldcv(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 295
{ } 
#endif
#line 296 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldcv(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 296
{ } 
#endif
#line 297 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldcv(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 297
{ } 
#endif
#line 298 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldcv(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 298
{ } 
#endif
#line 300 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float __ldcv(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 300
{ } 
#endif
#line 301 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double __ldcv(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 301
{ } 
#endif
#line 302 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldcv(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 302
{ } 
#endif
#line 303 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldcv(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 303
{ } 
#endif
#line 304 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldcv(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 304
{ } 
#endif
#line 308 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 308
{ } 
#endif
#line 309 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 309
{ } 
#endif
#line 311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 311
{ } 
#endif
#line 312 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 312
{ } 
#endif
#line 313 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 313
{ } 
#endif
#line 314 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 314
{ } 
#endif
#line 315 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 315
{ } 
#endif
#line 316 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 316
{ } 
#endif
#line 317 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 317
{ } 
#endif
#line 318 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 318
{ } 
#endif
#line 319 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 319
{ } 
#endif
#line 320 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 320
{ } 
#endif
#line 321 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 321
{ } 
#endif
#line 322 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 322
{ } 
#endif
#line 324 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 324
{ } 
#endif
#line 325 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 325
{ } 
#endif
#line 326 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 326
{ } 
#endif
#line 327 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 327
{ } 
#endif
#line 328 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 328
{ } 
#endif
#line 329 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 329
{ } 
#endif
#line 330 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 330
{ } 
#endif
#line 331 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 331
{ } 
#endif
#line 332 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 332
{ } 
#endif
#line 333 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 333
{ } 
#endif
#line 334 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 334
{ } 
#endif
#line 336 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 336
{ } 
#endif
#line 337 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 337
{ } 
#endif
#line 338 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 338
{ } 
#endif
#line 339 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 339
{ } 
#endif
#line 340 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 340
{ } 
#endif
#line 344 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 344
{ } 
#endif
#line 345 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 345
{ } 
#endif
#line 347 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 347
{ } 
#endif
#line 348 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 348
{ } 
#endif
#line 349 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 349
{ } 
#endif
#line 350 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 350
{ } 
#endif
#line 351 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 351
{ } 
#endif
#line 352 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 352
{ } 
#endif
#line 353 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 353
{ } 
#endif
#line 354 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 354
{ } 
#endif
#line 355 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 355
{ } 
#endif
#line 356 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 356
{ } 
#endif
#line 357 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 357
{ } 
#endif
#line 358 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 358
{ } 
#endif
#line 360 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 360
{ } 
#endif
#line 361 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 361
{ } 
#endif
#line 362 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 362
{ } 
#endif
#line 363 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 363
{ } 
#endif
#line 364 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 364
{ } 
#endif
#line 365 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 365
{ } 
#endif
#line 366 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 366
{ } 
#endif
#line 367 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 367
{ } 
#endif
#line 368 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 368
{ } 
#endif
#line 369 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 369
{ } 
#endif
#line 370 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 370
{ } 
#endif
#line 372 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 372
{ } 
#endif
#line 373 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 373
{ } 
#endif
#line 374 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 374
{ } 
#endif
#line 375 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 375
{ } 
#endif
#line 376 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 376
{ } 
#endif
#line 380 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 380
{ } 
#endif
#line 381 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 381
{ } 
#endif
#line 383 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 383
{ } 
#endif
#line 384 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 384
{ } 
#endif
#line 385 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 385
{ } 
#endif
#line 386 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 386
{ } 
#endif
#line 387 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 387
{ } 
#endif
#line 388 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 388
{ } 
#endif
#line 389 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 389
{ } 
#endif
#line 390 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 390
{ } 
#endif
#line 391 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 391
{ } 
#endif
#line 392 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 392
{ } 
#endif
#line 393 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 393
{ } 
#endif
#line 394 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 394
{ } 
#endif
#line 396 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 396
{ } 
#endif
#line 397 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 397
{ } 
#endif
#line 398 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 398
{ } 
#endif
#line 399 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 399
{ } 
#endif
#line 400 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 400
{ } 
#endif
#line 401 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 401
{ } 
#endif
#line 402 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 402
{ } 
#endif
#line 403 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 403
{ } 
#endif
#line 404 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 404
{ } 
#endif
#line 405 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 405
{ } 
#endif
#line 406 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 406
{ } 
#endif
#line 408 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 408
{ } 
#endif
#line 409 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 409
{ } 
#endif
#line 410 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 410
{ } 
#endif
#line 411 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 411
{ } 
#endif
#line 412 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 412
{ } 
#endif
#line 416 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 416
{ } 
#endif
#line 417 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 417
{ } 
#endif
#line 419 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 419
{ } 
#endif
#line 420 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 420
{ } 
#endif
#line 421 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 421
{ } 
#endif
#line 422 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 422
{ } 
#endif
#line 423 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 423
{ } 
#endif
#line 424 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 424
{ } 
#endif
#line 425 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 425
{ } 
#endif
#line 426 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 426
{ } 
#endif
#line 427 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 427
{ } 
#endif
#line 428 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 428
{ } 
#endif
#line 429 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 429
{ } 
#endif
#line 430 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 430
{ } 
#endif
#line 432 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 432
{ } 
#endif
#line 433 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 433
{ } 
#endif
#line 434 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 434
{ } 
#endif
#line 435 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 435
{ } 
#endif
#line 436 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 436
{ } 
#endif
#line 437 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 437
{ } 
#endif
#line 438 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 438
{ } 
#endif
#line 439 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 439
{ } 
#endif
#line 440 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 440
{ } 
#endif
#line 441 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 441
{ } 
#endif
#line 442 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 442
{ } 
#endif
#line 444 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 444
{ } 
#endif
#line 445 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 445
{ } 
#endif
#line 446 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 446
{ } 
#endif
#line 447 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 447
{ } 
#endif
#line 448 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 448
{ } 
#endif
#line 465 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_l(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 465
{ } 
#endif
#line 477 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_lc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 477
{ } 
#endif
#line 490 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_r(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 490
{ } 
#endif
#line 502 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_rc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 502
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_lo(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_lo(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_lo(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 125
{ } 
#endif
#line 136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_lo(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 136
{ } 
#endif
#line 148 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_hi(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 148
{ } 
#endif
#line 159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_hi(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 159
{ } 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_hi(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 171
{ } 
#endif
#line 182 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_hi(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 182
{ } 
#endif
#line 197 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline int __dp4a(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 197
{ } 
#endif
#line 206 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp4a(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 206
{ } 
#endif
#line 216 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline int __dp4a(char4 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 216
{ } 
#endif
#line 225 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp4a(uchar4 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 225
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, unsigned long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 100
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, unsigned __int64 value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, __int64 value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, float value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 104
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, double value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, unsigned value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 108 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, int value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 108
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, unsigned long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, unsigned __int64 value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, __int64 value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, float value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, double value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 114
{ } 
#endif
#line 116 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline void __nanosleep(unsigned ns) {int volatile ___ = 1;(void)ns;::exit(___);}
#if 0
#line 116
{ } 
#endif
#line 118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned short atomicCAS(unsigned short *address, unsigned short compare, unsigned short val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 118
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_add_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_min_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_max_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline int __reduce_add_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline int __reduce_min_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline int __reduce_max_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_and_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_or_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 106
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_xor_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
extern "C" {
#line 113
inline void *__nv_associate_access_property(const void *ptr, unsigned __int64 
#line 114
property) {int volatile ___ = 1;(void)ptr;(void)property;::exit(___);}
#if 0
#line 114
{ 
#line 115
extern void *__nv_associate_access_property_impl(const void *, unsigned __int64); 
#line 117
return __nv_associate_access_property_impl(ptr, property); 
#line 118
} 
#endif
#line 120 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
inline void __nv_memcpy_async_shared_global_4(void *dst, const void *
#line 121
src, unsigned 
#line 122
src_size) {int volatile ___ = 1;(void)dst;(void)src;(void)src_size;::exit(___);}
#if 0
#line 122
{ 
#line 123
extern void __nv_memcpy_async_shared_global_4_impl(void *, const void *, unsigned); 
#line 126
__nv_memcpy_async_shared_global_4_impl(dst, src, src_size); 
#line 127
} 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
inline void __nv_memcpy_async_shared_global_8(void *dst, const void *
#line 130
src, unsigned 
#line 131
src_size) {int volatile ___ = 1;(void)dst;(void)src;(void)src_size;::exit(___);}
#if 0
#line 131
{ 
#line 132
extern void __nv_memcpy_async_shared_global_8_impl(void *, const void *, unsigned); 
#line 135
__nv_memcpy_async_shared_global_8_impl(dst, src, src_size); 
#line 136
} 
#endif
#line 138 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
inline void __nv_memcpy_async_shared_global_16(void *dst, const void *
#line 139
src, unsigned 
#line 140
src_size) {int volatile ___ = 1;(void)dst;(void)src;(void)src_size;::exit(___);}
#if 0
#line 140
{ 
#line 141
extern void __nv_memcpy_async_shared_global_16_impl(void *, const void *, unsigned); 
#line 144
__nv_memcpy_async_shared_global_16_impl(dst, src, src_size); 
#line 145
} 
#endif
#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_80_rt.h"
}
#line 92 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __isCtaShared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 92
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __isClusterShared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline void *__cluster_map_shared_rank(const void *ptr, unsigned target_block_rank) {int volatile ___ = 1;(void)ptr;(void)target_block_rank;::exit(___);}
#if 0
#line 94
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __cluster_query_shared_rank(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline uint2 __cluster_map_shared_multicast(const void *ptr, unsigned cluster_cta_mask) {int volatile ___ = 1;(void)ptr;(void)cluster_cta_mask;::exit(___);}
#if 0
#line 96
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __clusterDimIsSpecified() {int volatile ___ = 1;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterDim() {int volatile ___ = 1;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterRelativeBlockIdx() {int volatile ___ = 1;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterGridDimInClusters() {int volatile ___ = 1;::exit(___);}
#if 0
#line 100
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterIdx() {int volatile ___ = 1;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __clusterRelativeBlockRank() {int volatile ___ = 1;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __clusterSizeInBlocks() {int volatile ___ = 1;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline void __cluster_barrier_arrive() {int volatile ___ = 1;::exit(___);}
#if 0
#line 104
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline void __cluster_barrier_arrive_relaxed() {int volatile ___ = 1;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline void __cluster_barrier_wait() {int volatile ___ = 1;::exit(___);}
#if 0
#line 106
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline void __threadfence_cluster() {int volatile ___ = 1;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline float2 atomicAdd(float2 *__address, float2 val) {int volatile ___ = 1;(void)__address;(void)val;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline float2 atomicAdd_block(float2 *__address, float2 val) {int volatile ___ = 1;(void)__address;(void)val;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline float2 atomicAdd_system(float2 *__address, float2 val) {int volatile ___ = 1;(void)__address;(void)val;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline float4 atomicAdd(float4 *__address, float4 val) {int volatile ___ = 1;(void)__address;(void)val;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline float4 atomicAdd_block(float4 *__address, float4 val) {int volatile ___ = 1;(void)__address;(void)val;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static __inline float4 atomicAdd_system(float4 *__address, float4 val) {int volatile ___ = 1;(void)__address;(void)val;::exit(___);}
#if 0
#line 114
{ } 
#endif
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
extern "C" {
#line 132
}
#line 139
template< bool __b, class _T> 
#line 140
struct __nv_atomic_enable_if { }; 
#line 142
template< class _T> 
#line 143
struct __nv_atomic_enable_if< true, _T>  { typedef _T __type; }; 
#line 153 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
template< class _T> 
#line 154
struct __nv_atomic_triv_cp_helper { 
#line 164 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
static const bool __val = __is_trivially_copyable(_T); 
#line 166 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
}; 
#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
template< class _T> static __inline typename __nv_atomic_enable_if< ((sizeof(_T) == (16)) && (__alignof(_T) >= (16))) && __nv_atomic_triv_cp_helper< _T> ::__val, _T> ::__type 
#line 203
atomicCAS(_T *__address, _T __compare, _T __val) {int volatile ___ = 1;(void)__address;(void)__compare;(void)__val;::exit(___);}
#if 0
#line 203
{ 
#line 204
union _U { _T __ret; __inline _U() {int *volatile ___ = 0;::free(___);}
#if 0
#line 204
{ } 
#endif
#line 204 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
}; _U __u; 
#line 205
__u128AtomicCAS((void *)__address, (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__compare)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__val)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__u.__ret))))); 
#line 209
return __u.__ret; 
#line 210
} 
#endif
#line 212 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
template< class _T> static __inline typename __nv_atomic_enable_if< ((sizeof(_T) == (16)) && (__alignof(_T) >= (16))) && __nv_atomic_triv_cp_helper< _T> ::__val, _T> ::__type 
#line 214
atomicCAS_block(_T *__address, _T __compare, _T __val) {int volatile ___ = 1;(void)__address;(void)__compare;(void)__val;::exit(___);}
#if 0
#line 214
{ 
#line 215
union _U { _T __ret; __inline _U() {int *volatile ___ = 0;::free(___);}
#if 0
#line 215
{ } 
#endif
#line 215 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
}; _U __u; 
#line 216
__u128AtomicCAS_block((void *)__address, (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__compare)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__val)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__u.__ret))))); 
#line 220
return __u.__ret; 
#line 221
} 
#endif
#line 223 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
template< class _T> static __inline typename __nv_atomic_enable_if< ((sizeof(_T) == (16)) && (__alignof(_T) >= (16))) && __nv_atomic_triv_cp_helper< _T> ::__val, _T> ::__type 
#line 225
atomicCAS_system(_T *__address, _T __compare, _T __val) {int volatile ___ = 1;(void)__address;(void)__compare;(void)__val;::exit(___);}
#if 0
#line 225
{ 
#line 226
union _U { _T __ret; __inline _U() {int *volatile ___ = 0;::free(___);}
#if 0
#line 226
{ } 
#endif
#line 226 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
}; _U __u; 
#line 227
__u128AtomicCAS_system((void *)__address, (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__compare)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__val)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__u.__ret))))); 
#line 231
return __u.__ret; 
#line 232
} 
#endif
#line 234 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
template< class _T> static __inline typename __nv_atomic_enable_if< ((sizeof(_T) == (16)) && (__alignof(_T) >= (16))) && __nv_atomic_triv_cp_helper< _T> ::__val, _T> ::__type 
#line 236
atomicExch(_T *__address, _T __val) {int volatile ___ = 1;(void)__address;(void)__val;::exit(___);}
#if 0
#line 236
{ 
#line 237
union _U { _T __ret; __inline _U() {int *volatile ___ = 0;::free(___);}
#if 0
#line 237
{ } 
#endif
#line 237 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
}; _U __u; 
#line 238
__u128AtomicExch((void *)__address, (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__val)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__u.__ret))))); 
#line 241
return __u.__ret; 
#line 242
} 
#endif
#line 244 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
template< class _T> static __inline typename __nv_atomic_enable_if< ((sizeof(_T) == (16)) && (__alignof(_T) >= (16))) && __nv_atomic_triv_cp_helper< _T> ::__val, _T> ::__type 
#line 246
atomicExch_block(_T *__address, _T __val) {int volatile ___ = 1;(void)__address;(void)__val;::exit(___);}
#if 0
#line 246
{ 
#line 247
union _U { _T __ret; __inline _U() {int *volatile ___ = 0;::free(___);}
#if 0
#line 247
{ } 
#endif
#line 247 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
}; _U __u; 
#line 248
__u128AtomicExch_block((void *)__address, (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__val)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__u.__ret))))); 
#line 251
return __u.__ret; 
#line 252
} 
#endif
#line 254 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
template< class _T> static __inline typename __nv_atomic_enable_if< ((sizeof(_T) == (16)) && (__alignof(_T) >= (16))) && __nv_atomic_triv_cp_helper< _T> ::__val, _T> ::__type 
#line 256
atomicExch_system(_T *__address, _T __val) {int volatile ___ = 1;(void)__address;(void)__val;::exit(___);}
#if 0
#line 256
{ 
#line 257
union _U { _T __ret; __inline _U() {int *volatile ___ = 0;::free(___);}
#if 0
#line 257
{ } 
#endif
#line 257 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_90_rt.h"
}; _U __u; 
#line 258
__u128AtomicExch_system((void *)__address, (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__val)))), (void *)(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__u.__ret))))); 
#line 261
return __u.__ret; 
#line 262
} 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __ffma2_rn(float2 x, float2 y, float2 z) {int volatile ___ = 1;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 100
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __ffma2_rz(float2 x, float2 y, float2 z) {int volatile ___ = 1;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 124 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __ffma2_rd(float2 x, float2 y, float2 z) {int volatile ___ = 1;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 124
{ } 
#endif
#line 136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __ffma2_ru(float2 x, float2 y, float2 z) {int volatile ___ = 1;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 136
{ } 
#endif
#line 149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fadd2_rn(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 149
{ } 
#endif
#line 161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fadd2_rz(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 161
{ } 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fadd2_rd(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 173
{ } 
#endif
#line 185 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fadd2_ru(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 185
{ } 
#endif
#line 198 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fmul2_rn(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 198
{ } 
#endif
#line 210 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fmul2_rz(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 210
{ } 
#endif
#line 222 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fmul2_rd(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 222
{ } 
#endif
#line 234 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt\\sm_100_rt.h"
static __inline float2 __fmul2_ru(float2 x, float2 y) {int volatile ___ = 1;(void)x;(void)y;::exit(___);}
#if 0
#line 234
{ } 
#endif
#line 65 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> struct __nv_itex_trait { }; 
#line 66
template<> struct __nv_itex_trait< char>  { typedef void type; }; 
#line 67
template<> struct __nv_itex_trait< signed char>  { typedef void type; }; 
#line 68
template<> struct __nv_itex_trait< char1>  { typedef void type; }; 
#line 69
template<> struct __nv_itex_trait< char2>  { typedef void type; }; 
#line 70
template<> struct __nv_itex_trait< char4>  { typedef void type; }; 
#line 71
template<> struct __nv_itex_trait< unsigned char>  { typedef void type; }; 
#line 72
template<> struct __nv_itex_trait< uchar1>  { typedef void type; }; 
#line 73
template<> struct __nv_itex_trait< uchar2>  { typedef void type; }; 
#line 74
template<> struct __nv_itex_trait< uchar4>  { typedef void type; }; 
#line 75
template<> struct __nv_itex_trait< short>  { typedef void type; }; 
#line 76
template<> struct __nv_itex_trait< short1>  { typedef void type; }; 
#line 77
template<> struct __nv_itex_trait< short2>  { typedef void type; }; 
#line 78
template<> struct __nv_itex_trait< short4>  { typedef void type; }; 
#line 79
template<> struct __nv_itex_trait< unsigned short>  { typedef void type; }; 
#line 80
template<> struct __nv_itex_trait< ushort1>  { typedef void type; }; 
#line 81
template<> struct __nv_itex_trait< ushort2>  { typedef void type; }; 
#line 82
template<> struct __nv_itex_trait< ushort4>  { typedef void type; }; 
#line 83
template<> struct __nv_itex_trait< int>  { typedef void type; }; 
#line 84
template<> struct __nv_itex_trait< int1>  { typedef void type; }; 
#line 85
template<> struct __nv_itex_trait< int2>  { typedef void type; }; 
#line 86
template<> struct __nv_itex_trait< int4>  { typedef void type; }; 
#line 87
template<> struct __nv_itex_trait< unsigned>  { typedef void type; }; 
#line 88
template<> struct __nv_itex_trait< uint1>  { typedef void type; }; 
#line 89
template<> struct __nv_itex_trait< uint2>  { typedef void type; }; 
#line 90
template<> struct __nv_itex_trait< uint4>  { typedef void type; }; 
#line 92
template<> struct __nv_itex_trait< long>  { typedef void type; }; 
#line 93
template<> struct __nv_itex_trait< long1>  { typedef void type; }; 
#line 94
template<> struct __nv_itex_trait< long2>  { typedef void type; }; 
#line 95
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 96
template<> struct __nv_itex_trait< long4>  { typedef void type; }; 
#line 97
__pragma( warning(pop)) 
#line 98
template<> struct __nv_itex_trait< unsigned long>  { typedef void type; }; 
#line 99
template<> struct __nv_itex_trait< ulong1>  { typedef void type; }; 
#line 100
template<> struct __nv_itex_trait< ulong2>  { typedef void type; }; 
#line 101
__pragma( warning(push)) __pragma( warning(disable:4996)) 
#line 102
template<> struct __nv_itex_trait< ulong4>  { typedef void type; }; 
#line 103
__pragma( warning(pop)) 
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template<> struct __nv_itex_trait< float>  { typedef void type; }; 
#line 106
template<> struct __nv_itex_trait< float1>  { typedef void type; }; 
#line 107
template<> struct __nv_itex_trait< float2>  { typedef void type; }; 
#line 108
template<> struct __nv_itex_trait< float4>  { typedef void type; }; 
__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 112
template< class T> static typename __nv_itex_trait< T> ::type 
#line 113
tex1Dfetch(T *ptr, ::cudaTextureObject_t obj, int x) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;::exit(___);}
#if 0
#line 114
{ 
#line 115
__nv_tex_surf_handler("__itex1Dfetch", ptr, obj, x); 
#line 116
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 119
tex1Dfetch(::cudaTextureObject_t texObject, int x) {int volatile ___ = 1;(void)texObject;(void)x;::exit(___);}
#if 0
#line 120
{ 
#line 121
T ret; 
#line 122
tex1Dfetch(&ret, texObject, x); 
#line 123
return ret; 
#line 124
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 127
tex1D(T *ptr, ::cudaTextureObject_t obj, float x) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;::exit(___);}
#if 0
#line 128
{ 
#line 129
__nv_tex_surf_handler("__itex1D", ptr, obj, x); 
#line 130
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 134
tex1D(::cudaTextureObject_t texObject, float x) {int volatile ___ = 1;(void)texObject;(void)x;::exit(___);}
#if 0
#line 135
{ 
#line 136
T ret; 
#line 137
tex1D(&ret, texObject, x); 
#line 138
return ret; 
#line 139
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 142 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 143
tex2D(T *ptr, ::cudaTextureObject_t obj, float x, float y) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;::exit(___);}
#if 0
#line 144
{ 
#line 145
__nv_tex_surf_handler("__itex2D", ptr, obj, x, y); 
#line 146
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 148 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 149
tex2D(::cudaTextureObject_t texObject, float x, float y) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;::exit(___);}
#if 0
#line 150
{ 
#line 151
T ret; 
#line 152
tex2D(&ret, texObject, x, y); 
#line 153
return ret; 
#line 154
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 157 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 158
tex2D(T *ptr, ::cudaTextureObject_t obj, float x, float y, bool *
#line 159
isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)isResident;::exit(___);}
#if 0
#line 160
{ 
#line 161
unsigned char res; 
#line 162
__nv_tex_surf_handler("__itex2D_sparse", ptr, obj, x, y, &res); 
#line 163
(*isResident) = (res != 0); 
#line 164
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 166 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 167
tex2D(::cudaTextureObject_t texObject, float x, float y, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)isResident;::exit(___);}
#if 0
#line 168
{ 
#line 169
T ret; 
#line 170
tex2D(&ret, texObject, x, y, isResident); 
#line 171
return ret; 
#line 172
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 178
tex3D(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 179
{ 
#line 180
__nv_tex_surf_handler("__itex3D", ptr, obj, x, y, z); 
#line 181
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 184
tex3D(::cudaTextureObject_t texObject, float x, float y, float z) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 185
{ 
#line 186
T ret; 
#line 187
tex3D(&ret, texObject, x, y, z); 
#line 188
return ret; 
#line 189
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 192 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 193
tex3D(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, bool *
#line 194
isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)isResident;::exit(___);}
#if 0
#line 195
{ 
#line 196
unsigned char res; 
#line 197
__nv_tex_surf_handler("__itex3D_sparse", ptr, obj, x, y, z, &res); 
#line 198
(*isResident) = (res != 0); 
#line 199
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 202
tex3D(::cudaTextureObject_t texObject, float x, float y, float z, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)isResident;::exit(___);}
#if 0
#line 203
{ 
#line 204
T ret; 
#line 205
tex3D(&ret, texObject, x, y, z, isResident); 
#line 206
return ret; 
#line 207
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 211 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 212
tex1DLayered(T *ptr, ::cudaTextureObject_t obj, float x, int layer) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;::exit(___);}
#if 0
#line 213
{ 
#line 214
__nv_tex_surf_handler("__itex1DLayered", ptr, obj, x, layer); 
#line 215
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 217 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 218
tex1DLayered(::cudaTextureObject_t texObject, float x, int layer) {int volatile ___ = 1;(void)texObject;(void)x;(void)layer;::exit(___);}
#if 0
#line 219
{ 
#line 220
T ret; 
#line 221
tex1DLayered(&ret, texObject, x, layer); 
#line 222
return ret; 
#line 223
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 225 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 226
tex2DLayered(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;::exit(___);}
#if 0
#line 227
{ 
#line 228
__nv_tex_surf_handler("__itex2DLayered", ptr, obj, x, y, layer); 
#line 229
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 231 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 232
tex2DLayered(::cudaTextureObject_t texObject, float x, float y, int layer) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;::exit(___);}
#if 0
#line 233
{ 
#line 234
T ret; 
#line 235
tex2DLayered(&ret, texObject, x, y, layer); 
#line 236
return ret; 
#line 237
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 240 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 241
tex2DLayered(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)isResident;::exit(___);}
#if 0
#line 242
{ 
#line 243
unsigned char res; 
#line 244
__nv_tex_surf_handler("__itex2DLayered_sparse", ptr, obj, x, y, layer, &res); 
#line 245
(*isResident) = (res != 0); 
#line 246
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 248 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 249
tex2DLayered(::cudaTextureObject_t texObject, float x, float y, int layer, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)isResident;::exit(___);}
#if 0
#line 250
{ 
#line 251
T ret; 
#line 252
tex2DLayered(&ret, texObject, x, y, layer, isResident); 
#line 253
return ret; 
#line 254
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 258 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 259
texCubemap(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 260
{ 
#line 261
__nv_tex_surf_handler("__itexCubemap", ptr, obj, x, y, z); 
#line 262
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 265 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 266
texCubemap(::cudaTextureObject_t texObject, float x, float y, float z) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 267
{ 
#line 268
T ret; 
#line 269
texCubemap(&ret, texObject, x, y, z); 
#line 270
return ret; 
#line 271
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 274 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 275
texCubemapLayered(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, int layer) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;::exit(___);}
#if 0
#line 276
{ 
#line 277
__nv_tex_surf_handler("__itexCubemapLayered", ptr, obj, x, y, z, layer); 
#line 278
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 280 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 281
texCubemapLayered(::cudaTextureObject_t texObject, float x, float y, float z, int layer) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;::exit(___);}
#if 0
#line 282
{ 
#line 283
T ret; 
#line 284
texCubemapLayered(&ret, texObject, x, y, z, layer); 
#line 285
return ret; 
#line 286
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 288 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 289
tex2Dgather(T *ptr, ::cudaTextureObject_t obj, float x, float y, int comp = 0) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)comp;::exit(___);}
#if 0
#line 290
{ 
#line 291
__nv_tex_surf_handler("__itex2Dgather", ptr, obj, x, y, comp); 
#line 292
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 294 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 295
tex2Dgather(::cudaTextureObject_t to, float x, float y, int comp = 0) {int volatile ___ = 1;(void)to;(void)x;(void)y;(void)comp;::exit(___);}
#if 0
#line 296
{ 
#line 297
T ret; 
#line 298
tex2Dgather(&ret, to, x, y, comp); 
#line 299
return ret; 
#line 300
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 303 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 304
tex2Dgather(T *ptr, ::cudaTextureObject_t obj, float x, float y, bool *isResident, int comp = 0) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)isResident;(void)comp;::exit(___);}
#if 0
#line 305
{ 
#line 306
unsigned char res; 
#line 307
__nv_tex_surf_handler("__itex2Dgather_sparse", ptr, obj, x, y, comp, &res); 
#line 308
(*isResident) = (res != 0); 
#line 309
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 312
tex2Dgather(::cudaTextureObject_t to, float x, float y, bool *isResident, int comp = 0) {int volatile ___ = 1;(void)to;(void)x;(void)y;(void)isResident;(void)comp;::exit(___);}
#if 0
#line 313
{ 
#line 314
T ret; 
#line 315
tex2Dgather(&ret, to, x, y, isResident, comp); 
#line 316
return ret; 
#line 317
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 321 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 322
tex1DLod(T *ptr, ::cudaTextureObject_t obj, float x, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)level;::exit(___);}
#if 0
#line 323
{ 
#line 324
__nv_tex_surf_handler("__itex1DLod", ptr, obj, x, level); 
#line 325
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 327 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 328
tex1DLod(::cudaTextureObject_t texObject, float x, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)level;::exit(___);}
#if 0
#line 329
{ 
#line 330
T ret; 
#line 331
tex1DLod(&ret, texObject, x, level); 
#line 332
return ret; 
#line 333
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 336 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 337
tex2DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)level;::exit(___);}
#if 0
#line 338
{ 
#line 339
__nv_tex_surf_handler("__itex2DLod", ptr, obj, x, y, level); 
#line 340
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 342 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 343
tex2DLod(::cudaTextureObject_t texObject, float x, float y, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)level;::exit(___);}
#if 0
#line 344
{ 
#line 345
T ret; 
#line 346
tex2DLod(&ret, texObject, x, y, level); 
#line 347
return ret; 
#line 348
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 352 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 353
tex2DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float level, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)level;(void)isResident;::exit(___);}
#if 0
#line 354
{ 
#line 355
unsigned char res; 
#line 356
__nv_tex_surf_handler("__itex2DLod_sparse", ptr, obj, x, y, level, &res); 
#line 357
(*isResident) = (res != 0); 
#line 358
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 360 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 361
tex2DLod(::cudaTextureObject_t texObject, float x, float y, float level, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)level;(void)isResident;::exit(___);}
#if 0
#line 362
{ 
#line 363
T ret; 
#line 364
tex2DLod(&ret, texObject, x, y, level, isResident); 
#line 365
return ret; 
#line 366
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 371 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 372
tex3DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 373
{ 
#line 374
__nv_tex_surf_handler("__itex3DLod", ptr, obj, x, y, z, level); 
#line 375
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 377 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 378
tex3DLod(::cudaTextureObject_t texObject, float x, float y, float z, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 379
{ 
#line 380
T ret; 
#line 381
tex3DLod(&ret, texObject, x, y, z, level); 
#line 382
return ret; 
#line 383
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 386 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 387
tex3DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, float level, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;(void)isResident;::exit(___);}
#if 0
#line 388
{ 
#line 389
unsigned char res; 
#line 390
__nv_tex_surf_handler("__itex3DLod_sparse", ptr, obj, x, y, z, level, &res); 
#line 391
(*isResident) = (res != 0); 
#line 392
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 394 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 395
tex3DLod(::cudaTextureObject_t texObject, float x, float y, float z, float level, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;(void)isResident;::exit(___);}
#if 0
#line 396
{ 
#line 397
T ret; 
#line 398
tex3DLod(&ret, texObject, x, y, z, level, isResident); 
#line 399
return ret; 
#line 400
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 405 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 406
tex1DLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, int layer, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)level;::exit(___);}
#if 0
#line 407
{ 
#line 408
__nv_tex_surf_handler("__itex1DLayeredLod", ptr, obj, x, layer, level); 
#line 409
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 411 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 412
tex1DLayeredLod(::cudaTextureObject_t texObject, float x, int layer, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)level;::exit(___);}
#if 0
#line 413
{ 
#line 414
T ret; 
#line 415
tex1DLayeredLod(&ret, texObject, x, layer, level); 
#line 416
return ret; 
#line 417
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 420 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 421
tex2DLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)level;::exit(___);}
#if 0
#line 422
{ 
#line 423
__nv_tex_surf_handler("__itex2DLayeredLod", ptr, obj, x, y, layer, level); 
#line 424
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 426 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 427
tex2DLayeredLod(::cudaTextureObject_t texObject, float x, float y, int layer, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)level;::exit(___);}
#if 0
#line 428
{ 
#line 429
T ret; 
#line 430
tex2DLayeredLod(&ret, texObject, x, y, layer, level); 
#line 431
return ret; 
#line 432
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 435 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 436
tex2DLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, float level, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)level;(void)isResident;::exit(___);}
#if 0
#line 437
{ 
#line 438
unsigned char res; 
#line 439
__nv_tex_surf_handler("__itex2DLayeredLod_sparse", ptr, obj, x, y, layer, level, &res); 
#line 440
(*isResident) = (res != 0); 
#line 441
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 443 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 444
tex2DLayeredLod(::cudaTextureObject_t texObject, float x, float y, int layer, float level, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)level;(void)isResident;::exit(___);}
#if 0
#line 445
{ 
#line 446
T ret; 
#line 447
tex2DLayeredLod(&ret, texObject, x, y, layer, level, isResident); 
#line 448
return ret; 
#line 449
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 452 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 453
texCubemapLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 454
{ 
#line 455
__nv_tex_surf_handler("__itexCubemapLod", ptr, obj, x, y, z, level); 
#line 456
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 458 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 459
texCubemapLod(::cudaTextureObject_t texObject, float x, float y, float z, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 460
{ 
#line 461
T ret; 
#line 462
texCubemapLod(&ret, texObject, x, y, z, level); 
#line 463
return ret; 
#line 464
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 467 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 468
texCubemapGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 469
{ 
#line 470
__nv_tex_surf_handler("__itexCubemapGrad_v2", ptr, obj, x, y, z, &dPdx, &dPdy); 
#line 471
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 473 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 474
texCubemapGrad(::cudaTextureObject_t texObject, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 475
{ 
#line 476
T ret; 
#line 477
texCubemapGrad(&ret, texObject, x, y, z, dPdx, dPdy); 
#line 478
return ret; 
#line 479
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 481 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 482
texCubemapLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, int layer, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;(void)level;::exit(___);}
#if 0
#line 483
{ 
#line 484
__nv_tex_surf_handler("__itexCubemapLayeredLod", ptr, obj, x, y, z, layer, level); 
#line 485
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 487 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 488
texCubemapLayeredLod(::cudaTextureObject_t texObject, float x, float y, float z, int layer, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;(void)level;::exit(___);}
#if 0
#line 489
{ 
#line 490
T ret; 
#line 491
texCubemapLayeredLod(&ret, texObject, x, y, z, layer, level); 
#line 492
return ret; 
#line 493
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 495 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 496
tex1DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float dPdx, float dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 497
{ 
#line 498
__nv_tex_surf_handler("__itex1DGrad", ptr, obj, x, dPdx, dPdy); 
#line 499
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 501 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 502
tex1DGrad(::cudaTextureObject_t texObject, float x, float dPdx, float dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 503
{ 
#line 504
T ret; 
#line 505
tex1DGrad(&ret, texObject, x, dPdx, dPdy); 
#line 506
return ret; 
#line 507
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 510 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 511
tex2DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 512
{ 
#line 513
__nv_tex_surf_handler("__itex2DGrad_v2", ptr, obj, x, y, &dPdx, &dPdy); 
#line 514
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 516 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 517
tex2DGrad(::cudaTextureObject_t texObject, float x, float y, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 518
{ 
#line 519
T ret; 
#line 520
tex2DGrad(&ret, texObject, x, y, dPdx, dPdy); 
#line 521
return ret; 
#line 522
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 525 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 526
tex2DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 527
{ 
#line 528
unsigned char res; 
#line 529
__nv_tex_surf_handler("__itex2DGrad_sparse", ptr, obj, x, y, &dPdx, &dPdy, &res); 
#line 530
(*isResident) = (res != 0); 
#line 531
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 533 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 534
tex2DGrad(::cudaTextureObject_t texObject, float x, float y, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 535
{ 
#line 536
T ret; 
#line 537
tex2DGrad(&ret, texObject, x, y, dPdx, dPdy, isResident); 
#line 538
return ret; 
#line 539
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 543 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 544
tex3DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 545
{ 
#line 546
__nv_tex_surf_handler("__itex3DGrad_v2", ptr, obj, x, y, z, &dPdx, &dPdy); 
#line 547
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 549 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 550
tex3DGrad(::cudaTextureObject_t texObject, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 551
{ 
#line 552
T ret; 
#line 553
tex3DGrad(&ret, texObject, x, y, z, dPdx, dPdy); 
#line 554
return ret; 
#line 555
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 558 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 559
tex3DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, ::float4 dPdx, ::float4 dPdy, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 560
{ 
#line 561
unsigned char res; 
#line 562
__nv_tex_surf_handler("__itex3DGrad_sparse", ptr, obj, x, y, z, &dPdx, &dPdy, &res); 
#line 563
(*isResident) = (res != 0); 
#line 564
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 566 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 567
tex3DGrad(::cudaTextureObject_t texObject, float x, float y, float z, ::float4 dPdx, ::float4 dPdy, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 568
{ 
#line 569
T ret; 
#line 570
tex3DGrad(&ret, texObject, x, y, z, dPdx, dPdy, isResident); 
#line 571
return ret; 
#line 572
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 577 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 578
tex1DLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, int layer, float dPdx, float dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 579
{ 
#line 580
__nv_tex_surf_handler("__itex1DLayeredGrad", ptr, obj, x, layer, dPdx, dPdy); 
#line 581
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 583 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 584
tex1DLayeredGrad(::cudaTextureObject_t texObject, float x, int layer, float dPdx, float dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 585
{ 
#line 586
T ret; 
#line 587
tex1DLayeredGrad(&ret, texObject, x, layer, dPdx, dPdy); 
#line 588
return ret; 
#line 589
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 592 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 593
tex2DLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 594
{ 
#line 595
__nv_tex_surf_handler("__itex2DLayeredGrad_v2", ptr, obj, x, y, layer, &dPdx, &dPdy); 
#line 596
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 598 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 599
tex2DLayeredGrad(::cudaTextureObject_t texObject, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 600
{ 
#line 601
T ret; 
#line 602
tex2DLayeredGrad(&ret, texObject, x, y, layer, dPdx, dPdy); 
#line 603
return ret; 
#line 604
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 607 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 608
tex2DLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 609
{ 
#line 610
unsigned char res; 
#line 611
__nv_tex_surf_handler("__itex2DLayeredGrad_sparse", ptr, obj, x, y, layer, &dPdx, &dPdy, &res); 
#line 612
(*isResident) = (res != 0); 
#line 613
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 615 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 616
tex2DLayeredGrad(::cudaTextureObject_t texObject, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 617
{ 
#line 618
T ret; 
#line 619
tex2DLayeredGrad(&ret, texObject, x, y, layer, dPdx, dPdy, isResident); 
#line 620
return ret; 
#line 621
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 625 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 626
texCubemapLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, int layer, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 627
{ 
#line 628
__nv_tex_surf_handler("__itexCubemapLayeredGrad_v2", ptr, obj, x, y, z, layer, &dPdx, &dPdy); 
#line 629
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 631 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 632
texCubemapLayeredGrad(::cudaTextureObject_t texObject, float x, float y, float z, int layer, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 633
{ 
#line 634
T ret; 
#line 635
texCubemapLayeredGrad(&ret, texObject, x, y, z, layer, dPdx, dPdy); 
#line 636
return ret; 
#line 637
} 
#endif

__pragma(warning(pop))

#line 58 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> struct __nv_isurf_trait { }; 
#line 59
template<> struct __nv_isurf_trait< char>  { typedef void type; }; 
#line 60
template<> struct __nv_isurf_trait< signed char>  { typedef void type; }; 
#line 61
template<> struct __nv_isurf_trait< char1>  { typedef void type; }; 
#line 62
template<> struct __nv_isurf_trait< unsigned char>  { typedef void type; }; 
#line 63
template<> struct __nv_isurf_trait< uchar1>  { typedef void type; }; 
#line 64
template<> struct __nv_isurf_trait< short>  { typedef void type; }; 
#line 65
template<> struct __nv_isurf_trait< short1>  { typedef void type; }; 
#line 66
template<> struct __nv_isurf_trait< unsigned short>  { typedef void type; }; 
#line 67
template<> struct __nv_isurf_trait< ushort1>  { typedef void type; }; 
#line 68
template<> struct __nv_isurf_trait< int>  { typedef void type; }; 
#line 69
template<> struct __nv_isurf_trait< int1>  { typedef void type; }; 
#line 70
template<> struct __nv_isurf_trait< unsigned>  { typedef void type; }; 
#line 71
template<> struct __nv_isurf_trait< uint1>  { typedef void type; }; 
#line 72
template<> struct __nv_isurf_trait< __int64>  { typedef void type; }; 
#line 73
template<> struct __nv_isurf_trait< longlong1>  { typedef void type; }; 
#line 74
template<> struct __nv_isurf_trait< unsigned __int64>  { typedef void type; }; 
#line 75
template<> struct __nv_isurf_trait< ulonglong1>  { typedef void type; }; 
#line 76
template<> struct __nv_isurf_trait< float>  { typedef void type; }; 
#line 77
template<> struct __nv_isurf_trait< float1>  { typedef void type; }; 
#line 79
template<> struct __nv_isurf_trait< char2>  { typedef void type; }; 
#line 80
template<> struct __nv_isurf_trait< uchar2>  { typedef void type; }; 
#line 81
template<> struct __nv_isurf_trait< short2>  { typedef void type; }; 
#line 82
template<> struct __nv_isurf_trait< ushort2>  { typedef void type; }; 
#line 83
template<> struct __nv_isurf_trait< int2>  { typedef void type; }; 
#line 84
template<> struct __nv_isurf_trait< uint2>  { typedef void type; }; 
#line 85
template<> struct __nv_isurf_trait< longlong2>  { typedef void type; }; 
#line 86
template<> struct __nv_isurf_trait< ulonglong2>  { typedef void type; }; 
#line 87
template<> struct __nv_isurf_trait< float2>  { typedef void type; }; 
#line 89
template<> struct __nv_isurf_trait< char4>  { typedef void type; }; 
#line 90
template<> struct __nv_isurf_trait< uchar4>  { typedef void type; }; 
#line 91
template<> struct __nv_isurf_trait< short4>  { typedef void type; }; 
#line 92
template<> struct __nv_isurf_trait< ushort4>  { typedef void type; }; 
#line 93
template<> struct __nv_isurf_trait< int4>  { typedef void type; }; 
#line 94
template<> struct __nv_isurf_trait< uint4>  { typedef void type; }; 
#line 95
template<> struct __nv_isurf_trait< float4>  { typedef void type; }; 
__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 98
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 99
surf1Dread(T *ptr, ::cudaSurfaceObject_t obj, int x, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)mode;::exit(___);}
#if 0
#line 100
{ 
#line 101
__nv_tex_surf_handler("__isurf1Dread", ptr, obj, x, mode); 
#line 102
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 105
surf1Dread(::cudaSurfaceObject_t surfObject, int x, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)boundaryMode;::exit(___);}
#if 0
#line 106
{ 
#line 107
T ret; 
#line 108
surf1Dread(&ret, surfObject, x, boundaryMode); 
#line 109
return ret; 
#line 110
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 113
surf2Dread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)mode;::exit(___);}
#if 0
#line 114
{ 
#line 115
__nv_tex_surf_handler("__isurf2Dread", ptr, obj, x, y, mode); 
#line 116
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 119
surf2Dread(::cudaSurfaceObject_t surfObject, int x, int y, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)boundaryMode;::exit(___);}
#if 0
#line 120
{ 
#line 121
T ret; 
#line 122
surf2Dread(&ret, surfObject, x, y, boundaryMode); 
#line 123
return ret; 
#line 124
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 127 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 128
surf3Dread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int z, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)mode;::exit(___);}
#if 0
#line 129
{ 
#line 130
__nv_tex_surf_handler("__isurf3Dread", ptr, obj, x, y, z, mode); 
#line 131
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 134
surf3Dread(::cudaSurfaceObject_t surfObject, int x, int y, int z, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)z;(void)boundaryMode;::exit(___);}
#if 0
#line 135
{ 
#line 136
T ret; 
#line 137
surf3Dread(&ret, surfObject, x, y, z, boundaryMode); 
#line 138
return ret; 
#line 139
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 142
surf1DLayeredread(T *ptr, ::cudaSurfaceObject_t obj, int x, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)mode;::exit(___);}
#if 0
#line 143
{ 
#line 144
__nv_tex_surf_handler("__isurf1DLayeredread", ptr, obj, x, layer, mode); 
#line 145
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 148
surf1DLayeredread(::cudaSurfaceObject_t surfObject, int x, int layer, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)layer;(void)boundaryMode;::exit(___);}
#if 0
#line 149
{ 
#line 150
T ret; 
#line 151
surf1DLayeredread(&ret, surfObject, x, layer, boundaryMode); 
#line 152
return ret; 
#line 153
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 155 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 156
surf2DLayeredread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)mode;::exit(___);}
#if 0
#line 157
{ 
#line 158
__nv_tex_surf_handler("__isurf2DLayeredread", ptr, obj, x, y, layer, mode); 
#line 159
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 162
surf2DLayeredread(::cudaSurfaceObject_t surfObject, int x, int y, int layer, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layer;(void)boundaryMode;::exit(___);}
#if 0
#line 163
{ 
#line 164
T ret; 
#line 165
surf2DLayeredread(&ret, surfObject, x, y, layer, boundaryMode); 
#line 166
return ret; 
#line 167
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 169 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 170
surfCubemapread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int face, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)face;(void)mode;::exit(___);}
#if 0
#line 171
{ 
#line 172
__nv_tex_surf_handler("__isurfCubemapread", ptr, obj, x, y, face, mode); 
#line 173
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 176
surfCubemapread(::cudaSurfaceObject_t surfObject, int x, int y, int face, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)face;(void)boundaryMode;::exit(___);}
#if 0
#line 177
{ 
#line 178
T ret; 
#line 179
surfCubemapread(&ret, surfObject, x, y, face, boundaryMode); 
#line 180
return ret; 
#line 181
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 184
surfCubemapLayeredread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int layerface, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layerface;(void)mode;::exit(___);}
#if 0
#line 185
{ 
#line 186
__nv_tex_surf_handler("__isurfCubemapLayeredread", ptr, obj, x, y, layerface, mode); 
#line 187
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 190
surfCubemapLayeredread(::cudaSurfaceObject_t surfObject, int x, int y, int layerface, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layerface;(void)boundaryMode;::exit(___);}
#if 0
#line 191
{ 
#line 192
T ret; 
#line 193
surfCubemapLayeredread(&ret, surfObject, x, y, layerface, boundaryMode); 
#line 194
return ret; 
#line 195
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 197 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 198
surf1Dwrite(T val, ::cudaSurfaceObject_t obj, int x, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)mode;::exit(___);}
#if 0
#line 199
{ 
#line 200
__nv_tex_surf_handler("__isurf1Dwrite_v2", &val, obj, x, mode); 
#line 201
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 203 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 204
surf2Dwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)mode;::exit(___);}
#if 0
#line 205
{ 
#line 206
__nv_tex_surf_handler("__isurf2Dwrite_v2", &val, obj, x, y, mode); 
#line 207
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 209 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 210
surf3Dwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int z, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)z;(void)mode;::exit(___);}
#if 0
#line 211
{ 
#line 212
__nv_tex_surf_handler("__isurf3Dwrite_v2", &val, obj, x, y, z, mode); 
#line 213
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 215 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 216
surf1DLayeredwrite(T val, ::cudaSurfaceObject_t obj, int x, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)layer;(void)mode;::exit(___);}
#if 0
#line 217
{ 
#line 218
__nv_tex_surf_handler("__isurf1DLayeredwrite_v2", &val, obj, x, layer, mode); 
#line 219
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 221 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 222
surf2DLayeredwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)layer;(void)mode;::exit(___);}
#if 0
#line 223
{ 
#line 224
__nv_tex_surf_handler("__isurf2DLayeredwrite_v2", &val, obj, x, y, layer, mode); 
#line 225
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 227 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 228
surfCubemapwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int face, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)face;(void)mode;::exit(___);}
#if 0
#line 229
{ 
#line 230
__nv_tex_surf_handler("__isurfCubemapwrite_v2", &val, obj, x, y, face, mode); 
#line 231
} 
#endif

__pragma(warning(pop))

__pragma(warning(push))
__pragma(warning(disable : 4505)) /* "unreferenced local function has been removed" */

#line 233 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 234
surfCubemapLayeredwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int layerface, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)layerface;(void)mode;::exit(___);}
#if 0
#line 235
{ 
#line 236
__nv_tex_surf_handler("__isurfCubemapLayeredwrite_v2", &val, obj, x, y, layerface, mode); 
#line 237
} 
#endif

__pragma(warning(pop))

#line 2924 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/device_functions.h"
extern "C" unsigned __stdcall __cudaPushCallConfiguration(dim3 gridDim, dim3 blockDim = 1, size_t sharedMem = 0, CUstream_st * stream = 0); 
#line 2930
extern "C" cudaError_t __stdcall __cudaGetKernel(cudaKernel_t *, const void *); 
#line 2932
extern "C" cudaError_t __stdcall __cudaLaunchKernel(cudaKernel_t kernel, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
#line 2941
extern "C" cudaError_t __stdcall __cudaLaunchKernel_ptsz(cudaKernel_t kernel, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
#line 2951
static inline cudaError_t __cudaLaunchKernel_helper(cudaKernel_t 
#line 2952
kernel, dim3 
#line 2953
gridDim, dim3 
#line 2954
blockDim, void **
#line 2955
args, size_t 
#line 2956
sharedMem, cudaStream_t 
#line 2957
stream) 
#line 2958
{ 
#line 2963 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/device_functions.h"
return __cudaLaunchKernel(kernel, gridDim, blockDim, args, sharedMem, stream); 
#line 2966 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/device_functions.h"
} 
#line 2969 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\crt/device_functions.h"
enum { 
#line 2970
__NV_ATOMIC_RELAXED, 
#line 2971
__NV_ATOMIC_CONSUME, 
#line 2972
__NV_ATOMIC_ACQUIRE, 
#line 2973
__NV_ATOMIC_RELEASE, 
#line 2974
__NV_ATOMIC_ACQ_REL, 
#line 2975
__NV_ATOMIC_SEQ_CST
#line 2976
}; 
#line 2978
enum { 
#line 2979
__NV_THREAD_SCOPE_THREAD, 
#line 2980
__NV_THREAD_SCOPE_BLOCK, 
#line 2981
__NV_THREAD_SCOPE_CLUSTER, 
#line 2982
__NV_THREAD_SCOPE_DEVICE, 
#line 2983
__NV_THREAD_SCOPE_SYSTEM
#line 2984
}; 
#line 68 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_launch_parameters.h"
extern "C" {
#line 71 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v13.0\\include\\device_launch_parameters.h"
extern const uint3 __device_builtin_variable_threadIdx; 
#line 72
extern const uint3 __device_builtin_variable_blockIdx; 
#line 73
extern const dim3 __device_builtin_variable_blockDim; 
#line 74
extern const dim3 __device_builtin_variable_gridDim; 
#line 75
extern const int __device_builtin_variable_warpSize; 
#line 80
}
#line 14 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cstddef"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 27
namespace std { 
#line 28
using ::ptrdiff_t;
#line 30
using max_align_t = double; 
#line 31
using nullptr_t = decltype(nullptr); 
#line 99
}
#line 102
using std::max_align_t;
#line 111
#pragma warning(pop)
#pragma pack ( pop )
#line 12 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\initializer_list"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 19
namespace std { 
#line 20
template < class _Elem >
class initializer_list {
public :
    using value_type = _Elem;
    using reference = const _Elem &;
    using const_reference = const _Elem &;
    using size_type = size_t;

    using iterator = const _Elem *;
    using const_iterator = const _Elem *;

    constexpr initializer_list ( ) noexcept : _First ( nullptr ), _Last ( nullptr ) { }

    constexpr initializer_list ( const _Elem * _First_arg, const _Elem * _Last_arg ) noexcept
        : _First ( _First_arg ), _Last ( _Last_arg ) { }

    [ [ nodiscard ] ] constexpr const _Elem * begin ( ) const noexcept {
        return _First;
    }

    [ [ nodiscard ] ] constexpr const _Elem * end ( ) const noexcept {
        return _Last;
    }

    [ [ nodiscard ] ] constexpr size_t size ( ) const noexcept {
        return static_cast < size_t > ( _Last - _First );
    }

private :
    const _Elem * _First;
    const _Elem * _Last;
};
#line 53
template < class _Elem >
[ [ nodiscard ] ] constexpr const _Elem * begin ( initializer_list < _Elem > _Ilist ) noexcept {
    return _Ilist . begin ( );
}
#line 58
template < class _Elem >
[ [ nodiscard ] ] constexpr const _Elem * end ( initializer_list < _Elem > _Ilist ) noexcept {
    return _Ilist . end ( );
}
#line 62
}
#line 65
#pragma warning(pop)
#pragma pack ( pop )
#line 15 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\stdint.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 18
typedef signed char int8_t; 
#line 19
typedef short int16_t; 
#line 20
typedef int int32_t; 
#line 21
typedef __int64 int64_t; 
#line 22
typedef unsigned char uint8_t; 
#line 23
typedef unsigned short uint16_t; 
#line 24
typedef unsigned uint32_t; 
#line 25
typedef unsigned __int64 uint64_t; 
#line 27
typedef signed char int_least8_t; 
#line 28
typedef short int_least16_t; 
#line 29
typedef int int_least32_t; 
#line 30
typedef __int64 int_least64_t; 
#line 31
typedef unsigned char uint_least8_t; 
#line 32
typedef unsigned short uint_least16_t; 
#line 33
typedef unsigned uint_least32_t; 
#line 34
typedef unsigned __int64 uint_least64_t; 
#line 36
typedef signed char int_fast8_t; 
#line 37
typedef int int_fast16_t; 
#line 38
typedef int int_fast32_t; 
#line 39
typedef __int64 int_fast64_t; 
#line 40
typedef unsigned char uint_fast8_t; 
#line 41
typedef unsigned uint_fast16_t; 
#line 42
typedef unsigned uint_fast32_t; 
#line 43
typedef unsigned __int64 uint_fast64_t; 
#line 45
typedef __int64 intmax_t; 
#line 46
typedef unsigned __int64 uintmax_t; 
#line 136 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\stdint.h"
#pragma warning(pop)
#line 13 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cstdint"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 20
namespace std { 
#line 21
using ::int8_t;
#line 22
using ::int16_t;
#line 23
using ::int32_t;
#line 24
using ::int64_t;
#line 25
using ::uint8_t;
#line 26
using ::uint16_t;
#line 27
using ::uint32_t;
#line 28
using ::uint64_t;
#line 30
using ::int_least8_t;
#line 31
using ::int_least16_t;
#line 32
using ::int_least32_t;
#line 33
using ::int_least64_t;
#line 34
using ::uint_least8_t;
#line 35
using ::uint_least16_t;
#line 36
using ::uint_least32_t;
#line 37
using ::uint_least64_t;
#line 39
using ::int_fast8_t;
#line 40
using ::int_fast16_t;
#line 41
using ::int_fast32_t;
#line 42
using ::int_fast64_t;
#line 43
using ::uint_fast8_t;
#line 44
using ::uint_fast16_t;
#line 45
using ::uint_fast32_t;
#line 46
using ::uint_fast64_t;
#line 48
using ::intmax_t;
#line 49
using ::intptr_t;
#line 50
using ::uintmax_t;
#line 51
using ::uintptr_t;
#line 54
namespace [[deprecated("warning STL4002: The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can define _" "SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to suppress this warning.")]] tr1 { 
#line 55
using ::int8_t;
#line 56
using ::int16_t;
#line 57
using ::int32_t;
#line 58
using ::int64_t;
#line 59
using ::uint8_t;
#line 60
using ::uint16_t;
#line 61
using ::uint32_t;
#line 62
using ::uint64_t;
#line 64
using ::int_least8_t;
#line 65
using ::int_least16_t;
#line 66
using ::int_least32_t;
#line 67
using ::int_least64_t;
#line 68
using ::uint_least8_t;
#line 69
using ::uint_least16_t;
#line 70
using ::uint_least32_t;
#line 71
using ::uint_least64_t;
#line 73
using ::int_fast8_t;
#line 74
using ::int_fast16_t;
#line 75
using ::int_fast32_t;
#line 76
using ::int_fast64_t;
#line 77
using ::uint_fast8_t;
#line 78
using ::uint_fast16_t;
#line 79
using ::uint_fast32_t;
#line 80
using ::uint_fast64_t;
#line 82
using ::intmax_t;
#line 83
using ::intptr_t;
#line 84
using ::uintmax_t;
#line 85
using ::uintptr_t;
#line 86
}
#line 88 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cstdint"
}
#line 92
#pragma warning(pop)
#pragma pack ( pop )
#line 13 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\cstring"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 20
namespace std { 
#pragma warning(push)
#pragma warning(disable : 4995)
#line 25
using ::memchr;
#line 26
using ::memcmp;
#line 27
using ::memcpy;
#line 28
using ::memmove;
#line 29
using ::memset;
#line 30
using ::strcat;
#line 31
using ::strchr;
#line 32
using ::strcmp;
#line 33
using ::strcoll;
#line 34
using ::strcpy;
#line 35
using ::strcspn;
#line 36
using ::strerror;
#line 37
using ::strlen;
#line 38
using ::strncat;
#line 39
using ::strncmp;
#line 40
using ::strncpy;
#line 41
using ::strpbrk;
#line 42
using ::strrchr;
#line 43
using ::strspn;
#line 44
using ::strstr;
#line 45
using ::strtok;
#line 46
using ::strxfrm;
#line 48
#pragma warning(pop)
}
#line 53
#pragma warning(pop)
#pragma pack ( pop )
#line 15 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 30
namespace std { 
#line 31
template< class > constexpr bool 
#line 32
_Always_false = false; 
#line 34
template< bool _First_value, class _First, class ..._Rest> 
#line 35
struct _Conjunction { 
#line 36
using type = _First; 
#line 37
}; 
#line 39
template< class _True, class _Next, class ..._Rest> 
#line 40
struct _Conjunction< true, _True, _Next, _Rest...>  { 
#line 41
using type = typename std::_Conjunction< static_cast< bool>(_Next::value), _Next, _Rest...> ::type; 
#line 42
}; 
#line 44
template< class ..._Traits> 
#line 45
struct conjunction : public true_type { }; 
#line 47
template< class _First, class ..._Rest> 
#line 48
struct conjunction< _First, _Rest...>  : public _Conjunction< static_cast< bool>(_First::value), _First, _Rest...> ::type { 
#line 50
}; 
#line 52
template< class ..._Traits> constexpr bool 
#line 53
conjunction_v = (conjunction< _Traits...> ::value); 
#line 55
template< class _Trait> 
#line 56
struct negation : public bool_constant< !(static_cast< bool>(_Trait::value))>  { }; 
#line 58
template< class _Trait> constexpr bool 
#line 59
negation_v = (negation< _Trait> ::value); 
#line 61
template< class _Ty> constexpr bool 
#line 62
is_void_v = is_same_v< remove_cv_t< _Ty> , void> ; 
#line 64
template< class _Ty> 
#line 65
struct is_void : public bool_constant< is_void_v< _Ty> >  { }; 
#line 67
template< class ..._Types> using void_t = void; 
#line 70
template< class _Ty> 
#line 71
struct _Identity { 
#line 72
using type = _Ty; 
#line 73
}; 
#line 74
template< class _Ty> using _Identity_t
#line 75
 [[msvc::known_semantics]] = typename _Identity< _Ty> ::type; 
#line 78
template< class _Ty> 
#line 79
struct add_const { 
#line 80
using type = const _Ty; 
#line 81
}; 
#line 83
template< class _Ty> using add_const_t = typename add_const< _Ty> ::type; 
#line 86
template< class _Ty> 
#line 87
struct add_volatile { 
#line 88
using type = volatile _Ty; 
#line 89
}; 
#line 91
template< class _Ty> using add_volatile_t = typename add_volatile< _Ty> ::type; 
#line 94
template< class _Ty> 
#line 95
struct add_cv { 
#line 96
using type = const volatile _Ty; 
#line 97
}; 
#line 99
template< class _Ty> using add_cv_t = typename add_cv< _Ty> ::type; 
#line 102
template< class _Ty, class  = void> 
#line 103
struct _Add_reference { 
#line 104
using _Lvalue = _Ty; 
#line 105
using _Rvalue = _Ty; 
#line 106
}; 
#line 108
template< class _Ty> 
#line 109
struct _Add_reference< _Ty, void_t< _Ty &> >  { 
#line 110
using _Lvalue = _Ty &; 
#line 111
using _Rvalue = _Ty &&; 
#line 112
}; 
#line 114
template< class _Ty> 
#line 115
struct add_lvalue_reference { 
#line 116
using type = typename _Add_reference< _Ty> ::_Lvalue; 
#line 117
}; 
#line 119
template< class _Ty> using add_lvalue_reference_t = typename _Add_reference< _Ty> ::_Lvalue; 
#line 122
template< class _Ty> 
#line 123
struct add_rvalue_reference { 
#line 124
using type = typename _Add_reference< _Ty> ::_Rvalue; 
#line 125
}; 
#line 127
template< class _Ty> using add_rvalue_reference_t = typename _Add_reference< _Ty> ::_Rvalue; 
#line 130
template < class _Ty >
add_rvalue_reference_t < _Ty > declval ( ) noexcept {
    static_assert ( false, "Calling declval is ill-formed, see N4950 [declval]/2." );
}
#line 135
template< class _Ty> 
#line 136
struct remove_extent { 
#line 137
using type = _Ty; 
#line 138
}; 
#line 140
template< class _Ty, size_t _Ix> 
#line 141
struct remove_extent< _Ty [_Ix]>  { 
#line 142
using type = _Ty; 
#line 143
}; 
#line 145
template< class _Ty> 
#line 146
struct remove_extent< _Ty []>  { 
#line 147
using type = _Ty; 
#line 148
}; 
#line 150
template< class _Ty> using remove_extent_t = typename remove_extent< _Ty> ::type; 
#line 153
template< class _Ty> 
#line 154
struct remove_all_extents { 
#line 155
using type = _Ty; 
#line 156
}; 
#line 158
template< class _Ty, size_t _Ix> 
#line 159
struct remove_all_extents< _Ty [_Ix]>  { 
#line 160
using type = typename std::remove_all_extents< _Ty> ::type; 
#line 161
}; 
#line 163
template< class _Ty> 
#line 164
struct remove_all_extents< _Ty []>  { 
#line 165
using type = typename std::remove_all_extents< _Ty> ::type; 
#line 166
}; 
#line 168
template< class _Ty> using remove_all_extents_t = typename remove_all_extents< _Ty> ::type; 
#line 171
template< class _Ty> 
#line 172
struct remove_pointer { 
#line 173
using type = _Ty; 
#line 174
}; 
#line 176
template< class _Ty> 
#line 177
struct remove_pointer< _Ty *>  { 
#line 178
using type = _Ty; 
#line 179
}; 
#line 181
template< class _Ty> 
#line 182
struct remove_pointer< _Ty *const>  { 
#line 183
using type = _Ty; 
#line 184
}; 
#line 186
template< class _Ty> 
#line 187
struct remove_pointer< _Ty *volatile>  { 
#line 188
using type = _Ty; 
#line 189
}; 
#line 191
template< class _Ty> 
#line 192
struct remove_pointer< _Ty *const volatile>  { 
#line 193
using type = _Ty; 
#line 194
}; 
#line 196
template< class _Ty> using remove_pointer_t = typename remove_pointer< _Ty> ::type; 
#line 199
template< class _Ty, class  = void> 
#line 200
struct _Add_pointer { 
#line 201
using type = _Ty; 
#line 202
}; 
#line 204
template< class _Ty> 
#line 205
struct _Add_pointer< _Ty, void_t< remove_reference_t< _Ty>  *> >  { 
#line 206
using type = remove_reference_t< _Ty>  *; 
#line 207
}; 
#line 209
template< class _Ty> 
#line 210
struct add_pointer { 
#line 211
using type = typename _Add_pointer< _Ty> ::type; 
#line 212
}; 
#line 214
template< class _Ty> using add_pointer_t = typename _Add_pointer< _Ty> ::type; 
#line 217
template< class > constexpr bool 
#line 218
is_array_v = false; 
#line 220
template< class _Ty, size_t _Nx> constexpr bool 
#line 221
is_array_v< _Ty [_Nx]>  = true; 
#line 223
template< class _Ty> constexpr bool 
#line 224
is_array_v< _Ty []>  = true; 
#line 226
template< class _Ty> 
#line 227
struct is_array : public bool_constant< is_array_v< _Ty> >  { }; 
#line 249 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class > constexpr bool 
#line 250
is_lvalue_reference_v = false; 
#line 252
template< class _Ty> constexpr bool 
#line 253
is_lvalue_reference_v< _Ty &>  = true; 
#line 255
template< class _Ty> 
#line 256
struct is_lvalue_reference : public bool_constant< is_lvalue_reference_v< _Ty> >  { }; 
#line 258
template< class > constexpr bool 
#line 259
is_rvalue_reference_v = false; 
#line 261
template< class _Ty> constexpr bool 
#line 262
is_rvalue_reference_v< _Ty &&>  = true; 
#line 264
template< class _Ty> 
#line 265
struct is_rvalue_reference : public bool_constant< is_rvalue_reference_v< _Ty> >  { }; 
#line 267
template< class > constexpr bool 
#line 268
is_reference_v = false; 
#line 270
template< class _Ty> constexpr bool 
#line 271
is_reference_v< _Ty &>  = true; 
#line 273
template< class _Ty> constexpr bool 
#line 274
is_reference_v< _Ty &&>  = true; 
#line 276
template< class _Ty> 
#line 277
struct is_reference : public bool_constant< is_reference_v< _Ty> >  { }; 
#line 279
template< class > constexpr bool 
#line 280
is_pointer_v = false; 
#line 282
template< class _Ty> constexpr bool 
#line 283
is_pointer_v< _Ty *>  = true; 
#line 285
template< class _Ty> constexpr bool 
#line 286
is_pointer_v< _Ty *const>  = true; 
#line 288
template< class _Ty> constexpr bool 
#line 289
is_pointer_v< _Ty *volatile>  = true; 
#line 291
template< class _Ty> constexpr bool 
#line 292
is_pointer_v< _Ty *const volatile>  = true; 
#line 294
template< class _Ty> 
#line 295
struct is_pointer : public bool_constant< is_pointer_v< _Ty> >  { }; 
#line 297
template< class _Ty> constexpr bool 
#line 298
is_null_pointer_v = is_same_v< remove_cv_t< _Ty> , std::nullptr_t> ; 
#line 301
template< class _Ty> 
#line 302
struct is_null_pointer : public bool_constant< is_null_pointer_v< _Ty> >  { }; 
#line 304
template< class _Ty> 
#line 305
struct is_union : public bool_constant< __is_union(_Ty)>  { }; 
#line 307
template< class _Ty> constexpr bool 
#line 308
is_union_v = __is_union(_Ty); 
#line 310
template< class _Ty> 
#line 311
struct is_class : public bool_constant< __is_class(_Ty)>  { }; 
#line 313
template< class _Ty> constexpr bool 
#line 314
is_class_v = __is_class(_Ty); 
#line 316
template< class _Ty> constexpr bool 
#line 317
is_fundamental_v = (is_arithmetic_v< _Ty>  || is_void_v< _Ty> ) || is_null_pointer_v< _Ty> ; 
#line 319
template< class _Ty> 
#line 320
struct is_fundamental : public bool_constant< is_fundamental_v< _Ty> >  { }; 
#line 322
template< class _From, class _To> 
#line 323
struct is_convertible : public bool_constant< __is_convertible_to(_From, _To)>  { 
#line 325
}; 
#line 327
template< class _From, class _To> constexpr bool 
#line 328
is_convertible_v = __is_convertible_to(_From, _To); 
#line 330
template< class _Ty> 
#line 331
struct is_enum : public bool_constant< __is_enum(_Ty)>  { }; 
#line 333
template< class _Ty> constexpr bool 
#line 334
is_enum_v = __is_enum(_Ty); 
#line 344 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 345
struct is_compound : public bool_constant< !is_fundamental_v< _Ty> >  { }; 
#line 347
template< class _Ty> constexpr bool 
#line 348
is_compound_v = (!is_fundamental_v< _Ty> ); 
#line 473 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class ..._Types> 
#line 474
struct _Arg_types { }; 
#line 476
template< class _Ty1> 
#line 477
struct _Arg_types< _Ty1>  { 
#line 478
using argument_type = _Ty1; 
#line 479
}; 
#line 481
template< class _Ty1, class _Ty2> 
#line 482
struct _Arg_types< _Ty1, _Ty2>  { 
#line 483
using first_argument_type = _Ty1; 
#line 484
using second_argument_type = _Ty2; 
#line 485
}; 
#line 487
template< class _Ty> 
#line 488
struct _Is_memfunptr { 
#line 489
using _Bool_type = false_type; 
#line 490
}; 
#line 502
template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...)>  : public _Arg_types< _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...)>  : public _Arg_types< _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) const>  : public _Arg_types< const _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) const>  : public _Arg_types< const _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) volatile>  : public _Arg_types< volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) volatile>  : public _Arg_types< volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) const volatile>  : public _Arg_types< const volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) const volatile>  : public _Arg_types< const volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) &>  : public _Arg_types< _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) &>  : public _Arg_types< _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) const &>  : public _Arg_types< const _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) const &>  : public _Arg_types< const _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) volatile &>  : public _Arg_types< volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) volatile &>  : public _Arg_types< volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) const volatile &>  : public _Arg_types< const volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) const volatile &>  : public _Arg_types< const volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< true, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) &&>  : public _Arg_types< _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) &&>  : public _Arg_types< _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) const &&>  : public _Arg_types< const _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) const &&>  : public _Arg_types< const _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) volatile &&>  : public _Arg_types< volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) volatile &&>  : public _Arg_types< volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__cdecl _Arg0::*)(_Types ...) const volatile &&>  : public _Arg_types< const volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (__vectorcall _Arg0::*)(_Types ...) const volatile &&>  : public _Arg_types< const volatile _Arg0 *, _Types...>  { using _Bool_type = std::true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false, _Ret (_Types ...)> ; }; 
#line 515
template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...)>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) const>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) volatile>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) const volatile>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) &>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) const &>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) volatile &>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) const volatile &>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) &&>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) const &&>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) volatile &&>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; template< class _Ret, class _Arg0, class ..._Types> struct _Is_memfunptr< _Ret (_Arg0::*)(_Types ..., ...) const volatile &&>  { using _Bool_type = true_type; using result_type = _Ret; using _Class_type = _Arg0; using _Guide_type = enable_if< false> ; }; 
#line 538 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> constexpr bool 
#line 539
is_member_function_pointer_v = (_Is_memfunptr< remove_cv_t< _Ty> > ::_Bool_type::value); 
#line 542 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 543
struct is_member_function_pointer : public bool_constant< is_member_function_pointer_v< _Ty> >  { }; 
#line 545
template< class > constexpr bool 
#line 546
is_const_v = false; 
#line 548
template< class _Ty> constexpr bool 
#line 549
is_const_v< const _Ty>  = true; 
#line 551
template< class _Ty> 
#line 552
struct is_const : public bool_constant< is_const_v< _Ty> >  { }; 
#line 554
template< class > constexpr bool 
#line 555
is_volatile_v = false; 
#line 557
template< class _Ty> constexpr bool 
#line 558
is_volatile_v< volatile _Ty>  = true; 
#line 560
template< class _Ty> 
#line 561
struct is_volatile : public bool_constant< is_volatile_v< _Ty> >  { }; 
#line 563
template< class _Ty> constexpr bool 
#line 564
is_function_v = ((!is_const_v< const _Ty> ) && (!is_reference_v< _Ty> )); 
#line 567
template< class _Ty> 
#line 568
struct is_function : public bool_constant< is_function_v< _Ty> >  { }; 
#line 570
template< class _Ty> constexpr bool 
#line 571
is_object_v = is_const_v< const _Ty>  && (!is_void_v< _Ty> ); 
#line 574
template< class _Ty> 
#line 575
struct is_object : public bool_constant< is_object_v< _Ty> >  { }; 
#line 577
template< class > 
#line 578
struct _Is_member_object_pointer { 
#line 579
static constexpr bool value = false; 
#line 580
}; 
#line 582
template< class _Ty1, class _Ty2> 
#line 583
struct _Is_member_object_pointer< _Ty1 _Ty2::*>  { 
#line 584
static constexpr bool value = (!is_function_v< _Ty1> ); 
#line 585
using _Class_type = _Ty2; 
#line 586
}; 
#line 592
template< class _Ty> constexpr bool 
#line 593
is_member_object_pointer_v = (_Is_member_object_pointer< remove_cv_t< _Ty> > ::value); 
#line 596 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 597
struct is_member_object_pointer : public bool_constant< is_member_object_pointer_v< _Ty> >  { }; 
#line 603
template< class _Ty> constexpr bool 
#line 604
is_member_pointer_v = is_member_object_pointer_v< _Ty>  || is_member_function_pointer_v< _Ty> ; 
#line 607 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 608
struct is_member_pointer : public bool_constant< is_member_pointer_v< _Ty> >  { }; 
#line 610
template< class _Ty> constexpr bool 
#line 611
is_scalar_v = (((is_arithmetic_v< _Ty>  || is_enum_v< _Ty> ) || is_pointer_v< _Ty> ) || is_member_pointer_v< _Ty> ) || is_null_pointer_v< _Ty> ; 
#line 614
template< class _Ty> 
#line 615
struct is_scalar : public bool_constant< is_scalar_v< _Ty> >  { }; 
#line 617
template< class _Ty> 
#line 618
struct is_pod : public bool_constant< __is_pod(_Ty)>  { }; 
#line 620
template< class _Ty> constexpr bool 
#line 621
is_pod_v = __is_pod(_Ty); 
#line 623
template< class _Ty> 
#line 624
struct is_empty : public bool_constant< __is_empty(_Ty)>  { }; 
#line 626
template< class _Ty> constexpr bool 
#line 627
is_empty_v = __is_empty(_Ty); 
#line 629
template< class _Ty> 
#line 630
struct is_polymorphic : public bool_constant< __is_polymorphic(_Ty)>  { }; 
#line 632
template< class _Ty> constexpr bool 
#line 633
is_polymorphic_v = __is_polymorphic(_Ty); 
#line 635
template< class _Ty> 
#line 636
struct is_abstract : public bool_constant< __is_abstract(_Ty)>  { }; 
#line 638
template< class _Ty> constexpr bool 
#line 639
is_abstract_v = __is_abstract(_Ty); 
#line 641
template< class _Ty> 
#line 642
struct is_final : public bool_constant< __is_final(_Ty)>  { }; 
#line 644
template< class _Ty> constexpr bool 
#line 645
is_final_v = __is_final(_Ty); 
#line 647
template< class _Ty> 
#line 648
struct is_standard_layout : public bool_constant< __is_standard_layout(_Ty)>  { }; 
#line 650
template< class _Ty> constexpr bool 
#line 651
is_standard_layout_v = __is_standard_layout(_Ty); 
#line 654
template< class _Ty> 
#line 655
struct is_literal_type : public bool_constant< __is_literal_type(_Ty)>  { 
#line 657
}; 
#line 659
template< class _Ty> constexpr bool 
#line 660
is_literal_type_v = __is_literal_type(_Ty); 
#line 663 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 664
struct is_trivial : public bool_constant< __is_trivial(_Ty)>  { }; 
#line 666
template< class _Ty> constexpr bool 
#line 667
is_trivial_v = __is_trivial(_Ty); 
#line 669
template< class _Ty> 
#line 670
struct is_trivially_copyable : public bool_constant< __is_trivially_copyable(_Ty)>  { 
#line 672
}; 
#line 674
template< class _Ty> constexpr bool 
#line 675
is_trivially_copyable_v = __is_trivially_copyable(_Ty); 
#line 677
template< class _Ty> 
#line 678
struct has_virtual_destructor : public bool_constant< __has_virtual_destructor(_Ty)>  { 
#line 680
}; 
#line 682
template< class _Ty> constexpr bool 
#line 683
has_virtual_destructor_v = __has_virtual_destructor(_Ty); 
#line 712 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty, class ..._Args> 
#line 713
struct is_constructible : public bool_constant< __is_constructible(_Ty, _Args...)>  { 
#line 715
}; 
#line 717
template< class _Ty, class ..._Args> constexpr bool 
#line 718
is_constructible_v = __is_constructible(_Ty, _Args...); 
#line 720
template< class _Ty> 
#line 721
struct is_copy_constructible : public bool_constant< __is_constructible(_Ty, add_lvalue_reference_t< const _Ty> )>  { 
#line 723
}; 
#line 725
template< class _Ty> constexpr bool 
#line 726
is_copy_constructible_v = __is_constructible(_Ty, add_lvalue_reference_t< const _Ty> ); 
#line 728
template< class _Ty> 
#line 729
struct is_default_constructible : public bool_constant< __is_constructible(_Ty)>  { 
#line 731
}; 
#line 733
template< class _Ty> constexpr bool 
#line 734
is_default_constructible_v = __is_constructible(_Ty); 
#line 736
template< class _Ty, class  = void> 
#line 737
struct _Is_implicitly_default_constructible : public false_type { 
#line 739
}; 
#line 741
template< class _Ty> void _Implicitly_default_construct(const _Ty &); 
#line 744
template< class _Ty> 
#line 745
struct _Is_implicitly_default_constructible< _Ty, void_t< decltype(_Implicitly_default_construct< _Ty> ({}))> >  : public true_type { 
#line 746
}; 
#line 748
template< class _Ty> 
#line 749
struct is_move_constructible : public bool_constant< __is_constructible(_Ty, _Ty)>  { 
#line 751
}; 
#line 753
template< class _Ty> constexpr bool 
#line 754
is_move_constructible_v = __is_constructible(_Ty, _Ty); 
#line 756
template< class _To, class _From> 
#line 757
struct is_assignable : public bool_constant< __is_assignable(_To, _From)>  { }; 
#line 759
template< class _To, class _From> constexpr bool 
#line 760
is_assignable_v = __is_assignable(_To, _From); 
#line 766 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _To, class _From> using _Is_assignable_no_precondition_check = is_assignable< _To, _From> ; 
#line 770 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 771
struct is_copy_assignable : public bool_constant< __is_assignable(add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< const _Ty> )>  { 
#line 774
}; 
#line 776
template< class _Ty> constexpr bool 
#line 777
is_copy_assignable_v = __is_assignable(add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< const _Ty> ); 
#line 789 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> using _Is_copy_assignable_no_precondition_check = is_copy_assignable< _Ty> ; 
#line 792
template< class _Ty> constexpr bool 
#line 793
_Is_copy_assignable_unchecked_v = is_copy_assignable_v< _Ty> ; 
#line 796 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 797
struct is_move_assignable : public bool_constant< __is_assignable(add_lvalue_reference_t< _Ty> , _Ty)>  { 
#line 799
}; 
#line 801
template< class _Ty> constexpr bool 
#line 802
is_move_assignable_v = __is_assignable(add_lvalue_reference_t< _Ty> , _Ty); 
#line 813 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> using _Is_move_assignable_no_precondition_check = is_move_assignable< _Ty> ; 
#line 816
template< class _Ty> constexpr bool 
#line 817
_Is_move_assignable_unchecked_v = is_move_assignable_v< _Ty> ; 
#line 820 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 821
struct is_destructible : public bool_constant< __is_destructible(_Ty)>  { 
#line 823
}; 
#line 825
template< class _Ty> constexpr bool 
#line 826
is_destructible_v = __is_destructible(_Ty); 
#line 828
template< class _Ty, class ..._Args> 
#line 829
struct is_trivially_constructible : public bool_constant< __is_trivially_constructible(_Ty, _Args...)>  { 
#line 831
}; 
#line 833
template< class _Ty, class ..._Args> constexpr bool 
#line 834
is_trivially_constructible_v = __is_trivially_constructible(_Ty, _Args...); 
#line 836
template< class _Ty> 
#line 837
struct is_trivially_copy_constructible : public bool_constant< __is_trivially_constructible(_Ty, add_lvalue_reference_t< const _Ty> )>  { 
#line 840
}; 
#line 842
template< class _Ty> constexpr bool 
#line 843
is_trivially_copy_constructible_v = __is_trivially_constructible(_Ty, add_lvalue_reference_t< const _Ty> ); 
#line 845
template< class _Ty> 
#line 846
struct is_trivially_default_constructible : public bool_constant< __is_trivially_constructible(_Ty)>  { 
#line 848
}; 
#line 850
template< class _Ty> constexpr bool 
#line 851
is_trivially_default_constructible_v = __is_trivially_constructible(_Ty); 
#line 853
template< class _Ty> 
#line 854
struct is_trivially_move_constructible : public bool_constant< __is_trivially_constructible(_Ty, _Ty)>  { 
#line 856
}; 
#line 858
template< class _Ty> constexpr bool 
#line 859
is_trivially_move_constructible_v = __is_trivially_constructible(_Ty, _Ty); 
#line 861
template< class _To, class _From> 
#line 862
struct is_trivially_assignable : public bool_constant< __is_trivially_assignable(_To, _From)>  { 
#line 864
}; 
#line 866
template< class _To, class _From> constexpr bool 
#line 867
is_trivially_assignable_v = __is_trivially_assignable(_To, _From); 
#line 869
template< class _Ty> 
#line 870
struct is_trivially_copy_assignable : public bool_constant< __is_trivially_assignable(add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< const _Ty> )>  { 
#line 873
}; 
#line 875
template< class _Ty> constexpr bool 
#line 876
is_trivially_copy_assignable_v = __is_trivially_assignable(add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< const _Ty> ); 
#line 879
template< class _Ty> 
#line 880
struct is_trivially_move_assignable : public bool_constant< __is_trivially_assignable(add_lvalue_reference_t< _Ty> , _Ty)>  { 
#line 882
}; 
#line 884
template< class _Ty> constexpr bool 
#line 885
is_trivially_move_assignable_v = __is_trivially_assignable(add_lvalue_reference_t< _Ty> , _Ty); 
#line 887
template< class _Ty> 
#line 888
struct is_trivially_destructible : public bool_constant< __is_trivially_destructible(_Ty)>  { 
#line 890
}; 
#line 892
template< class _Ty> constexpr bool 
#line 893
is_trivially_destructible_v = __is_trivially_destructible(_Ty); 
#line 895
template< class _Ty, class ..._Args> 
#line 896
struct is_nothrow_constructible : public bool_constant< __is_nothrow_constructible(_Ty, _Args...)>  { 
#line 898
}; 
#line 900
template< class _Ty, class ..._Args> constexpr bool 
#line 901
is_nothrow_constructible_v = __is_nothrow_constructible(_Ty, _Args...); 
#line 903
template< class _Ty> 
#line 904
struct is_nothrow_copy_constructible : public bool_constant< __is_nothrow_constructible(_Ty, add_lvalue_reference_t< const _Ty> )>  { 
#line 908
}; 
#line 910
template< class _Ty> constexpr bool 
#line 911
is_nothrow_copy_constructible_v = __is_nothrow_constructible(_Ty, add_lvalue_reference_t< const _Ty> ); 
#line 913
template< class _Ty> 
#line 914
struct is_nothrow_default_constructible : public bool_constant< __is_nothrow_constructible(_Ty)>  { 
#line 916
}; 
#line 918
template< class _Ty> constexpr bool 
#line 919
is_nothrow_default_constructible_v = __is_nothrow_constructible(_Ty); 
#line 921
template< class _Ty> 
#line 922
struct is_nothrow_move_constructible : public bool_constant< __is_nothrow_constructible(_Ty, _Ty)>  { 
#line 924
}; 
#line 926
template< class _Ty> constexpr bool 
#line 927
is_nothrow_move_constructible_v = __is_nothrow_constructible(_Ty, _Ty); 
#line 929
template< class _To, class _From> 
#line 930
struct is_nothrow_assignable : public bool_constant< __is_nothrow_assignable(_To, _From)>  { 
#line 932
}; 
#line 934
template< class _To, class _From> constexpr bool 
#line 935
is_nothrow_assignable_v = __is_nothrow_assignable(_To, _From); 
#line 937
template< class _Ty> 
#line 938
struct is_nothrow_copy_assignable : public bool_constant< __is_nothrow_assignable(add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< const _Ty> )>  { 
#line 941
}; 
#line 943
template< class _Ty> constexpr bool 
#line 944
is_nothrow_copy_assignable_v = __is_nothrow_assignable(add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< const _Ty> ); 
#line 947
template< class _Ty> 
#line 948
struct is_nothrow_move_assignable : public bool_constant< __is_nothrow_assignable(add_lvalue_reference_t< _Ty> , _Ty)>  { 
#line 950
}; 
#line 952
template< class _Ty> constexpr bool 
#line 953
is_nothrow_move_assignable_v = __is_nothrow_assignable(add_lvalue_reference_t< _Ty> , _Ty); 
#line 955
template< class _Ty> 
#line 956
struct is_nothrow_destructible : public bool_constant< __is_nothrow_destructible(_Ty)>  { 
#line 959
}; 
#line 961
template< class _Ty> constexpr bool 
#line 962
is_nothrow_destructible_v = __is_nothrow_destructible(_Ty); 
#line 964
template< class _Ty, bool  = is_integral_v< _Ty> > 
#line 965
struct _Sign_base { 
#line 966
using _Uty = remove_cv_t< _Ty> ; 
#line 968
static constexpr bool _Signed = ((static_cast< _Uty>(-1)) < (static_cast< _Uty>(0))); 
#line 969
static constexpr bool _Unsigned = (!_Signed); 
#line 970
}; 
#line 972
template< class _Ty> 
#line 973
struct _Sign_base< _Ty, false>  { 
#line 975
static constexpr bool _Signed = is_floating_point_v< _Ty> ; 
#line 976
static constexpr bool _Unsigned = false; 
#line 977
}; 
#line 979
template< class _Ty> 
#line 980
struct is_signed : public bool_constant< _Sign_base< _Ty> ::_Signed>  { }; 
#line 982
template< class _Ty> constexpr bool 
#line 983
is_signed_v = (_Sign_base< _Ty> ::_Signed); 
#line 985
template< class _Ty> 
#line 986
struct is_unsigned : public bool_constant< _Sign_base< _Ty> ::_Unsigned>  { }; 
#line 988
template< class _Ty> constexpr bool 
#line 989
is_unsigned_v = (_Sign_base< _Ty> ::_Unsigned); 
#line 991
template< class _Ty> constexpr bool 
#line 992
_Is_nonbool_integral = is_integral_v< _Ty>  && (!is_same_v< remove_cv_t< _Ty> , bool> ); 
#line 994
template< bool > 
#line 995
struct _Select { 
#line 996
template< class _Ty1, class > using _Apply = _Ty1; 
#line 998
}; 
#line 1001
template<> struct _Select< false>  { 
#line 1002
template< class , class _Ty2> using _Apply = _Ty2; 
#line 1004
}; 
#line 1006
template< size_t > struct _Make_signed2; 
#line 1010
template<> struct _Make_signed2< 1Ui64>  { 
#line 1011
template< class > using _Apply = signed char; 
#line 1013
}; 
#line 1016
template<> struct _Make_signed2< 2Ui64>  { 
#line 1017
template< class > using _Apply = short; 
#line 1019
}; 
#line 1022
template<> struct _Make_signed2< 4Ui64>  { 
#line 1023
template< class _Ty> using _Apply = typename _Select< is_same_v< _Ty, long>  || is_same_v< _Ty, unsigned long> > ::template _Apply< long, int> ; 
#line 1026
}; 
#line 1029
template<> struct _Make_signed2< 8Ui64>  { 
#line 1030
template< class > using _Apply = __int64; 
#line 1032
}; 
#line 1034
template< class _Ty> using _Make_signed1 = typename _Make_signed2< sizeof(_Ty)> ::template _Apply< _Ty> ; 
#line 1038
template< class _Ty> 
#line 1039
struct make_signed { 
#line 1040
static_assert((_Is_nonbool_integral< _Ty>  || is_enum_v< _Ty> ), "make_signed<T> requires that T shall be a (possibly cv-qualified) integral type or enumeration but not a bool type.");
#line 1044
using type = typename remove_cv< _Ty> ::template _Apply< _Make_signed1> ; 
#line 1045
}; 
#line 1047
template< class _Ty> using make_signed_t = typename make_signed< _Ty> ::type; 
#line 1050
template< size_t > struct _Make_unsigned2; 
#line 1054
template<> struct _Make_unsigned2< 1Ui64>  { 
#line 1055
template< class > using _Apply = unsigned char; 
#line 1057
}; 
#line 1060
template<> struct _Make_unsigned2< 2Ui64>  { 
#line 1061
template< class > using _Apply = unsigned short; 
#line 1063
}; 
#line 1066
template<> struct _Make_unsigned2< 4Ui64>  { 
#line 1067
template< class _Ty> using _Apply = typename _Select< is_same_v< _Ty, long>  || is_same_v< _Ty, unsigned long> > ::template _Apply< unsigned long, unsigned> ; 
#line 1071
}; 
#line 1074
template<> struct _Make_unsigned2< 8Ui64>  { 
#line 1075
template< class > using _Apply = unsigned __int64; 
#line 1077
}; 
#line 1079
template< class _Ty> using _Make_unsigned1 = typename _Make_unsigned2< sizeof(_Ty)> ::template _Apply< _Ty> ; 
#line 1083
template< class _Ty> 
#line 1084
struct make_unsigned { 
#line 1085
static_assert((_Is_nonbool_integral< _Ty>  || is_enum_v< _Ty> ), "make_unsigned<T> requires that T shall be a (possibly cv-qualified) integral type or enumeration but not a bool type.");
#line 1089
using type = typename remove_cv< _Ty> ::template _Apply< _Make_unsigned1> ; 
#line 1090
}; 
#line 1092
template< class _Ty> using make_unsigned_t = typename make_unsigned< _Ty> ::type; 
#line 1095
template < class _Rep >
constexpr make_unsigned_t < _Rep > _Unsigned_value ( _Rep _Val ) {
    return static_cast < make_unsigned_t < _Rep >> ( _Val );
}
#line 1100
template< class _Ty> 
#line 1101
struct alignment_of : public integral_constant< unsigned __int64, __alignof(_Ty)>  { }; 
#line 1103
template< class _Ty> constexpr size_t 
#line 1104
alignment_of_v = __alignof(_Ty); 
#line 1106
template< class _Ty, size_t _Len> 
#line 1107
union _Align_type { 
#line 1108
_Ty _Val; 
#line 1109
char _Pad[_Len]; 
#line 1110
}; 
#line 1112
template< size_t _Len, size_t _Align, class _Ty, bool _Ok> struct _Aligned; 
#line 1115
template< size_t _Len, size_t _Align, class _Ty> 
#line 1116
struct _Aligned< _Len, _Align, _Ty, true>  { 
#line 1117
using type = _Align_type< _Ty, _Len> ; 
#line 1118
}; 
#line 1120
template< size_t _Len, size_t _Align> 
#line 1121
struct _Aligned< _Len, _Align, double, false>  { 
#line 1128
static_assert((_Always_false< _Aligned> ), "You\'ve instantiated std::aligned_storage<Len, Align> with an extended alignment (in other words, Align > alignof(max_align_t))." " Before VS 2017 15.8, the member \"type\" would non-conformingly have an alignment of only alignof(max_align_t). VS 2017 15.8 wa" "s fixed to handle this correctly, but the fix inherently changes layout and breaks binary compatibility (*only* for uses of alig" "ned_storage with extended alignments). To suppress this error, please define either (1) _ENABLE_EXTENDED_ALIGNED_STORAGE to conf" "irm that you want a type with an extended alignment, or (2) _DISABLE_EXTENDED_ALIGNED_STORAGE to get the old non-conforming beha" "vior.");
#line 1138 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
using type = _Align_type< max_align_t, _Len> ; 
#line 1140 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
}; 
#line 1142
template< size_t _Len, size_t _Align> 
#line 1143
struct _Aligned< _Len, _Align, int, false>  { 
#line 1144
using _Next = double; 
#line 1145
static constexpr bool _Fits = (_Align <= __alignof(_Next)); 
#line 1146
using type = typename std::_Aligned< _Len, _Align, double, _Fits> ::type; 
#line 1147
}; 
#line 1149
template< size_t _Len, size_t _Align> 
#line 1150
struct _Aligned< _Len, _Align, short, false>  { 
#line 1151
using _Next = int; 
#line 1152
static constexpr bool _Fits = (_Align <= __alignof(_Next)); 
#line 1153
using type = typename std::_Aligned< _Len, _Align, int, _Fits> ::type; 
#line 1154
}; 
#line 1156
template< size_t _Len, size_t _Align> 
#line 1157
struct _Aligned< _Len, _Align, char, false>  { 
#line 1158
using _Next = short; 
#line 1159
static constexpr bool _Fits = (_Align <= __alignof(_Next)); 
#line 1160
using type = typename std::_Aligned< _Len, _Align, short, _Fits> ::type; 
#line 1161
}; 
#line 1164
template< size_t _Len, size_t _Align = 8Ui64> 
#line 1165
struct _Aligned_storage { 
#line 1166
using _Next = char; 
#line 1167
static constexpr bool _Fits = (_Align <= __alignof(_Next)); 
#line 1168
using type = typename _Aligned< _Len, _Align, char, _Fits> ::type; 
#line 1169
}; 
#line 1171
template< size_t _Len, size_t _Align = 8Ui64> using _Aligned_storage_t = typename _Aligned_storage< _Len, _Align> ::type; 
#line 1174
template< size_t _Len, size_t _Align = 8Ui64> 
#line 1175
struct aligned_storage { 
#line 1176
using type = _Aligned_storage_t< _Len, _Align> ; 
#line 1177
}; 
#line 1179
template< size_t _Len, size_t _Align = 8Ui64> using aligned_storage_t = _Aligned_storage_t< _Len, _Align> ; 
#line 1182
template< size_t ..._Vals> struct _Maximum; 
#line 1186
template<> struct _Maximum< >  : public integral_constant< unsigned __int64, 0Ui64>  { }; 
#line 1188
template< size_t _Val> 
#line 1189
struct _Maximum< _Val>  : public integral_constant< unsigned __int64, _Val>  { }; 
#line 1191
template< size_t _First, size_t _Second, size_t ..._Rest> 
#line 1192
struct _Maximum< _First, _Second, _Rest...>  : public std::_Maximum< (((_First) < _Second) ? _Second : _First), _Rest...> ::type { 
#line 1194
}; 
#line 1196
template< size_t _Len, class ..._Types> 
#line 1197
struct aligned_union { 
#line 1199
static constexpr size_t _Max_len = (_Maximum< _Len, sizeof(_Types)...> ::value); 
#line 1200
static constexpr size_t alignment_value = (_Maximum< __alignof(_Types)...> ::value); 
#line 1202
using type = _Aligned_storage_t< _Max_len, alignment_value> ; 
#line 1203
}; 
#line 1205
__pragma( warning(push)) __pragma( warning(disable : 4996)) 
#line 1206
template< size_t _Len, class ..._Types> using aligned_union_t = typename aligned_union< _Len, _Types...> ::type; 
#line 1208
__pragma( warning(pop)) 
#line 1210
template< class _Ty, bool  = is_enum_v< _Ty> > 
#line 1211
struct _Underlying_type { 
#line 1212
using type = __underlying_type(_Ty); 
#line 1213
}; 
#line 1215
template< class _Ty> 
#line 1216
struct _Underlying_type< _Ty, false>  { }; 
#line 1218
template< class _Ty> 
#line 1219
struct underlying_type : public _Underlying_type< _Ty>  { }; 
#line 1221
template< class _Ty> using underlying_type_t = typename _Underlying_type< _Ty> ::type; 
#line 1224
template< class _Ty> constexpr size_t 
#line 1225
rank_v = (0); 
#line 1227
template< class _Ty, size_t _Nx> constexpr size_t 
#line 1228
rank_v< _Ty [_Nx]>  = rank_v< _Ty>  + 1; 
#line 1230
template< class _Ty> constexpr size_t 
#line 1231
rank_v< _Ty []>  = rank_v< _Ty>  + 1; 
#line 1233
template< class _Ty> 
#line 1234
struct rank : public integral_constant< unsigned __int64, rank_v< _Ty> >  { }; 
#line 1236
template< class _Ty, unsigned _Ix = 0U> constexpr size_t 
#line 1237
extent_v = (0); 
#line 1239
template< class _Ty, size_t _Nx> constexpr size_t 
#line 1240
extent_v< _Ty [_Nx], 0>  = _Nx; 
#line 1242
template< class _Ty, unsigned _Ix, size_t _Nx> constexpr size_t 
#line 1243
extent_v< _Ty [_Nx], _Ix>  = extent_v< _Ty, _Ix - (1)> ; 
#line 1245
template< class _Ty, unsigned _Ix> constexpr size_t 
#line 1246
extent_v< _Ty [], _Ix>  = extent_v< _Ty, _Ix - (1)> ; 
#line 1248
template< class _Ty, unsigned _Ix = 0U> 
#line 1249
struct extent : public integral_constant< unsigned __int64, extent_v< _Ty, _Ix> >  { }; 
#line 1251
template< class _Base, class _Derived> 
#line 1252
struct is_base_of : public bool_constant< __is_base_of(_Base, _Derived)>  { 
#line 1254
}; 
#line 1256
template< class _Base, class _Derived> constexpr bool 
#line 1257
is_base_of_v = __is_base_of(_Base, _Derived); 
#line 1259
template< class _Ty> 
#line 1260
struct decay { 
#line 1261
using _Ty1 = remove_reference_t< _Ty> ; 
#line 1262
using _Ty2 = typename _Select< is_function_v< _Ty1> > ::template _Apply< add_pointer< _Ty1> , remove_cv< _Ty1> > ; 
#line 1263
using type = typename _Select< is_array_v< _Ty1> > ::template _Apply< add_pointer< remove_extent_t< _Ty1> > , _Ty2> ::type; 
#line 1264
}; 
#line 1266
template< class _Ty> using decay_t = typename decay< _Ty> ::type; 
#line 1269
template< class _Ty1, class _Ty2> using _Conditional_type = decltype(false ? std::declval< _Ty1> () : std::declval< _Ty2> ()); 
#line 1287 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty1, class _Ty2, class  = void> 
#line 1288
struct _Decayed_cond_oper { }; 
#line 1291 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty1, class _Ty2> 
#line 1292
struct _Decayed_cond_oper< _Ty1, _Ty2, void_t< _Conditional_type< _Ty1, _Ty2> > >  { 
#line 1293
using type = decay_t< _Conditional_type< _Ty1, _Ty2> > ; 
#line 1294
}; 
#line 1296
template< class ..._Ty> struct common_type; 
#line 1299
template< class ..._Ty> using common_type_t = typename common_type< _Ty...> ::type; 
#line 1303
template<> struct common_type< >  { }; 
#line 1305
template< class _Ty1> 
#line 1306
struct common_type< _Ty1>  : public std::common_type< _Ty1, _Ty1>  { }; 
#line 1308
template< class _Ty1, class _Ty2, class _Decayed1 = decay_t< _Ty1> , class _Decayed2 = decay_t< _Ty2> > 
#line 1309
struct _Common_type2 : public common_type< _Decayed1, _Decayed2>  { }; 
#line 1311
template< class _Ty1, class _Ty2> 
#line 1312
struct _Common_type2< _Ty1, _Ty2, _Ty1, _Ty2>  : public _Decayed_cond_oper< _Ty1, _Ty2>  { }; 
#line 1314
template< class _Ty1, class _Ty2> 
#line 1315
struct common_type< _Ty1, _Ty2>  : public _Common_type2< _Ty1, _Ty2>  { }; 
#line 1317
template< class _Void, class _Ty1, class _Ty2, class ..._Rest> 
#line 1318
struct _Common_type3 { }; 
#line 1320
template< class _Ty1, class _Ty2, class ..._Rest> 
#line 1321
struct _Common_type3< void_t< common_type_t< _Ty1, _Ty2> > , _Ty1, _Ty2, _Rest...>  : public common_type< common_type_t< _Ty1, _Ty2> , _Rest...>  { 
#line 1322
}; 
#line 1324
template< class _Ty1, class _Ty2, class ..._Rest> 
#line 1325
struct common_type< _Ty1, _Ty2, _Rest...>  : public _Common_type3< void, _Ty1, _Ty2, _Rest...>  { }; 
#line 1327
template< class _Ty> _Ty _Returns_exactly() noexcept; 
#line 1492 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Type, template< class ...>  class _Template> constexpr bool 
#line 1493
_Is_specialization_v = false; 
#line 1494
template< template< class ...>  class _Template, class ..._Types> constexpr bool 
#line 1495
_Is_specialization_v< _Template< _Types...> , _Template>  = true; 
#line 1497
template< class _Type, template< class ...>  class _Template> 
#line 1498
struct _Is_specialization : public bool_constant< _Is_specialization_v< _Type, _Template> >  { }; 
#line 1500
template< class _Ty> 
#line 1501
[[nodiscard]] [[msvc::intrinsic]] constexpr _Ty &&forward(remove_reference_t< _Ty>  &_Arg) noexcept { 
#line 1502
return static_cast< _Ty &&>(_Arg); 
#line 1503
} 
#line 1505
template< class _Ty> 
#line 1506
[[nodiscard]] [[msvc::intrinsic]] constexpr _Ty &&forward(remove_reference_t< _Ty>  &&_Arg) noexcept { 
#line 1507
static_assert((!is_lvalue_reference_v< _Ty> ), "bad forward call");
#line 1508
return static_cast< _Ty &&>(_Arg); 
#line 1509
} 
#line 1511
template< class _Ty> 
#line 1512
[[nodiscard]] [[msvc::intrinsic]] constexpr remove_reference_t< _Ty>  &&move(_Ty &&_Arg) noexcept { 
#line 1513
return static_cast< remove_reference_t< _Ty>  &&>(_Arg); 
#line 1514
} 
#line 1516
template < class _Ty >
[ [ nodiscard ] ] [ [ msvc :: intrinsic ] ] constexpr
    conditional_t < ! is_nothrow_move_constructible_v < _Ty > && is_copy_constructible_v < _Ty >, const _Ty &, _Ty && >
    move_if_noexcept ( _Ty & _Arg ) noexcept {
    return :: std :: move ( _Arg );
}
#line 1523
template < class _Ty >
[ [ nodiscard ] ] constexpr _Ty * addressof ( _Ty & _Val ) noexcept {
    return __builtin_addressof ( _Val );
}
#line 1528
template < class _Ty >
const _Ty * addressof ( const _Ty && ) = delete;
#line 1531
#pragma warning(push)
#pragma warning(disable : 5215)
#pragma warning(disable : 5216)
#line 1540
template< class _Ty> 
#line 1541
[[nodiscard]] _Ty 
#line 1540
_Fake_copy_init(_Ty) noexcept; 
#line 1551
#pragma warning(pop)
#line 1553
template < class _Ty >
class reference_wrapper;
#line 1560
enum class _Invoker_strategy { 
#line 1561
_Functor, 
#line 1562
_Pmf_object, 
#line 1563
_Pmf_refwrap, 
#line 1564
_Pmf_pointer, 
#line 1565
_Pmd_object, 
#line 1566
_Pmd_refwrap, 
#line 1567
_Pmd_pointer
#line 1568
}; 
#line 1570
struct _Invoker_functor { 
#line 1571
static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Functor; 
#line 1573
template < class _Callable, class ... _Types >
    static constexpr auto _Call ( _Callable && _Obj, _Types && ... _Args )
        noexcept ( noexcept ( static_cast < _Callable && > ( _Obj ) ( static_cast < _Types && > ( _Args ) ... ) ) )
        -> decltype ( static_cast < _Callable && > ( _Obj ) ( static_cast < _Types && > ( _Args ) ... ) ) {
        return static_cast < _Callable && > ( _Obj ) ( static_cast < _Types && > ( _Args ) ... );
    }
#line 1579
}; 
#line 1581
struct _Invoker_pmf_object { 
#line 1582
static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmf_object; 
#line 1584
template < class _Decayed, class _Ty1, class ... _Types2 >
    static constexpr auto _Call ( _Decayed _Pmf, _Ty1 && _Arg1, _Types2 && ... _Args2 )
        noexcept ( noexcept ( ( static_cast < _Ty1 && > ( _Arg1 ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... ) ) )
        -> decltype ( ( static_cast < _Ty1 && > ( _Arg1 ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... ) ) {
        return ( static_cast < _Ty1 && > ( _Arg1 ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... );
    }
#line 1590
}; 
#line 1592
struct _Invoker_pmf_refwrap { 
#line 1593
static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmf_refwrap; 
#line 1595
template < class _Decayed, class _Refwrap, class ... _Types2 >
    static constexpr auto _Call ( _Decayed _Pmf, _Refwrap _Rw, _Types2 && ... _Args2 )
        noexcept ( noexcept ( ( _Rw . get ( ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... ) ) )
        -> decltype ( ( _Rw . get ( ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... ) ) {
        return ( _Rw . get ( ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... );
    }
#line 1601
}; 
#line 1603
struct _Invoker_pmf_pointer { 
#line 1604
static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmf_pointer; 
#line 1606
template < class _Decayed, class _Ty1, class ... _Types2 >
    static constexpr auto _Call ( _Decayed _Pmf, _Ty1 && _Arg1, _Types2 && ... _Args2 )
        noexcept ( noexcept ( ( ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... ) ) )
        -> decltype ( ( ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... ) ) {
        return ( ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Pmf ) ( static_cast < _Types2 && > ( _Args2 ) ... );
    }
#line 1612
}; 
#line 1614
struct _Invoker_pmd_object { 
#line 1615
static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmd_object; 
#line 1617
template < class _Decayed, class _Ty1 >
    static constexpr auto _Call ( _Decayed _Pmd, _Ty1 && _Arg1 ) noexcept -> decltype ( static_cast < _Ty1 && > ( _Arg1 ) .* _Pmd ) {
        return static_cast < _Ty1 && > ( _Arg1 ) .* _Pmd;
    }
#line 1621
}; 
#line 1623
struct _Invoker_pmd_refwrap { 
#line 1624
static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmd_refwrap; 
#line 1626
template < class _Decayed, class _Refwrap >
    static constexpr auto _Call ( _Decayed _Pmd, _Refwrap _Rw ) noexcept -> decltype ( _Rw . get ( ) .* _Pmd ) {
        return _Rw . get ( ) .* _Pmd;
    }
#line 1630
}; 
#line 1632
struct _Invoker_pmd_pointer { 
#line 1633
static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmd_pointer; 
#line 1635
template < class _Decayed, class _Ty1 >
    static constexpr auto _Call ( _Decayed _Pmd, _Ty1 && _Arg1 ) noexcept ( noexcept ( ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Pmd ) )
        -> decltype ( ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Pmd ) {
        return ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Pmd;
    }
#line 1640
}; 
#line 1642
template< class _Callable, class _Ty1, class _Removed_cvref = _Remove_cvref_t< _Callable> , bool 
#line 1643
_Is_pmf = is_member_function_pointer_v< _Removed_cvref> , bool 
#line 1644
_Is_pmd = is_member_object_pointer_v< _Removed_cvref> > struct _Invoker1; 
#line 1647
template< class _Callable, class _Ty1, class _Removed_cvref> 
#line 1648
struct _Invoker1< _Callable, _Ty1, _Removed_cvref, true, false>  : public conditional_t< is_same_v< typename _Is_memfunptr< _Removed_cvref> ::_Class_type, _Remove_cvref_t< _Ty1> >  || is_base_of_v< typename _Is_memfunptr< _Removed_cvref> ::_Class_type, _Remove_cvref_t< _Ty1> > , _Invoker_pmf_object, conditional_t< _Is_specialization_v< _Remove_cvref_t< _Ty1> , reference_wrapper> , _Invoker_pmf_refwrap, _Invoker_pmf_pointer> >  { 
#line 1653
}; 
#line 1655
template< class _Callable, class _Ty1, class _Removed_cvref> 
#line 1656
struct _Invoker1< _Callable, _Ty1, _Removed_cvref, false, true>  : public conditional_t< is_same_v< typename _Is_member_object_pointer< _Removed_cvref> ::_Class_type, _Remove_cvref_t< _Ty1> >  || is_base_of_v< typename _Is_member_object_pointer< _Removed_cvref> ::_Class_type, _Remove_cvref_t< _Ty1> > , _Invoker_pmd_object, conditional_t< _Is_specialization_v< _Remove_cvref_t< _Ty1> , reference_wrapper> , _Invoker_pmd_refwrap, _Invoker_pmd_pointer> >  { 
#line 1662
}; 
#line 1664
template< class _Callable, class _Ty1, class _Removed_cvref> 
#line 1665
struct _Invoker1< _Callable, _Ty1, _Removed_cvref, false, false>  : public _Invoker_functor { }; 
#line 1667
template < class _Callable >
constexpr auto invoke ( _Callable && _Obj ) noexcept ( noexcept ( static_cast < _Callable && > ( _Obj ) ( ) ) )
    -> decltype ( static_cast < _Callable && > ( _Obj ) ( ) ) {
    return static_cast < _Callable && > ( _Obj ) ( );
}
#line 1673
template < class _Callable, class _Ty1, class ... _Types2 >
constexpr auto invoke ( _Callable && _Obj, _Ty1 && _Arg1, _Types2 && ... _Args2 )
    noexcept ( noexcept ( _Invoker1 < _Callable, _Ty1 > :: _Call (
        static_cast < _Callable && > ( _Obj ), static_cast < _Ty1 && > ( _Arg1 ), static_cast < _Types2 && > ( _Args2 ) ... ) ) )
    -> decltype ( _Invoker1 < _Callable, _Ty1 > :: _Call (
        static_cast < _Callable && > ( _Obj ), static_cast < _Ty1 && > ( _Arg1 ), static_cast < _Types2 && > ( _Args2 ) ... ) ) {
    if constexpr ( _Invoker1 < _Callable, _Ty1 > :: _Strategy == _Invoker_strategy :: _Functor ) {
        return static_cast < _Callable && > ( _Obj ) ( static_cast < _Ty1 && > ( _Arg1 ), static_cast < _Types2 && > ( _Args2 ) ... );
    } else if constexpr ( _Invoker1 < _Callable, _Ty1 > :: _Strategy == _Invoker_strategy :: _Pmf_object ) {
        return ( static_cast < _Ty1 && > ( _Arg1 ) .* _Obj ) ( static_cast < _Types2 && > ( _Args2 ) ... );
    } else if constexpr ( _Invoker1 < _Callable, _Ty1 > :: _Strategy == _Invoker_strategy :: _Pmf_refwrap ) {
        return ( _Arg1 . get ( ) .* _Obj ) ( static_cast < _Types2 && > ( _Args2 ) ... );
    } else if constexpr ( _Invoker1 < _Callable, _Ty1 > :: _Strategy == _Invoker_strategy :: _Pmf_pointer ) {
        return ( ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Obj ) ( static_cast < _Types2 && > ( _Args2 ) ... );
    } else if constexpr ( _Invoker1 < _Callable, _Ty1 > :: _Strategy == _Invoker_strategy :: _Pmd_object ) {
        return static_cast < _Ty1 && > ( _Arg1 ) .* _Obj;
    } else if constexpr ( _Invoker1 < _Callable, _Ty1 > :: _Strategy == _Invoker_strategy :: _Pmd_refwrap ) {



        auto & _Ref = _Arg1 . get ( );
        return _Ref .* _Obj;

    } else {
        ;
        return ( * static_cast < _Ty1 && > ( _Arg1 ) ) .* _Obj;
    }
}
#line 1702 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
#pragma warning(push)
#pragma warning(disable : 4242)
#pragma warning(disable : 4244)
#pragma warning(disable : 4365)
#line 1707
template< class _From, class _To, bool  = is_convertible_v< _From, _To> , bool  = is_void_v< _To> > constexpr bool 
#line 1708
_Is_nothrow_convertible_v = noexcept(std::_Fake_copy_init< _To> (std::declval< _From> ())); 
#line 1710
#pragma warning(pop)
#line 1712
template< class _From, class _To, bool _IsVoid> constexpr bool 
#line 1713
_Is_nothrow_convertible_v< _From, _To, false, _IsVoid>  = false; 
#line 1715
template< class _From, class _To> constexpr bool 
#line 1716
_Is_nothrow_convertible_v< _From, _To, true, true>  = true; 
#line 1718
template< class _From, class _To> 
#line 1719
struct _Is_nothrow_convertible : public bool_constant< _Is_nothrow_convertible_v< _From, _To> >  { 
#line 1721
}; 
#line 1731 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _From, class _To, class  = void> 
#line 1732
struct _Invoke_convertible : public false_type { }; 
#line 1734
template< class _From, class _To> 
#line 1735
struct _Invoke_convertible< _From, _To, void_t< decltype(std::_Fake_copy_init< _To> (std::_Returns_exactly< _From> ()))> >  : public true_type { 
#line 1736
}; 
#line 1738
template< class _From, class _To> 
#line 1739
struct _Invoke_nothrow_convertible : public bool_constant< noexcept(std::_Fake_copy_init< _To> (std::_Returns_exactly< _From> ()))>  { 
#line 1740
}; 
#line 1742
template< class _Result, bool _Nothrow> 
#line 1743
struct _Invoke_traits_common { 
#line 1744
using type = _Result; 
#line 1745
using _Is_invocable = true_type; 
#line 1746
using _Is_nothrow_invocable = bool_constant< _Nothrow> ; 
#line 1747
template< class _Rx> using _Is_invocable_r = bool_constant< disjunction_v< is_void< _Rx> , _Invoke_convertible< type, _Rx> > > ; 
#line 1749
template< class _Rx> using _Is_nothrow_invocable_r = bool_constant< conjunction_v< _Is_nothrow_invocable, disjunction< is_void< _Rx> , conjunction< _Invoke_convertible< type, _Rx> , _Invoke_nothrow_convertible< type, _Rx> > > > > ; 
#line 1753
}; 
#line 1755
template< class _Void, class _Callable> 
#line 1756
struct _Invoke_traits_zero { 
#line 1758
using _Is_invocable = false_type; 
#line 1759
using _Is_nothrow_invocable = false_type; 
#line 1760
template< class _Rx> using _Is_invocable_r = false_type; 
#line 1762
template< class _Rx> using _Is_nothrow_invocable_r = false_type; 
#line 1764
}; 
#line 1766
template< class _Callable> using _Decltype_invoke_zero = decltype(std::declval< _Callable> ()()); 
#line 1769
template< class _Callable> 
#line 1770
struct _Invoke_traits_zero< void_t< _Decltype_invoke_zero< _Callable> > , _Callable>  : public _Invoke_traits_common< _Decltype_invoke_zero< _Callable> , noexcept(std::declval< _Callable> ()())>  { 
#line 1771
}; 
#line 1773
template< class _Void, class ..._Types> 
#line 1774
struct _Invoke_traits_nonzero { 
#line 1776
using _Is_invocable = false_type; 
#line 1777
using _Is_nothrow_invocable = false_type; 
#line 1778
template< class _Rx> using _Is_invocable_r = false_type; 
#line 1780
template< class _Rx> using _Is_nothrow_invocable_r = false_type; 
#line 1782
}; 
#line 1784
template< class _Callable, class _Ty1, class ..._Types2> using _Decltype_invoke_nonzero = decltype(_Invoker1< _Callable, _Ty1> ::_Call(std::declval< _Callable> (), std::declval< _Ty1> (), std::declval< _Types2> ()...)); 
#line 1788
template< class _Callable, class _Ty1, class ..._Types2> 
#line 1789
struct _Invoke_traits_nonzero< void_t< _Decltype_invoke_nonzero< _Callable, _Ty1, _Types2...> > , _Callable, _Ty1, _Types2...>  : public _Invoke_traits_common< _Decltype_invoke_nonzero< _Callable, _Ty1, _Types2...> , noexcept(_Invoker1< _Callable, _Ty1> ::_Call(std::declval< _Callable> (), std::declval< _Ty1> (), std::declval< _Types2> ()...))>  { 
#line 1792
}; 
#line 1794
template< class _Callable, class ..._Args> using _Select_invoke_traits = conditional_t< sizeof...(_Args) == (0), _Invoke_traits_zero< void, _Callable> , _Invoke_traits_nonzero< void, _Callable, _Args...> > ; 
#line 1799
template< class _Fty> 
#line 1800
struct result_of { 
#line 1801
static_assert((_Always_false< _Fty> ), "result_of<CallableType> is invalid; use result_of<CallableType(zero or more argument types)> instead.");
#line 1803
}; 
#line 1811
template< class _Callable, class ..._Args> struct result_of< _Callable __cdecl (_Args ...)>  : public _Select_invoke_traits< _Callable, _Args...>  { }; template< class _Callable, class ..._Args> struct result_of< _Callable __vectorcall (_Args ...)>  : public _Select_invoke_traits< _Callable, _Args...>  { }; 
#line 1814
__pragma( warning(push)) __pragma( warning(disable : 4996)) 
#line 1815
template< class _Ty> using result_of_t = typename result_of< _Ty> ::type; 
#line 1817
__pragma( warning(pop)) 
#line 1820 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Callable, class ..._Args> using _Invoke_result_t = typename _Select_invoke_traits< _Callable, _Args...> ::type; 
#line 1823
template< class _Rx, class _Callable, class ..._Args> using _Is_invocable_r_ = typename conditional< sizeof...(_Args) == (0), _Invoke_traits_zero< void, _Callable> , _Invoke_traits_nonzero< void, _Callable, _Args...> > ::type::template _Is_invocable_r< _Rx> ; 
#line 1826
template< class _Rx, class _Callable, class ..._Args> 
#line 1827
struct _Is_invocable_r : public _Is_invocable_r_< _Rx, _Callable, _Args...>  { 
#line 1829
}; 
#line 1900 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> 
#line 1901
struct _Function_args { }; 
#line 1909
template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...)>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...)>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) const>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) const>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) volatile>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) volatile>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) const volatile>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) const volatile>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) const &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) const &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) volatile &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) volatile &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) const volatile &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) const volatile &>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) const &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) const &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) volatile &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) volatile &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __cdecl (_Types ...) const volatile &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret __vectorcall (_Types ...) const volatile &&>  : public _Arg_types< _Types...>  { using result_type = _Ret; }; 
#line 1918
template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...)>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) const>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) volatile>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) const volatile>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) &>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) const &>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) volatile &>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) const volatile &>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) &&>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) const &&>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) volatile &&>  { using result_type = _Ret; }; template< class _Ret, class ..._Types> struct _Function_args< _Ret (_Types ..., ...) const volatile &&>  { using result_type = _Ret; }; 
#line 1921
template< class _Ty, class  = void> 
#line 1922
struct _Weak_result_type { }; 
#line 1924
__pragma( warning(push)) __pragma( warning(disable : 4996)) 
#line 1925
template< class _Ty> 
#line 1926
struct _Weak_result_type< _Ty, void_t< typename _Ty::result_type> >  { 
#line 1927
using result_type = typename _Ty::result_type; 
#line 1928
}; 
#line 1929
__pragma( warning(pop)) 
#line 1931
template< class _Ty, class  = void> 
#line 1932
struct _Weak_argument_type : public _Weak_result_type< _Ty>  { }; 
#line 1934
__pragma( warning(push)) __pragma( warning(disable : 4996)) 
#line 1935
template< class _Ty> 
#line 1936
struct _Weak_argument_type< _Ty, void_t< typename _Ty::argument_type> >  : public _Weak_result_type< _Ty>  { 
#line 1938
using argument_type = typename _Ty::argument_type; 
#line 1939
}; 
#line 1940
__pragma( warning(pop)) 
#line 1942
template< class _Ty, class  = void> 
#line 1943
struct _Weak_binary_args : public _Weak_argument_type< _Ty>  { }; 
#line 1945
__pragma( warning(push)) __pragma( warning(disable : 4996)) 
#line 1946
template< class _Ty> 
#line 1947
struct _Weak_binary_args< _Ty, void_t< typename _Ty::first_argument_type, typename _Ty::second_argument_type> >  : public _Weak_argument_type< _Ty>  { 
#line 1950
using first_argument_type = typename _Ty::first_argument_type; 
#line 1951
using second_argument_type = typename _Ty::second_argument_type; 
#line 1952
}; 
#line 1953
__pragma( warning(pop)) 
#line 1955
template< class _Ty> using _Weak_types = conditional_t< is_function_v< remove_pointer_t< _Ty> > , _Function_args< remove_pointer_t< _Ty> > , conditional_t< is_member_function_pointer_v< _Ty> , _Is_memfunptr< remove_cv_t< _Ty> > , _Weak_binary_args< _Ty> > > ; 
#line 1959
template< class _Ty> void _Refwrap_ctor_fun(_Identity_t< _Ty &> ) noexcept; 
#line 1961
template < class _Ty >
void _Refwrap_ctor_fun ( _Identity_t < _Ty && > ) = delete;
#line 1964
template< class _Ty, class _Uty, class  = void> 
#line 1965
struct _Refwrap_has_ctor_from : public false_type { }; 
#line 1967
template< class _Ty, class _Uty> 
#line 1968
struct _Refwrap_has_ctor_from< _Ty, _Uty, void_t< decltype(std::_Refwrap_ctor_fun< _Ty> (std::declval< _Uty> ()))> >  : public true_type { 
#line 1969
}; 
#line 1971
template < class _Ty >
class reference_wrapper

    : public _Weak_types < _Ty >

{
public :
    static_assert ( is_object_v < _Ty > || is_function_v < _Ty >,
        "reference_wrapper<T> requires T to be an object type or a function type." );

    using type = _Ty;

    template < class _Uty, enable_if_t < conjunction_v < negation < is_same < _Remove_cvref_t < _Uty >, reference_wrapper >>,
                                          _Refwrap_has_ctor_from < _Ty, _Uty >>,
                              int > = 0 >
    inline reference_wrapper ( _Uty && _Val ) noexcept (
        noexcept ( :: std :: _Refwrap_ctor_fun < _Ty > ( :: std :: declval < _Uty > ( ) ) ) ) {
        _Ty & _Ref = static_cast < _Uty && > ( _Val );
        _Ptr = :: std :: addressof ( _Ref );
    }

    inline operator _Ty & ( ) const noexcept {
        return * _Ptr;
    }

    [ [ nodiscard ] ] inline _Ty & get ( ) const noexcept {
        return * _Ptr;
    }

private :
    _Ty * _Ptr { };

public :
    template < class ... _Types >
    inline auto operator ( ) ( _Types && ... _Args ) const
        noexcept ( noexcept ( :: std :: invoke ( * _Ptr, static_cast < _Types && > ( _Args ) ... ) ) )
        -> decltype ( :: std :: invoke ( * _Ptr, static_cast < _Types && > ( _Args ) ... ) ) {
        return :: std :: invoke ( * _Ptr, static_cast < _Types && > ( _Args ) ... );
    }
};
#line 2017 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template < class _Ty >
[ [ nodiscard ] ] inline reference_wrapper < _Ty > ref ( _Ty & _Val ) noexcept {
    return reference_wrapper < _Ty > ( _Val );
}
#line 2022
template < class _Ty >
void ref ( const _Ty && ) = delete;
#line 2025
template < class _Ty >
[ [ nodiscard ] ] inline reference_wrapper < _Ty > ref ( reference_wrapper < _Ty > _Val ) noexcept {
    return _Val;
}
#line 2030
template < class _Ty >
[ [ nodiscard ] ] inline reference_wrapper < const _Ty > cref ( const _Ty & _Val ) noexcept {
    return reference_wrapper < const _Ty > ( _Val );
}
#line 2035
template < class _Ty >
void cref ( const _Ty && ) = delete;
#line 2038
template < class _Ty >
[ [ nodiscard ] ] inline reference_wrapper < const _Ty > cref ( reference_wrapper < _Ty > _Val ) noexcept {
    return _Val;
}
#line 2063 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class _Ty> struct _Is_swappable; 
#line 2066
template< class _Ty> struct _Is_nothrow_swappable; 
#line 2072 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template < class _Ty, int _Enabled = 0 >

inline void swap ( _Ty &, _Ty & ) noexcept ( is_nothrow_move_constructible_v < _Ty > && is_nothrow_move_assignable_v < _Ty > );
#line 2076 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template < class _Ty, size_t _Size, enable_if_t < _Is_swappable < _Ty > :: value, int > = 0 >
inline void swap ( _Ty ( & ) [ _Size ], _Ty ( & ) [ _Size ] ) noexcept ( _Is_nothrow_swappable < _Ty > :: value );
#line 2079
template< class _Ty1, class _Ty2, class  = void> 
#line 2080
struct _Swappable_with_helper : public false_type { }; 
#line 2082
template< class _Ty1, class _Ty2> 
#line 2083
struct _Swappable_with_helper< _Ty1, _Ty2, void_t< decltype(swap(std::declval< _Ty1> (), std::declval< _Ty2> ()))> >  : public true_type { 
#line 2084
}; 
#line 2086
template< class _Ty1, class _Ty2> 
#line 2087
struct _Is_swappable_with : public bool_constant< conjunction_v< _Swappable_with_helper< _Ty1, _Ty2> , _Swappable_with_helper< _Ty2, _Ty1> > >  { 
#line 2090
}; 
#line 2092
template< class _Ty> 
#line 2093
struct _Is_swappable : public _Is_swappable_with< add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< _Ty> > ::type { 
#line 2095
}; 
#line 2097
template< class _Ty1, class _Ty2> 
#line 2098
struct _Swap_cannot_throw : public bool_constant< noexcept(swap(std::declval< _Ty1> (), std::declval< _Ty2> ())) && noexcept(swap(std::declval< _Ty2> (), std::declval< _Ty1> ()))>  { 
#line 2102
}; 
#line 2104
template< class _Ty1, class _Ty2> 
#line 2105
struct _Is_nothrow_swappable_with : public bool_constant< conjunction_v< _Is_swappable_with< _Ty1, _Ty2> , _Swap_cannot_throw< _Ty1, _Ty2> > >  { 
#line 2109
}; 
#line 2111
template< class _Ty> 
#line 2112
struct _Is_nothrow_swappable : public _Is_nothrow_swappable_with< add_lvalue_reference_t< _Ty> , add_lvalue_reference_t< _Ty> > ::type { 
#line 2115
}; 
#line 2152 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
namespace _Has_ADL_swap_detail { 
#line 2156 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
void swap(); 
#line 2159 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template< class , class  = void> 
#line 2160
struct _Has_ADL_swap : public false_type { }; 
#line 2161
template< class _Ty> 
#line 2162
struct _Has_ADL_swap< _Ty, void_t< decltype(swap(std::declval< _Ty &> (), std::declval< _Ty &> ()))> >  : public true_type { }; 
#line 2163
}
#line 2164
using _Has_ADL_swap_detail::_Has_ADL_swap;
#line 2166
template< class _Ty> constexpr bool 
#line 2167
_Is_trivially_swappable_v = conjunction_v< is_trivially_destructible< _Ty> , is_trivially_move_constructible< _Ty> , is_trivially_move_assignable< _Ty> , negation< _Has_ADL_swap_detail::_Has_ADL_swap< _Ty> > > ; 
#line 2175
template< class _Ty> 
#line 2176
struct _Is_trivially_swappable : public bool_constant< _Is_trivially_swappable_v< _Ty> >  { 
#line 2178
}; 
#line 2237 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
template < class _Bitmask >
[ [ nodiscard ] ] constexpr bool _Bitmask_includes_any ( _Bitmask _Left, _Bitmask _Elements ) noexcept {
    return ( _Left & _Elements ) != _Bitmask { };
}
#line 2242
template < class _Bitmask >
[ [ nodiscard ] ] constexpr bool _Bitmask_includes_all ( _Bitmask _Left, _Bitmask _Elements ) noexcept {
    return ( _Left & _Elements ) == _Elements;
}
#line 2250
constexpr size_t _FNV_offset_basis = 14695981039346656037Ui64; 
#line 2251
constexpr size_t _FNV_prime = 1099511628211Ui64; 
#line 2257 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
[[nodiscard]] inline size_t _Fnv1a_append_bytes(size_t _Val, const unsigned char *const _First, const size_t 
#line 2258
_Count) noexcept { 
#line 2259
for (size_t _Idx = (0); _Idx < _Count; ++_Idx) { 
#line 2260
_Val ^= (static_cast< size_t>(_First[_Idx])); 
#line 2261
_Val *= _FNV_prime; 
#line 2262
}  
#line 2264
return _Val; 
#line 2265
} 
#line 2267
template < class _Ty >
[ [ nodiscard ] ] size_t _Fnv1a_append_range ( const size_t _Val, const _Ty * const _First,
    const _Ty * const _Last ) noexcept {
    static_assert ( is_trivially_copyable_v < _Ty >, "Only trivially copyable types can be directly hashed." );
    const auto _Firstb = reinterpret_cast < const unsigned char * > ( _First );
    const auto _Lastb = reinterpret_cast < const unsigned char * > ( _Last );
    return _Fnv1a_append_bytes ( _Val, _Firstb, static_cast < size_t > ( _Lastb - _Firstb ) );
}
#line 2276
template < class _Kty >
[ [ nodiscard ] ] size_t _Fnv1a_append_value (
    const size_t _Val, const _Kty & _Keyval ) noexcept {
    static_assert ( is_trivially_copyable_v < _Kty >, "Only trivially copyable types can be directly hashed." );
    return _Fnv1a_append_bytes ( _Val, & reinterpret_cast < const unsigned char & > ( _Keyval ), sizeof ( _Kty ) );
}
#line 2283
template < class _Kty >
[ [ nodiscard ] ] size_t _Hash_representation ( const _Kty & _Keyval ) noexcept {
    return _Fnv1a_append_value ( _FNV_offset_basis, _Keyval );
}
#line 2288
template < class _Kty >
[ [ nodiscard ] ] size_t _Hash_array_representation (
    const _Kty * const _First, const size_t _Count ) noexcept {
    static_assert ( is_trivially_copyable_v < _Kty >, "Only trivially copyable types can be directly hashed." );
    return _Fnv1a_append_bytes (
        _FNV_offset_basis, reinterpret_cast < const unsigned char * > ( _First ), _Count * sizeof ( _Kty ) );
}
#line 2296
template < class _Kty >
struct hash;
#line 2299
template < class _Kty, bool _Enabled >
struct _Conditionally_enabled_hash {
    using argument_type = _Kty;
    using result_type = size_t;

    [ [ nodiscard ] ] size_t operator ( ) ( const _Kty & _Keyval ) const
        noexcept ( noexcept ( hash < _Kty > :: _Do_hash ( _Keyval ) ) ) {
        return hash < _Kty > :: _Do_hash ( _Keyval );
    }
};
#line 2310
template< class _Kty> 
#line 2311
struct _Conditionally_enabled_hash< _Kty, false>  { 
#line 2312
_Conditionally_enabled_hash() = delete;
#line 2313
_Conditionally_enabled_hash(const _Conditionally_enabled_hash &) = delete;
#line 2314
_Conditionally_enabled_hash(_Conditionally_enabled_hash &&) = delete;
#line 2315
_Conditionally_enabled_hash &operator=(const _Conditionally_enabled_hash &) = delete;
#line 2316
_Conditionally_enabled_hash &operator=(_Conditionally_enabled_hash &&) = delete;
#line 2317
}; 
#line 2319
template < class _Kty >
struct hash : _Conditionally_enabled_hash < _Kty, ! is_const_v < _Kty > && ! is_volatile_v < _Kty >
                                                    && ( is_enum_v < _Kty > || is_integral_v < _Kty > || is_pointer_v < _Kty > ) > {

    static size_t _Do_hash ( const _Kty & _Keyval ) noexcept {
        return _Hash_representation ( _Keyval );
    }
};
#line 2329
#pragma pack(8)
template<> 
#line 2329
struct hash< float>  { 
#line 2330
using argument_type = float; 
#line 2331
using result_type = size_t; 
#line 2332
[[nodiscard]] size_t operator()(const float _Keyval) const noexcept { 
#line 2333
return _Hash_representation((_Keyval == (0.0F)) ? (0.0F) : _Keyval); 
#line 2334
} 
#line 2335
}; 
#pragma pack()
#line 2338
#pragma pack(8)
template<> 
#line 2338
struct hash< double>  { 
#line 2339
using argument_type = double; 
#line 2340
using result_type = size_t; 
#line 2341
[[nodiscard]] size_t operator()(const double _Keyval) const noexcept { 
#line 2342
return _Hash_representation((_Keyval == (0.0)) ? (0.0) : _Keyval); 
#line 2343
} 
#line 2344
}; 
#pragma pack()
#line 2347
#pragma pack(8)
template<> 
#line 2347
struct hash< long double>  { 
#line 2348
using argument_type = long double; 
#line 2349
using result_type = size_t; 
#line 2350
[[nodiscard]] size_t operator()(const long double _Keyval) const noexcept { 
#line 2351
return _Hash_representation((_Keyval == (0.0L)) ? (0.0L) : _Keyval); 
#line 2352
} 
#line 2353
}; 
#pragma pack()
#line 2356
#pragma pack(8)
template<> 
#line 2356
struct hash< std::nullptr_t>  { 
#line 2357
using argument_type = nullptr_t; 
#line 2358
using result_type = size_t; 
#line 2359
[[nodiscard]] size_t operator()(nullptr_t) const noexcept { 
#line 2360
void *_Null{((void *)0i64)}; 
#line 2361
return _Hash_representation(_Null); 
#line 2362
} 
#line 2363
}; 
#pragma pack()
template< class _Kty, class  = void> 
#pragma pack(8)
#line 2366
struct _Is_nothrow_hashable : public false_type { }; 
#pragma pack()
template< class _Kty> 
#pragma pack(8)
#line 2369
struct _Is_nothrow_hashable< _Kty, void_t< decltype(hash< _Kty> {}(std::declval< const _Kty &> ()))> >  : public bool_constant< noexcept(hash< _Kty> {}(std::declval< const _Kty &> ()))>  { 
#line 2370
}; 
#pragma pack()
template < class _Ty = void >
struct less {
    using first_argument_type = _Ty;
    using second_argument_type = _Ty;
    using result_type = bool;

    [ [ nodiscard ] ] constexpr bool operator ( ) ( const _Ty & _Left, const _Ty & _Right ) const
        noexcept ( noexcept ( :: std :: _Fake_copy_init < bool > ( _Left < _Right ) ) ) {
        return _Left < _Right;
    }
};
#line 2385
template<> struct less< void>  { 
#line 2386
template < class _Ty1, class _Ty2 >
    [ [ nodiscard ] ] constexpr auto operator ( ) ( _Ty1 && _Left, _Ty2 && _Right ) const
        noexcept ( noexcept ( static_cast < _Ty1 && > ( _Left ) < static_cast < _Ty2 && > ( _Right ) ) )
        -> decltype ( static_cast < _Ty1 && > ( _Left ) < static_cast < _Ty2 && > ( _Right ) ) {
        return static_cast < _Ty1 && > ( _Left ) < static_cast < _Ty2 && > ( _Right );
    }
#line 2393
using is_transparent = int; 
#line 2394
}; 
#line 2398
template< class _FloatingType> struct _Floating_type_traits; 
#line 2402
template<> struct _Floating_type_traits< float>  { 
#line 2403
static constexpr int32_t _Mantissa_bits = 24; 
#line 2404
static constexpr int32_t _Exponent_bits = 8; 
#line 2405
static constexpr int32_t _Maximum_binary_exponent = 127; 
#line 2406
static constexpr int32_t _Minimum_binary_exponent = (-126); 
#line 2407
static constexpr int32_t _Exponent_bias = 127; 
#line 2408
static constexpr int32_t _Sign_shift = 31; 
#line 2409
static constexpr int32_t _Exponent_shift = 23; 
#line 2411
using _Uint_type = uint32_t; 
#line 2413
static constexpr uint32_t _Exponent_mask = 255U; 
#line 2414
static constexpr uint32_t _Normal_mantissa_mask = 16777215U; 
#line 2415
static constexpr uint32_t _Denormal_mantissa_mask = 8388607U; 
#line 2416
static constexpr uint32_t _Special_nan_mantissa_mask = 4194304U; 
#line 2417
static constexpr uint32_t _Shifted_sign_mask = 2147483648U; 
#line 2418
static constexpr uint32_t _Shifted_exponent_mask = 2139095040U; 
#line 2420
static constexpr float _Minimum_value = (1.175494351e-38F); 
#line 2421
static constexpr float _Maximum_value = (3.402823466e+38F); 
#line 2422
}; 
#line 2425
template<> struct _Floating_type_traits< double>  { 
#line 2426
static constexpr int32_t _Mantissa_bits = 53; 
#line 2427
static constexpr int32_t _Exponent_bits = 11; 
#line 2428
static constexpr int32_t _Maximum_binary_exponent = 1023; 
#line 2429
static constexpr int32_t _Minimum_binary_exponent = (-1022); 
#line 2430
static constexpr int32_t _Exponent_bias = 1023; 
#line 2431
static constexpr int32_t _Sign_shift = 63; 
#line 2432
static constexpr int32_t _Exponent_shift = 52; 
#line 2434
using _Uint_type = uint64_t; 
#line 2436
static constexpr uint64_t _Exponent_mask = (2047U); 
#line 2437
static constexpr uint64_t _Normal_mantissa_mask = 9007199254740991Ui64; 
#line 2438
static constexpr uint64_t _Denormal_mantissa_mask = 4503599627370495Ui64; 
#line 2439
static constexpr uint64_t _Special_nan_mantissa_mask = 2251799813685248Ui64; 
#line 2440
static constexpr uint64_t _Shifted_sign_mask = 9223372036854775808Ui64; 
#line 2441
static constexpr uint64_t _Shifted_exponent_mask = 9218868437227405312Ui64; 
#line 2443
static constexpr double _Minimum_value = (2.225073858507201383e-308); 
#line 2444
static constexpr double _Maximum_value = (1.797693134862315708e+308); 
#line 2445
}; 
#line 2448
template<> struct _Floating_type_traits< long double>  : public std::_Floating_type_traits< double>  { }; 
#line 2452
template < class _To, class _From,
    enable_if_t < conjunction_v < bool_constant < sizeof ( _To ) == sizeof ( _From ) >, is_trivially_copyable < _To >,
                    is_trivially_copyable < _From > >,
        int > = 0 >
[ [ nodiscard ] ] constexpr _To _Bit_cast ( const _From & _Val ) noexcept {
    return __builtin_bit_cast ( _To, _Val );
}
#line 2460
template < class _Ty, enable_if_t < is_floating_point_v < _Ty >, int > = 0 >
[ [ nodiscard ] ] constexpr auto _Float_abs_bits ( const _Ty & _Xx ) noexcept {
    using _Traits = _Floating_type_traits < _Ty >;
    using _Uint_type = typename _Traits :: _Uint_type;
    const auto _Bits = _Bit_cast < _Uint_type > ( _Xx );
    return _Bits & ~ _Traits :: _Shifted_sign_mask;
}
#line 2468
template < class _Ty, enable_if_t < is_floating_point_v < _Ty >, int > = 0 >
[ [ nodiscard ] ] constexpr _Ty _Float_abs ( const _Ty _Xx ) noexcept {
    return _Bit_cast < _Ty > ( _Float_abs_bits ( _Xx ) );
}
#line 2473
template < class _Ty, enable_if_t < is_floating_point_v < _Ty >, int > = 0 >
[ [ nodiscard ] ] constexpr bool _Is_nan ( const _Ty _Xx ) noexcept {
    using _Traits = _Floating_type_traits < _Ty >;
    return _Float_abs_bits ( _Xx ) > _Traits :: _Shifted_exponent_mask;
}
#line 2479
template < class _Ty, enable_if_t < is_floating_point_v < _Ty >, int > = 0 >
[ [ nodiscard ] ] constexpr bool _Is_finite ( const _Ty _Xx ) noexcept {
    using _Traits = _Floating_type_traits < _Ty >;
    return _Float_abs_bits ( _Xx ) < _Traits :: _Shifted_exponent_mask;
}
#line 2485
template< bool _IsConst, class _Ty> using _Maybe_const = conditional_t< _IsConst, const _Ty, _Ty> ; 
#line 2488
template < class _Ty, size_t _Size >
void _Swap_trivial_arrays ( _Ty ( & _Left ) [ _Size ], _Ty ( & _Right ) [ _Size ] ) noexcept {






    auto _Left_ptr = reinterpret_cast < unsigned char * > ( & _Left );
    auto _Right_ptr = reinterpret_cast < unsigned char * > ( & _Right );

    constexpr size_t _Part_size_bytes = 64;
    constexpr size_t _Size_bytes = _Size * sizeof ( _Ty );
    constexpr size_t _Size_tail = _Size_bytes % _Part_size_bytes;
    constexpr size_t _Size_parts = _Size_bytes - _Size_tail;

    if constexpr ( _Size_parts != 0 ) {
        const auto _Stop = _Left_ptr + _Size_parts;
        do {
            unsigned char _Buf [ _Part_size_bytes ];
            :: memcpy ( _Buf, _Left_ptr, _Part_size_bytes );
            :: memcpy ( _Left_ptr, _Right_ptr, _Part_size_bytes );
            :: memcpy ( _Right_ptr, _Buf, _Part_size_bytes );
            _Left_ptr += _Part_size_bytes;
            _Right_ptr += _Part_size_bytes;

        } while ( _Left_ptr != _Stop );
    }

    if constexpr ( _Size_tail != 0 ) {
        unsigned char _Buf [ _Size_tail ];
        :: memcpy ( _Buf, _Left_ptr, _Size_tail );
        :: memcpy ( _Left_ptr, _Right_ptr, _Size_tail );
        :: memcpy ( _Right_ptr, _Buf, _Size_tail );
    }
}
#line 2526
__pragma( warning(push)) __pragma( warning(disable : 4996)) 
#line 2527
namespace [[deprecated("warning STL4002: The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can define _" "SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to suppress this warning.")]] tr1 { 
#line 2528
using std::add_const;
#line 2529
using std::add_cv;
#line 2530
using std::add_pointer;
#line 2531
using std::add_volatile;
#line 2532
using std::aligned_storage;
#line 2533
using std::alignment_of;
#line 2534
using std::conditional;
#line 2535
using std::decay;
#line 2536
using std::enable_if;
#line 2537
using std::extent;
#line 2538
using std::false_type;
#line 2539
using std::has_virtual_destructor;
#line 2540
using std::integral_constant;
#line 2541
using std::is_abstract;
#line 2542
using std::is_arithmetic;
#line 2543
using std::is_array;
#line 2544
using std::is_base_of;
#line 2545
using std::is_class;
#line 2546
using std::is_compound;
#line 2547
using std::is_const;
#line 2548
using std::is_convertible;
#line 2549
using std::is_empty;
#line 2550
using std::is_enum;
#line 2551
using std::is_floating_point;
#line 2552
using std::is_function;
#line 2553
using std::is_fundamental;
#line 2554
using std::is_integral;
#line 2555
using std::is_member_function_pointer;
#line 2556
using std::is_member_object_pointer;
#line 2557
using std::is_member_pointer;
#line 2558
using std::is_object;
#line 2559
using std::is_pod;
#line 2560
using std::is_pointer;
#line 2561
using std::is_polymorphic;
#line 2562
using std::is_reference;
#line 2563
using std::is_same;
#line 2564
using std::is_scalar;
#line 2565
using std::is_signed;
#line 2566
using std::is_union;
#line 2567
using std::is_unsigned;
#line 2568
using std::is_void;
#line 2569
using std::is_volatile;
#line 2570
using std::make_signed;
#line 2571
using std::make_unsigned;
#line 2572
using std::rank;
#line 2573
using std::remove_all_extents;
#line 2574
using std::remove_const;
#line 2575
using std::remove_cv;
#line 2576
using std::remove_extent;
#line 2577
using std::remove_pointer;
#line 2578
using std::remove_reference;
#line 2579
using std::remove_volatile;
#line 2580
using std::true_type;
#line 2581
using std::cref;
#line 2582
using std::ref;
#line 2583
using std::reference_wrapper;
#line 2585
using std::result_of;
#line 2587 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
using std::hash;
#line 2588
}
#line 2589
__pragma( warning(pop)) 
#line 2592 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\type_traits"
}
#line 2601
#pragma warning(pop)
#pragma pack ( pop )
#line 22 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4324 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4868 4988 5026 5027 5045 5220 5246 5278 5280 5281 6294 4984 5053 )
#line 39
namespace std { 
#line 40
template < class _Ty, _Ty ... _Vals >
struct integer_sequence {
    static_assert ( is_integral_v < _Ty >, "integer_sequence<T, I...> requires T to be an integral type." );

    using value_type = _Ty;

    [ [ nodiscard ] ] static constexpr size_t size ( ) noexcept {
        return sizeof ... ( _Vals );
    }
};
#line 51
template< class _Ty, _Ty _Size> using make_integer_sequence = __make_integer_seq< integer_sequence, _Ty, _Size> ; 
#line 54
template< size_t ..._Vals> using index_sequence = integer_sequence< unsigned __int64, _Vals...> ; 
#line 57
template< size_t _Size> using make_index_sequence = make_integer_sequence< unsigned __int64, _Size> ; 
#line 60
template< class ..._Types> using index_sequence_for = make_index_sequence< sizeof...(_Types)> ; 
#line 63
template < class _Ty, class _Pr >
[ [ nodiscard ] ] constexpr const _Ty & ( max ) ( const _Ty & _Left [ [ msvc :: lifetimebound ] ], const _Ty & _Right [ [ msvc :: lifetimebound ] ],
    _Pr _Pred ) noexcept ( noexcept ( _Pred ( _Left, _Right ) ) ) {

    return _Pred ( _Left, _Right ) ? _Right : _Left;
}
#line 70
#pragma warning(push)
#pragma warning(disable : 28285)
template < class _Ty >
[ [ nodiscard ] ] constexpr const _Ty &
    ( max ) ( const _Ty & _Left [ [ msvc :: lifetimebound ] ], const _Ty & _Right [ [ msvc :: lifetimebound ] ] )
        noexcept ( noexcept ( _Left < _Right ) ) {

    return _Left < _Right ? _Right : _Left;
}
#pragma warning(pop)
#line 81
template< class _Ty, class _Pr> 
#line 82
[[nodiscard]] constexpr _Ty 
#line 81
max(initializer_list< _Ty> , _Pr); 
#line 84
template< class _Ty> 
#line 85
[[nodiscard]] constexpr _Ty 
#line 84
max(initializer_list< _Ty> ); 
#line 87
template < class _Ty, class _Pr >
[ [ nodiscard ] ] constexpr const _Ty & ( min ) ( const _Ty & _Left [ [ msvc :: lifetimebound ] ], const _Ty & _Right [ [ msvc :: lifetimebound ] ],
    _Pr _Pred ) noexcept ( noexcept ( _Pred ( _Right, _Left ) ) ) {

    return _Pred ( _Right, _Left ) ? _Right : _Left;
}
#line 94
#pragma warning(push)
#pragma warning(disable : 28285)
template < class _Ty >
[ [ nodiscard ] ] constexpr const _Ty &
    ( min ) ( const _Ty & _Left [ [ msvc :: lifetimebound ] ], const _Ty & _Right [ [ msvc :: lifetimebound ] ] )
        noexcept ( noexcept ( _Right < _Left ) ) {

    return _Right < _Left ? _Right : _Left;
}
#pragma warning(pop)
#line 105
template< class _Ty, class _Pr> 
#line 106
[[nodiscard]] constexpr _Ty 
#line 105
min(initializer_list< _Ty> , _Pr); 
#line 108
template< class _Ty> 
#line 109
[[nodiscard]] constexpr _Ty 
#line 108
min(initializer_list< _Ty> ); 
#line 111
template < class _Ty, size_t _Size, enable_if_t < _Is_swappable < _Ty > :: value, int > >
inline void swap ( _Ty ( & _Left ) [ _Size ], _Ty ( & _Right ) [ _Size ] ) noexcept ( _Is_nothrow_swappable < _Ty > :: value ) {
    if ( & _Left == & _Right ) {
        return;
    }

    if constexpr ( _Is_trivially_swappable_v < _Ty > ) {
        if ( ! :: std :: _Is_constant_evaluated ( ) ) {
            :: std :: _Swap_trivial_arrays ( _Left, _Right );
            return;
        }
    }

    _Ty * _First1 = _Left;
    _Ty * _Last1 = _First1 + _Size;
    _Ty * _First2 = _Right;
    for (; _First1 != _Last1; ++ _First1, ++ _First2 ) {
        swap ( * _First1, * _First2 );
    }
}
#line 135 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
template < class _Ty, int _Enabled >

inline void swap ( _Ty & _Left, _Ty & _Right )
    noexcept ( is_nothrow_move_constructible_v < _Ty > && is_nothrow_move_assignable_v < _Ty > ) {
    _Ty _Tmp = :: std :: move ( _Left );
    _Left = :: std :: move ( _Right );
    _Right = :: std :: move ( _Tmp );
}
#line 144 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
#pragma pack(8)
#line 144
struct piecewise_construct_t { 
#line 145
explicit piecewise_construct_t() = default;
#line 146
}; 
#pragma pack()
constexpr piecewise_construct_t piecewise_construct{}; 
#line 150
#pragma pack(8)
#line 150
struct _Ignore { 
#line 151
template < class _Ty >
    constexpr const _Ignore & operator = ( const _Ty & ) const noexcept {

        return * this;
    }
#line 156
}; 
#pragma pack(8)
constexpr _Ignore ignore{}; 
#line 160
template< class ..._Types> class tuple; 
#line 163
template < class _Ty1, class _Ty2 >
struct pair;
#line 166
template< class _Ty, size_t _Size> class array; 
#line 169
template< class _Tuple> struct tuple_size; 
#line 172
template< class _Ty> constexpr size_t 
#line 173
tuple_size_v = (tuple_size< _Ty> ::value); 
#line 175
template< size_t _Index, class _Tuple> struct tuple_element; 
#line 178
template< size_t _Index, class _Tuple> using tuple_element_t = typename tuple_element< _Index, _Tuple> ::type; 
#line 181
template< size_t _Index, class ..._Types> 
#line 182
[[nodiscard]] constexpr auto &&
#line 181
_Tuple_get(tuple< _Types...>  && _Tuple) noexcept; 
#line 184
template< size_t _Index, class ..._Types> 
#line 185
[[nodiscard]] constexpr tuple_element_t< _Index, tuple< _Types...> >  &
#line 184
get(tuple< _Types...>  & _Tuple) noexcept; 
#line 187
template< size_t _Index, class ..._Types> 
#line 188
[[nodiscard]] constexpr const tuple_element_t< _Index, tuple< _Types...> >  &
#line 187
get(const tuple< _Types...>  & _Tuple) noexcept; 
#line 190
template< size_t _Index, class ..._Types> 
#line 191
[[nodiscard]] constexpr tuple_element_t< _Index, tuple< _Types...> >  &&
#line 190
get(tuple< _Types...>  && _Tuple) noexcept; 
#line 193
template< size_t _Index, class ..._Types> 
#line 194
[[nodiscard]] constexpr const tuple_element_t< _Index, tuple< _Types...> >  &&
#line 193
get(const tuple< _Types...>  && _Tuple) noexcept; 
#line 196
template< size_t _Idx, class _Ty, size_t _Size> 
#line 197
[[nodiscard]] constexpr _Ty &
#line 196
get(array< _Ty, _Size>  & _Arr) noexcept; 
#line 199
template< size_t _Idx, class _Ty, size_t _Size> 
#line 200
[[nodiscard]] constexpr const _Ty &
#line 199
get(const array< _Ty, _Size>  & _Arr) noexcept; 
#line 202
template< size_t _Idx, class _Ty, size_t _Size> 
#line 203
[[nodiscard]] constexpr _Ty &&
#line 202
get(array< _Ty, _Size>  && _Arr) noexcept; 
#line 205
template< size_t _Idx, class _Ty, size_t _Size> 
#line 206
[[nodiscard]] constexpr const _Ty &&
#line 205
get(const array< _Ty, _Size>  && _Arr) noexcept; 
#line 246 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
template < class _Ty1, class _Ty2 >
struct pair {
    using first_type = _Ty1;
    using second_type = _Ty2;

    template < class _Uty1 = _Ty1, class _Uty2 = _Ty2,
        enable_if_t < conjunction_v < is_default_constructible < _Uty1 >, is_default_constructible < _Uty2 >>, int > = 0 >
    constexpr explicit (
        ! conjunction_v < _Is_implicitly_default_constructible < _Uty1 >, _Is_implicitly_default_constructible < _Uty2 >> ) pair ( )
        noexcept ( is_nothrow_default_constructible_v < _Uty1 > && is_nothrow_default_constructible_v < _Uty2 > )
        : first ( ), second ( ) { }

    template < class _Uty1 = _Ty1, class _Uty2 = _Ty2,
        enable_if_t < conjunction_v < is_copy_constructible < _Uty1 >, is_copy_constructible < _Uty2 >>, int > = 0 >
    constexpr explicit ( ! conjunction_v < is_convertible < const _Uty1 &, _Uty1 >, is_convertible < const _Uty2 &, _Uty2 >> )
        pair ( const _Ty1 & _Val1, const _Ty2 & _Val2 )
            noexcept ( is_nothrow_copy_constructible_v < _Uty1 > && is_nothrow_copy_constructible_v < _Uty2 > )
        : first ( _Val1 ), second ( _Val2 ) { }




    template < class _Other1, class _Other2,

        enable_if_t < conjunction_v < is_constructible < _Ty1, _Other1 >, is_constructible < _Ty2, _Other2 >>, int > = 0 >
    constexpr explicit ( ! conjunction_v < is_convertible < _Other1, _Ty1 >, is_convertible < _Other2, _Ty2 >> )
        pair ( _Other1 && _Val1, _Other2 && _Val2 ) noexcept (
            is_nothrow_constructible_v < _Ty1, _Other1 > && is_nothrow_constructible_v < _Ty2, _Other2 > )
        : first ( :: std :: forward < _Other1 > ( _Val1 ) ), second ( :: std :: forward < _Other2 > ( _Val2 ) ) {
    }

    pair ( const pair & ) = default;
    pair ( pair && ) = default;










    template < class _Other1, class _Other2,
        enable_if_t < conjunction_v < is_constructible < _Ty1, const _Other1 & >, is_constructible < _Ty2, const _Other2 & >>,
            int > = 0 >
    constexpr explicit ( ! conjunction_v < is_convertible < const _Other1 &, _Ty1 >, is_convertible < const _Other2 &, _Ty2 >> )
        pair ( const pair < _Other1, _Other2 > & _Right )
            noexcept ( is_nothrow_constructible_v < _Ty1, const _Other1 & >
                     && is_nothrow_constructible_v < _Ty2, const _Other2 & > )
        : first ( _Right . first ), second ( _Right . second ) { }

    template < class _Other1, class _Other2,
        enable_if_t < conjunction_v < is_constructible < _Ty1, _Other1 >, is_constructible < _Ty2, _Other2 >>, int > = 0 >
    constexpr explicit ( ! conjunction_v < is_convertible < _Other1, _Ty1 >, is_convertible < _Other2, _Ty2 >> )
        pair ( pair < _Other1, _Other2 > && _Right ) noexcept (
            is_nothrow_constructible_v < _Ty1, _Other1 > && is_nothrow_constructible_v < _Ty2, _Other2 > )
        : first ( :: std :: forward < _Other1 > ( _Right . first ) ), second ( :: std :: forward < _Other2 > ( _Right . second ) ) { }

























    template < class ... _Types1, class ... _Types2 >
    inline pair ( piecewise_construct_t, tuple < _Types1 ... > _Val1, tuple < _Types2 ... > _Val2 )
        : pair ( _Val1, _Val2, index_sequence_for < _Types1 ... > { }, index_sequence_for < _Types2 ... > { } ) { }

    pair & operator = ( const volatile pair & ) = delete;

    template < class _Myself = pair,
        enable_if_t < conjunction_v < _Is_copy_assignable_no_precondition_check < typename _Myself :: first_type >,
                        _Is_copy_assignable_no_precondition_check < typename _Myself :: second_type >>,
            int > = 0 >
    inline pair & operator = ( _Identity_t < const _Myself & > _Right )
        noexcept ( conjunction_v < is_nothrow_copy_assignable < _Ty1 >, is_nothrow_copy_assignable < _Ty2 >> ) {
        first = _Right . first;
        second = _Right . second;
        return * this;
    }














    template < class _Myself = pair,
        enable_if_t < conjunction_v < _Is_move_assignable_no_precondition_check < typename _Myself :: first_type >,
                        _Is_move_assignable_no_precondition_check < typename _Myself :: second_type >>,
            int > = 0 >
    inline pair & operator = ( _Identity_t < _Myself && > _Right )
        noexcept ( conjunction_v < is_nothrow_move_assignable < _Ty1 >, is_nothrow_move_assignable < _Ty2 >> ) {
        first = :: std :: forward < _Ty1 > ( _Right . first );
        second = :: std :: forward < _Ty2 > ( _Right . second );
        return * this;
    }














    template < class _Other1, class _Other2,
        enable_if_t < conjunction_v < negation < is_same < pair, pair < _Other1, _Other2 >> >, is_assignable < _Ty1 &, const _Other1 & >,
                        is_assignable < _Ty2 &, const _Other2 & >>,
            int > = 0 >
    inline pair & operator = ( const pair < _Other1, _Other2 > & _Right )
        noexcept ( is_nothrow_assignable_v < _Ty1 &, const _Other1 & >
                 && is_nothrow_assignable_v < _Ty2 &, const _Other2 & > ) {
        first = _Right . first;
        second = _Right . second;
        return * this;
    }














    template < class _Other1, class _Other2,
        enable_if_t < conjunction_v < negation < is_same < pair, pair < _Other1, _Other2 >> >, is_assignable < _Ty1 &, _Other1 >,
                        is_assignable < _Ty2 &, _Other2 >>,
            int > = 0 >
    inline pair & operator = ( pair < _Other1, _Other2 > && _Right ) noexcept (
        is_nothrow_assignable_v < _Ty1 &, _Other1 > && is_nothrow_assignable_v < _Ty2 &, _Other2 > ) {
        first = :: std :: forward < _Other1 > ( _Right . first );
        second = :: std :: forward < _Other2 > ( _Right . second );
        return * this;
    }





































    inline void swap ( pair & _Right )
        noexcept ( _Is_nothrow_swappable < _Ty1 > :: value && _Is_nothrow_swappable < _Ty2 > :: value ) {
        using :: std :: swap;
        swap ( first, _Right . first );
        swap ( second, _Right . second );
    }











    _Ty1 first;
    _Ty2 second;

private :
    template < class _Tuple1, class _Tuple2, size_t ... _Indices1, size_t ... _Indices2 >
    constexpr pair ( _Tuple1 & _Val1, _Tuple2 & _Val2, index_sequence < _Indices1 ... >, index_sequence < _Indices2 ... > )
        : first ( :: std :: _Tuple_get < _Indices1 > ( :: std :: move ( _Val1 ) ) ... ),
          second ( :: std :: _Tuple_get < _Indices2 > ( :: std :: move ( _Val2 ) ) ... ) { }
};
#line 487 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
template < class _Ty1, class _Ty2,
    enable_if_t < _Is_swappable < _Ty1 > :: value && _Is_swappable < _Ty2 > :: value, int > = 0 >
inline void swap ( pair < _Ty1, _Ty2 > & _Left, pair < _Ty1, _Ty2 > & _Right ) noexcept ( noexcept ( _Left . swap ( _Right ) ) ) {
    _Left . swap ( _Right );
}
#line 502 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
template < class _Ty1, class _Ty2, class _Uty1, class _Uty2 >
[ [ nodiscard ] ] constexpr bool operator == ( const pair < _Ty1, _Ty2 > & _Left, const pair < _Uty1, _Uty2 > & _Right ) {
    return _Left . first == _Right . first && _Left . second == _Right . second;
}
#line 518 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
template < class _Ty1, class _Ty2, class _Uty1, class _Uty2 >
[ [ nodiscard ] ] constexpr bool operator != ( const pair < _Ty1, _Ty2 > & _Left, const pair < _Uty1, _Uty2 > & _Right ) {
    return ! ( _Left == _Right );
}
#line 523
template < class _Ty1, class _Ty2, class _Uty1, class _Uty2 >
[ [ nodiscard ] ] constexpr bool operator < ( const pair < _Ty1, _Ty2 > & _Left, const pair < _Uty1, _Uty2 > & _Right ) {
    return _Left . first < _Right . first || ( ! ( _Right . first < _Left . first ) && _Left . second < _Right . second );
}
#line 528
template < class _Ty1, class _Ty2, class _Uty1, class _Uty2 >
[ [ nodiscard ] ] constexpr bool operator > ( const pair < _Ty1, _Ty2 > & _Left, const pair < _Uty1, _Uty2 > & _Right ) {
    return _Right < _Left;
}
#line 533
template < class _Ty1, class _Ty2, class _Uty1, class _Uty2 >
[ [ nodiscard ] ] constexpr bool operator <= ( const pair < _Ty1, _Ty2 > & _Left, const pair < _Uty1, _Uty2 > & _Right ) {
    return ! ( _Right < _Left );
}
#line 538
template < class _Ty1, class _Ty2, class _Uty1, class _Uty2 >
[ [ nodiscard ] ] constexpr bool operator >= ( const pair < _Ty1, _Ty2 > & _Left, const pair < _Uty1, _Uty2 > & _Right ) {
    return ! ( _Left < _Right );
}
#line 561 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
template< class _Ty> 
#line 562
struct _Unrefwrap_helper { 
#line 563
using type = _Ty; 
#line 564
}; 
#line 566
template< class _Ty> 
#line 567
struct _Unrefwrap_helper< reference_wrapper< _Ty> >  { 
#line 568
using type = _Ty &; 
#line 569
}; 
#line 572
template< class _Ty> using _Unrefwrap_t = typename _Unrefwrap_helper< decay_t< _Ty> > ::type; 
#line 575
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr pair < _Unrefwrap_t < _Ty1 >, _Unrefwrap_t < _Ty2 > > make_pair ( _Ty1 && _Val1, _Ty2 && _Val2 )
    noexcept ( is_nothrow_constructible_v < _Unrefwrap_t < _Ty1 >, _Ty1 >
             && is_nothrow_constructible_v < _Unrefwrap_t < _Ty2 >, _Ty2 > ) {

    using _Mypair = pair < _Unrefwrap_t < _Ty1 >, _Unrefwrap_t < _Ty2 >>;
    return _Mypair ( :: std :: forward < _Ty1 > ( _Val1 ), :: std :: forward < _Ty2 > ( _Val2 ) );
}
#line 584
namespace rel_ops { 
#line 585
template < class _Ty >
     [ [ nodiscard ] ] bool operator != ( const _Ty & _Left, const _Ty & _Right ) {
        return ! ( _Left == _Right );
    }
#line 590
template < class _Ty >
     [ [ nodiscard ] ] bool operator > ( const _Ty & _Left, const _Ty & _Right ) {
        return _Right < _Left;
    }
#line 595
template < class _Ty >
     [ [ nodiscard ] ] bool operator <= ( const _Ty & _Left, const _Ty & _Right ) {
        return ! ( _Right < _Left );
    }
#line 600
template < class _Ty >
     [ [ nodiscard ] ] bool operator >= ( const _Ty & _Left, const _Ty & _Right ) {
        return ! ( _Left < _Right );
    }
#line 604
}
#line 606
template< class _Tuple, class  = void> 
#line 607
struct _Tuple_size_sfinae { }; 
#line 609
template< class _Tuple> 
#line 610
struct _Tuple_size_sfinae< _Tuple, void_t< decltype(tuple_size< _Tuple> ::value)> >  : public integral_constant< unsigned __int64, tuple_size< _Tuple> ::value>  { 
#line 611
}; 
#line 613
template< class _Tuple> 
#line 614
struct tuple_size< const _Tuple>  : public _Tuple_size_sfinae< _Tuple>  { }; 
#line 616
template< class _Tuple> 
#line 617
struct tuple_size< volatile _Tuple>  : public _Tuple_size_sfinae< _Tuple>  { }; 
#line 619
template< class _Tuple> 
#line 620
struct tuple_size< const volatile _Tuple>  : public _Tuple_size_sfinae< _Tuple>  { }; 
#line 622
template< size_t _Index, class _Tuple> 
#line 623
struct [[msvc::known_semantics]] tuple_element< _Index, const _Tuple>  : public std::tuple_element< _Index, _Tuple>  { 
#line 624
using _Mybase = std::tuple_element< _Index, _Tuple> ; 
#line 625
using type = std::add_const_t< typename std::tuple_element< _Index, _Tuple> ::type> ; 
#line 626
}; 
#line 628
template< size_t _Index, class _Tuple> 
#line 629
struct [[msvc::known_semantics]] tuple_element< _Index, volatile _Tuple>  : public std::tuple_element< _Index, _Tuple>  { 
#line 631
using _Mybase = std::tuple_element< _Index, _Tuple> ; 
#line 632
using type = std::add_volatile_t< typename std::tuple_element< _Index, _Tuple> ::type> ; 
#line 633
}; 
#line 635
template< size_t _Index, class _Tuple> 
#line 636
struct [[msvc::known_semantics]] tuple_element< _Index, const volatile _Tuple>  : public std::tuple_element< _Index, _Tuple>  { 
#line 638
using _Mybase = std::tuple_element< _Index, _Tuple> ; 
#line 639
using type = std::add_cv_t< typename std::tuple_element< _Index, _Tuple> ::type> ; 
#line 640
}; 
#line 642
template< class _Ty, size_t _Size> 
#line 643
struct tuple_size< array< _Ty, _Size> >  : public integral_constant< unsigned __int64, _Size>  { }; 
#line 645
template< size_t _Idx, class _Ty, size_t _Size> 
#line 646
struct [[msvc::known_semantics]] tuple_element< _Idx, array< _Ty, _Size> >  { 
#line 647
static_assert((_Idx < _Size), "array index out of bounds");
#line 649
using type = _Ty; 
#line 650
}; 
#line 652
template< class ..._Types> 
#line 653
struct tuple_size< tuple< _Types...> >  : public integral_constant< unsigned __int64, sizeof...(_Types)>  { }; 
#line 655
template< size_t _Index> 
#line 656
struct [[msvc::known_semantics]] tuple_element< _Index, tuple< > >  { 
#line 657
static_assert((_Always_false< integral_constant< size_t, _Index> > ), "tuple index out of bounds");
#line 658
}; 
#line 660
template< class _This, class ..._Rest> 
#line 661
struct [[msvc::known_semantics]] tuple_element< 0, tuple< _This, _Rest...> >  { 
#line 662
using type = _This; 
#line 664
using _Ttype = tuple< _This, _Rest...> ; 
#line 665
}; 
#line 667
template< size_t _Index, class _This, class ..._Rest> 
#line 668
struct [[msvc::known_semantics]] tuple_element< _Index, tuple< _This, _Rest...> >  : public std::tuple_element< _Index - (1), tuple< _Rest...> >  { 
#line 669
}; 
#line 671
template< class _Ty1, class _Ty2> 
#line 672
struct tuple_size< pair< _Ty1, _Ty2> >  : public integral_constant< unsigned __int64, 2Ui64>  { }; 
#line 674
template< size_t _Idx, class _Ty1, class _Ty2> 
#line 675
struct [[msvc::known_semantics]] tuple_element< _Idx, pair< _Ty1, _Ty2> >  { 
#line 676
static_assert((_Idx < (2)), "pair index out of bounds");
#line 678
using type = conditional_t< _Idx == (0), _Ty1, _Ty2> ; 
#line 679
}; 
#line 681
template < size_t _Idx, class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr tuple_element_t < _Idx, pair < _Ty1, _Ty2 > > & get ( pair < _Ty1, _Ty2 > & _Pr ) noexcept {

    if constexpr ( _Idx == 0 ) {
        return _Pr . first;
    } else {
        return _Pr . second;
    }
}
#line 691
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr _Ty1 & get ( pair < _Ty1, _Ty2 > & _Pr ) noexcept {

    return _Pr . first;
}
#line 697
template < class _Ty2, class _Ty1 >
[ [ nodiscard ] ] constexpr _Ty2 & get ( pair < _Ty1, _Ty2 > & _Pr ) noexcept {

    return _Pr . second;
}
#line 703
template < size_t _Idx, class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr const tuple_element_t < _Idx, pair < _Ty1, _Ty2 > > & get ( const pair < _Ty1, _Ty2 > & _Pr ) noexcept {

    if constexpr ( _Idx == 0 ) {
        return _Pr . first;
    } else {
        return _Pr . second;
    }
}
#line 713
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr const _Ty1 & get ( const pair < _Ty1, _Ty2 > & _Pr ) noexcept {

    return _Pr . first;
}
#line 719
template < class _Ty2, class _Ty1 >
[ [ nodiscard ] ] constexpr const _Ty2 & get ( const pair < _Ty1, _Ty2 > & _Pr ) noexcept {

    return _Pr . second;
}
#line 725
template < size_t _Idx, class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr tuple_element_t < _Idx, pair < _Ty1, _Ty2 > > && get ( pair < _Ty1, _Ty2 > && _Pr ) noexcept {

    if constexpr ( _Idx == 0 ) {
        return :: std :: forward < _Ty1 > ( _Pr . first );
    } else {
        return :: std :: forward < _Ty2 > ( _Pr . second );
    }
}
#line 735
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr _Ty1 && get ( pair < _Ty1, _Ty2 > && _Pr ) noexcept {

    return :: std :: forward < _Ty1 > ( _Pr . first );
}
#line 741
template < class _Ty2, class _Ty1 >
[ [ nodiscard ] ] constexpr _Ty2 && get ( pair < _Ty1, _Ty2 > && _Pr ) noexcept {

    return :: std :: forward < _Ty2 > ( _Pr . second );
}
#line 747
template < size_t _Idx, class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr const tuple_element_t < _Idx, pair < _Ty1, _Ty2 > > && get ( const pair < _Ty1, _Ty2 > && _Pr ) noexcept {

    if constexpr ( _Idx == 0 ) {
        return :: std :: forward < const _Ty1 > ( _Pr . first );
    } else {
        return :: std :: forward < const _Ty2 > ( _Pr . second );
    }
}
#line 757
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr const _Ty1 && get ( const pair < _Ty1, _Ty2 > && _Pr ) noexcept {

    return :: std :: forward < const _Ty1 > ( _Pr . first );
}
#line 763
template < class _Ty2, class _Ty1 >
[ [ nodiscard ] ] constexpr const _Ty2 && get ( const pair < _Ty1, _Ty2 > && _Pr ) noexcept {

    return :: std :: forward < const _Ty2 > ( _Pr . second );
}
#line 769
template < class _Ty, class _Other = _Ty >
inline _Ty exchange ( _Ty & _Val, _Other && _New_val )
    noexcept ( conjunction_v < is_nothrow_move_constructible < _Ty >, is_nothrow_assignable < _Ty &, _Other >> ) {

    _Ty _Old_val = static_cast < _Ty && > ( _Val );
    _Val = static_cast < _Other && > ( _New_val );
    return _Old_val;
}
#line 778
template < class _Ty >
[ [ nodiscard ] ] [ [ msvc :: intrinsic ] ] constexpr add_const_t < _Ty > & as_const ( _Ty & _Val ) noexcept {
    return _Val;
}
#line 783
template < class _Ty >
void as_const ( const _Ty && ) = delete;
#line 807 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr bool _Cmp_equal ( const _Ty1 _Left, const _Ty2 _Right ) noexcept {
    ;
    if constexpr ( is_signed_v < _Ty1 > == is_signed_v < _Ty2 > ) {
        return _Left == _Right;
    } else if constexpr ( is_signed_v < _Ty2 > ) {
        return _Left == static_cast < make_unsigned_t < _Ty2 >> ( _Right ) && _Right >= 0;
    } else {
        return static_cast < make_unsigned_t < _Ty1 >> ( _Left ) == _Right && _Left >= 0;
    }
}
#line 819
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr bool _Cmp_not_equal ( const _Ty1 _Left, const _Ty2 _Right ) noexcept {
    return ! :: std :: _Cmp_equal ( _Left, _Right );
}
#line 824
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr bool _Cmp_less ( const _Ty1 _Left, const _Ty2 _Right ) noexcept {
    ;
    if constexpr ( is_signed_v < _Ty1 > == is_signed_v < _Ty2 > ) {
        return _Left < _Right;
    } else if constexpr ( is_signed_v < _Ty2 > ) {
        return _Right > 0 && _Left < static_cast < make_unsigned_t < _Ty2 >> ( _Right );
    } else {
        return _Left < 0 || static_cast < make_unsigned_t < _Ty1 >> ( _Left ) < _Right;
    }
}
#line 836
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr bool _Cmp_greater ( const _Ty1 _Left, const _Ty2 _Right ) noexcept {
    return :: std :: _Cmp_less ( _Right, _Left );
}
#line 841
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr bool _Cmp_less_equal ( const _Ty1 _Left, const _Ty2 _Right ) noexcept {
    return ! :: std :: _Cmp_less ( _Right, _Left );
}
#line 846
template < class _Ty1, class _Ty2 >
[ [ nodiscard ] ] constexpr bool _Cmp_greater_equal ( const _Ty1 _Left, const _Ty2 _Right ) noexcept {
    return ! :: std :: _Cmp_less ( _Left, _Right );
}
#line 851
template < class _Ty >
[ [ nodiscard ] ] constexpr _Ty _Min_limit ( ) noexcept {
    ;
    if constexpr ( is_signed_v < _Ty > ) {
        constexpr auto _Unsigned_max = static_cast < make_unsigned_t < _Ty >> ( - 1 );
        return static_cast < _Ty > ( ( _Unsigned_max >> 1 ) + 1 );
    } else {
        return 0;
    }
}
#line 862
template < class _Ty >
[ [ nodiscard ] ] constexpr _Ty _Max_limit ( ) noexcept {
    ;
    if constexpr ( is_signed_v < _Ty > ) {
        constexpr auto _Unsigned_max = static_cast < make_unsigned_t < _Ty >> ( - 1 );
        return static_cast < _Ty > ( _Unsigned_max >> 1 );
    } else {
        return static_cast < _Ty > ( - 1 );
    }
}
#line 873
template < class _Rx, class _Ty >
[ [ nodiscard ] ] constexpr bool _In_range ( const _Ty _Value ) noexcept {
    ;

    constexpr auto _Ty_min = _Min_limit < _Ty > ( );
    constexpr auto _Rx_min = _Min_limit < _Rx > ( );

    if constexpr ( :: std :: _Cmp_less ( _Ty_min, _Rx_min ) ) {
        if ( _Value < _Ty { _Rx_min } ) {
            return false;
        }
    }

    constexpr auto _Ty_max = _Max_limit < _Ty > ( );
    constexpr auto _Rx_max = _Max_limit < _Rx > ( );

    if constexpr ( :: std :: _Cmp_greater ( _Ty_max, _Rx_max ) ) {
        if ( _Value > _Ty { _Rx_max } ) {
            return false;
        }
    }

    return true;
}
#line 977 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
namespace [[deprecated("warning STL4002: The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can define _" "SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to suppress this warning.")]] tr1 { 
#line 978
using std::get;
#line 979
using std::tuple_element;
#line 980
using std::tuple_size;
#line 981
}
#line 984 "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\MSVC\\14.44.35207\\include\\utility"
}
#line 994
#pragma warning(pop)
#pragma pack ( pop )
#line 207 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
template< class T> static __inline ::cudaError_t 
#line 208
cudaLaunchKernel(T *
#line 209
func, ::dim3 
#line 210
gridDim, ::dim3 
#line 211
blockDim, void **
#line 212
args, ::size_t 
#line 213
sharedMem = 0, ::cudaStream_t 
#line 214
stream = 0) 
#line 216
{ 
#line 217
return ::cudaLaunchKernel((const void *)func, gridDim, blockDim, args, sharedMem, stream); 
#line 218
} 
#line 279
template< class ...ExpTypes, class ...ActTypes> static __inline ::cudaError_t 
#line 280
cudaLaunchKernelEx(const ::cudaLaunchConfig_t *
#line 281
config, void (*
#line 282
kernel)(ExpTypes ...), ActTypes &&...
#line 283
args) 
#line 285
{ 
#line 286
return [&](ExpTypes ...coercedArgs) { 
#line 287
void *pArgs[] = {(&coercedArgs)...}; 
#line 288
return ::cudaLaunchKernelExC(config, (const void *)(kernel), pArgs); 
#line 289
} (std::forward< ActTypes> (args)...); 
#line 290
} 
#line 348
template< class ...ActTypes> static __inline ::cudaError_t 
#line 349
cudaLaunchKernelEx(const ::cudaLaunchConfig_t *
#line 350
config, const ::cudaKernel_t 
#line 351
kernel, ActTypes &&...
#line 352
args) 
#line 354
{ 
#line 355
void *pArgs[] = {(&args)...}; 
#line 356
return ::cudaLaunchKernelExC(config, (const void *)kernel, pArgs); 
#line 357
} 
#line 410 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
template< class T> static __inline ::cudaError_t 
#line 411
cudaLaunchCooperativeKernel(T *
#line 412
func, ::dim3 
#line 413
gridDim, ::dim3 
#line 414
blockDim, void **
#line 415
args, ::size_t 
#line 416
sharedMem = 0, ::cudaStream_t 
#line 417
stream = 0) 
#line 419
{ 
#line 420
return ::cudaLaunchCooperativeKernel((const void *)func, gridDim, blockDim, args, sharedMem, stream); 
#line 421
} 
#line 454
static __inline cudaError_t cudaEventCreate(cudaEvent_t *
#line 455
event, unsigned 
#line 456
flags) 
#line 458
{ 
#line 459
return ::cudaEventCreateWithFlags(event, flags); 
#line 460
} 
#line 498
static __inline cudaError_t cudaGraphInstantiate(cudaGraphExec_t *
#line 499
pGraphExec, cudaGraph_t 
#line 500
graph, cudaGraphNode_t *
#line 501
pErrorNode, char *
#line 502
pLogBuffer, size_t 
#line 503
bufferSize) 
#line 505
{ 
#line 506
(void)pErrorNode; 
#line 507
(void)pLogBuffer; 
#line 508
(void)bufferSize; 
#line 509
return ::cudaGraphInstantiate(pGraphExec, graph, 0); 
#line 510
} 
#line 569
static __inline cudaError_t cudaMallocHost(void **
#line 570
ptr, size_t 
#line 571
size, unsigned 
#line 572
flags) 
#line 574
{ 
#line 575
return ::cudaHostAlloc(ptr, size, flags); 
#line 576
} 
#line 578
template< class T> static __inline ::cudaError_t 
#line 579
cudaHostAlloc(T **
#line 580
ptr, ::size_t 
#line 581
size, unsigned 
#line 582
flags) 
#line 584
{ 
#line 585
return ::cudaHostAlloc((void **)((void *)ptr), size, flags); 
#line 586
} 
#line 588
template< class T> static __inline ::cudaError_t 
#line 589
cudaHostGetDevicePointer(T **
#line 590
pDevice, void *
#line 591
pHost, unsigned 
#line 592
flags) 
#line 594
{ 
#line 595
return ::cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags); 
#line 596
} 
#line 698
template< class T> static __inline ::cudaError_t 
#line 699
cudaMallocManaged(T **
#line 700
devPtr, ::size_t 
#line 701
size, unsigned 
#line 702
flags = 1) 
#line 704
{ 
#line 705
return ::cudaMallocManaged((void **)((void *)devPtr), size, flags); 
#line 706
} 
#line 716
template< class T> static __inline ::cudaError_t 
#line 717
cudaMemPrefetchBatchAsync(T **
#line 718
dptrs, ::size_t *sizes, ::size_t count, ::cudaMemLocation *
#line 719
prefetchLocs, ::size_t *prefetchLocIdxs, ::size_t numPrefetchLocs, unsigned __int64 
#line 720
flags, ::cudaStream_t stream) 
#line 722
{ 
#line 723
return ::cudaMemPrefetchBatchAsync((void **)dptrs, sizes, count, prefetchLocs, prefetchLocIdxs, numPrefetchLocs, flags, stream); 
#line 724
} 
#line 736
template< class T> static __inline ::cudaError_t 
#line 737
cudaMemPrefetchBatchAsync(T **
#line 738
dptrs, ::size_t *sizes, ::size_t count, ::cudaMemLocation prefetchLocs, unsigned __int64 flags, ::cudaStream_t stream) 
#line 740
{ 
#line 741
::size_t prefetchLocIdxs = (0); 
#line 742
return ::cudaMemPrefetchBatchAsync((void **)dptrs, sizes, count, &prefetchLocs, &prefetchLocIdxs, 1, flags, stream); 
#line 743
} 
#line 753
template< class T> static __inline ::cudaError_t 
#line 754
cudaMemDiscardAndPrefetchBatchAsync(T **
#line 755
dptrs, ::size_t *sizes, ::size_t count, ::cudaMemLocation *
#line 756
prefetchLocs, ::size_t *prefetchLocIdxs, ::size_t numPrefetchLocs, unsigned __int64 
#line 757
flags, ::cudaStream_t stream) 
#line 759
{ 
#line 760
return ::cudaMemDiscardAndPrefetchBatchAsync((void **)dptrs, sizes, count, prefetchLocs, prefetchLocIdxs, numPrefetchLocs, flags, stream); 
#line 761
} 
#line 773
template< class T> static __inline ::cudaError_t 
#line 774
cudaMemDiscardAndPrefetchBatchAsync(T **
#line 775
dptrs, ::size_t *sizes, ::size_t count, ::cudaMemLocation prefetchLocs, unsigned __int64 flags, ::cudaStream_t stream) 
#line 777
{ 
#line 778
::size_t prefetchLocIdxs = (0); 
#line 779
return ::cudaMemDiscardAndPrefetchBatchAsync((void **)dptrs, sizes, count, &prefetchLocs, &prefetchLocIdxs, 1, flags, stream); 
#line 780
} 
#line 862
template< class T> static __inline ::cudaError_t 
#line 863
cudaStreamAttachMemAsync(::cudaStream_t 
#line 864
stream, T *
#line 865
devPtr, ::size_t 
#line 866
length = 0, unsigned 
#line 867
flags = 4) 
#line 869
{ 
#line 870
return ::cudaStreamAttachMemAsync(stream, (void *)devPtr, length, flags); 
#line 871
} 
#line 873
template< class T> __inline ::cudaError_t 
#line 874
cudaMalloc(T **
#line 875
devPtr, ::size_t 
#line 876
size) 
#line 878
{ 
#line 879
return ::cudaMalloc((void **)((void *)devPtr), size); 
#line 880
} 
#line 882
template< class T> static __inline ::cudaError_t 
#line 883
cudaMallocHost(T **
#line 884
ptr, ::size_t 
#line 885
size, unsigned 
#line 886
flags = 0) 
#line 888
{ 
#line 889
return cudaMallocHost((void **)((void *)ptr), size, flags); 
#line 890
} 
#line 892
template< class T> static __inline ::cudaError_t 
#line 893
cudaMallocPitch(T **
#line 894
devPtr, ::size_t *
#line 895
pitch, ::size_t 
#line 896
width, ::size_t 
#line 897
height) 
#line 899
{ 
#line 900
return ::cudaMallocPitch((void **)((void *)devPtr), pitch, width, height); 
#line 901
} 
#line 912
static __inline cudaError_t cudaMallocAsync(void **
#line 913
ptr, size_t 
#line 914
size, cudaMemPool_t 
#line 915
memPool, cudaStream_t 
#line 916
stream) 
#line 918
{ 
#line 919
return ::cudaMallocFromPoolAsync(ptr, size, memPool, stream); 
#line 920
} 
#line 922
template< class T> static __inline ::cudaError_t 
#line 923
cudaMallocAsync(T **
#line 924
ptr, ::size_t 
#line 925
size, ::cudaMemPool_t 
#line 926
memPool, ::cudaStream_t 
#line 927
stream) 
#line 929
{ 
#line 930
return ::cudaMallocFromPoolAsync((void **)((void *)ptr), size, memPool, stream); 
#line 931
} 
#line 933
template< class T> static __inline ::cudaError_t 
#line 934
cudaMallocAsync(T **
#line 935
ptr, ::size_t 
#line 936
size, ::cudaStream_t 
#line 937
stream) 
#line 939
{ 
#line 940
return ::cudaMallocAsync((void **)((void *)ptr), size, stream); 
#line 941
} 
#line 943
template< class T> static __inline ::cudaError_t 
#line 944
cudaMallocFromPoolAsync(T **
#line 945
ptr, ::size_t 
#line 946
size, ::cudaMemPool_t 
#line 947
memPool, ::cudaStream_t 
#line 948
stream) 
#line 950
{ 
#line 951
return ::cudaMallocFromPoolAsync((void **)((void *)ptr), size, memPool, stream); 
#line 952
} 
#line 962
template< class T, class U> static __inline ::cudaError_t 
#line 963
cudaMemcpyBatchAsync(T *const *
#line 964
dsts, U *const *srcs, const ::size_t *sizes, ::size_t count, ::cudaMemcpyAttributes *attrs, ::size_t *
#line 965
attrsIdxs, ::size_t numAttrs, ::cudaStream_t 
#line 966
hStream) 
#line 968
{ 
#line 969
return ::cudaMemcpyBatchAsync((void *const *)dsts, (const void *const *)srcs, (const ::size_t *)sizes, count, attrs, attrsIdxs, numAttrs, hStream); 
#line 970
} 
#line 982
template< class T, class U> static __inline ::cudaError_t 
#line 983
cudaMemcpyBatchAsync(T *const *
#line 984
dsts, U *const *srcs, const ::size_t *sizes, ::size_t count, ::cudaMemcpyAttributes attr, ::cudaStream_t 
#line 985
hStream) 
#line 987
{ 
#line 988
::size_t attrsIdxs = (0); 
#line 989
return ::cudaMemcpyBatchAsync((void *const *)dsts, (const void *const *)srcs, (const ::size_t *)sizes, count, &attr, &attrsIdxs, 1, hStream); 
#line 990
} 
#line 1029
template< class T> static __inline ::cudaError_t 
#line 1030
cudaMemcpyToSymbol(const T &
#line 1031
symbol, const void *
#line 1032
src, ::size_t 
#line 1033
count, ::size_t 
#line 1034
offset = 0, ::cudaMemcpyKind 
#line 1035
kind = cudaMemcpyHostToDevice) 
#line 1037
{ 
#line 1038
return ::cudaMemcpyToSymbol((const void *)(&symbol), src, count, offset, kind); 
#line 1039
} 
#line 1083
template< class T> static __inline ::cudaError_t 
#line 1084
cudaMemcpyToSymbolAsync(const T &
#line 1085
symbol, const void *
#line 1086
src, ::size_t 
#line 1087
count, ::size_t 
#line 1088
offset = 0, ::cudaMemcpyKind 
#line 1089
kind = cudaMemcpyHostToDevice, ::cudaStream_t 
#line 1090
stream = 0) 
#line 1092
{ 
#line 1093
return ::cudaMemcpyToSymbolAsync((const void *)(&symbol), src, count, offset, kind, stream); 
#line 1094
} 
#line 1131
template< class T> static __inline ::cudaError_t 
#line 1132
cudaMemcpyFromSymbol(void *
#line 1133
dst, const T &
#line 1134
symbol, ::size_t 
#line 1135
count, ::size_t 
#line 1136
offset = 0, ::cudaMemcpyKind 
#line 1137
kind = cudaMemcpyDeviceToHost) 
#line 1139
{ 
#line 1140
return ::cudaMemcpyFromSymbol(dst, (const void *)(&symbol), count, offset, kind); 
#line 1141
} 
#line 1185
template< class T> static __inline ::cudaError_t 
#line 1186
cudaMemcpyFromSymbolAsync(void *
#line 1187
dst, const T &
#line 1188
symbol, ::size_t 
#line 1189
count, ::size_t 
#line 1190
offset = 0, ::cudaMemcpyKind 
#line 1191
kind = cudaMemcpyDeviceToHost, ::cudaStream_t 
#line 1192
stream = 0) 
#line 1194
{ 
#line 1195
return ::cudaMemcpyFromSymbolAsync(dst, (const void *)(&symbol), count, offset, kind, stream); 
#line 1196
} 
#line 1254
template< class T> static __inline ::cudaError_t 
#line 1255
cudaGraphAddMemcpyNodeToSymbol(::cudaGraphNode_t *
#line 1256
pGraphNode, ::cudaGraph_t 
#line 1257
graph, const ::cudaGraphNode_t *
#line 1258
pDependencies, ::size_t 
#line 1259
numDependencies, const T &
#line 1260
symbol, const void *
#line 1261
src, ::size_t 
#line 1262
count, ::size_t 
#line 1263
offset, ::cudaMemcpyKind 
#line 1264
kind) 
#line 1265
{ 
#line 1266
return ::cudaGraphAddMemcpyNodeToSymbol(pGraphNode, graph, pDependencies, numDependencies, (const void *)(&symbol), src, count, offset, kind); 
#line 1267
} 
#line 1325
template< class T> static __inline ::cudaError_t 
#line 1326
cudaGraphAddMemcpyNodeFromSymbol(::cudaGraphNode_t *
#line 1327
pGraphNode, ::cudaGraph_t 
#line 1328
graph, const ::cudaGraphNode_t *
#line 1329
pDependencies, ::size_t 
#line 1330
numDependencies, void *
#line 1331
dst, const T &
#line 1332
symbol, ::size_t 
#line 1333
count, ::size_t 
#line 1334
offset, ::cudaMemcpyKind 
#line 1335
kind) 
#line 1336
{ 
#line 1337
return ::cudaGraphAddMemcpyNodeFromSymbol(pGraphNode, graph, pDependencies, numDependencies, dst, (const void *)(&symbol), count, offset, kind); 
#line 1338
} 
#line 1376
template< class T> static __inline ::cudaError_t 
#line 1377
cudaGraphMemcpyNodeSetParamsToSymbol(::cudaGraphNode_t 
#line 1378
node, const T &
#line 1379
symbol, const void *
#line 1380
src, ::size_t 
#line 1381
count, ::size_t 
#line 1382
offset, ::cudaMemcpyKind 
#line 1383
kind) 
#line 1384
{ 
#line 1385
return ::cudaGraphMemcpyNodeSetParamsToSymbol(node, (const void *)(&symbol), src, count, offset, kind); 
#line 1386
} 
#line 1424
template< class T> static __inline ::cudaError_t 
#line 1425
cudaGraphMemcpyNodeSetParamsFromSymbol(::cudaGraphNode_t 
#line 1426
node, void *
#line 1427
dst, const T &
#line 1428
symbol, ::size_t 
#line 1429
count, ::size_t 
#line 1430
offset, ::cudaMemcpyKind 
#line 1431
kind) 
#line 1432
{ 
#line 1433
return ::cudaGraphMemcpyNodeSetParamsFromSymbol(node, dst, (const void *)(&symbol), count, offset, kind); 
#line 1434
} 
#line 1482
template< class T> static __inline ::cudaError_t 
#line 1483
cudaGraphExecMemcpyNodeSetParamsToSymbol(::cudaGraphExec_t 
#line 1484
hGraphExec, ::cudaGraphNode_t 
#line 1485
node, const T &
#line 1486
symbol, const void *
#line 1487
src, ::size_t 
#line 1488
count, ::size_t 
#line 1489
offset, ::cudaMemcpyKind 
#line 1490
kind) 
#line 1491
{ 
#line 1492
return ::cudaGraphExecMemcpyNodeSetParamsToSymbol(hGraphExec, node, (const void *)(&symbol), src, count, offset, kind); 
#line 1493
} 
#line 1541
template< class T> static __inline ::cudaError_t 
#line 1542
cudaGraphExecMemcpyNodeSetParamsFromSymbol(::cudaGraphExec_t 
#line 1543
hGraphExec, ::cudaGraphNode_t 
#line 1544
node, void *
#line 1545
dst, const T &
#line 1546
symbol, ::size_t 
#line 1547
count, ::size_t 
#line 1548
offset, ::cudaMemcpyKind 
#line 1549
kind) 
#line 1550
{ 
#line 1551
return ::cudaGraphExecMemcpyNodeSetParamsFromSymbol(hGraphExec, node, dst, (const void *)(&symbol), count, offset, kind); 
#line 1552
} 
#line 1555
static __inline cudaError_t __stdcall cudaGraphExecUpdate(cudaGraphExec_t hGraphExec, cudaGraph_t hGraph, cudaGraphNode_t *hErrorNode_out, cudaGraphExecUpdateResult *updateResult_out) 
#line 1556
{ 
#line 1557
cudaGraphExecUpdateResultInfo resultInfo; 
#line 1558
cudaError_t status = cudaGraphExecUpdate(hGraphExec, hGraph, &resultInfo); 
#line 1559
if (hErrorNode_out) { 
#line 1560
(*hErrorNode_out) = (resultInfo.errorNode); 
#line 1561
}  
#line 1562
if (updateResult_out) { 
#line 1563
(*updateResult_out) = (resultInfo.result); 
#line 1564
}  
#line 1565
return status; 
#line 1566
} 
#line 1594
template< class T> static __inline ::cudaError_t 
#line 1595
cudaUserObjectCreate(::cudaUserObject_t *
#line 1596
object_out, T *
#line 1597
objectToWrap, unsigned 
#line 1598
initialRefcount, unsigned 
#line 1599
flags) 
#line 1600
{ 
#line 1601
return ::cudaUserObjectCreate(object_out, objectToWrap, [](void *
#line 1604
vpObj) { delete (reinterpret_cast< T *>(vpObj)); } , initialRefcount, flags); 
#line 1607
} 
#line 1609
template< class T> static __inline ::cudaError_t 
#line 1610
cudaUserObjectCreate(::cudaUserObject_t *
#line 1611
object_out, T *
#line 1612
objectToWrap, unsigned 
#line 1613
initialRefcount, ::cudaUserObjectFlags 
#line 1614
flags) 
#line 1615
{ 
#line 1616
return cudaUserObjectCreate(object_out, objectToWrap, initialRefcount, (unsigned)flags); 
#line 1617
} 
#line 1644 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
template< class T> static __inline ::cudaError_t 
#line 1645
cudaGetSymbolAddress(void **
#line 1646
devPtr, const T &
#line 1647
symbol) 
#line 1649
{ 
#line 1650
return ::cudaGetSymbolAddress(devPtr, (const void *)(&symbol)); 
#line 1651
} 
#line 1676
template< class T> static __inline ::cudaError_t 
#line 1677
cudaGetSymbolSize(::size_t *
#line 1678
size, const T &
#line 1679
symbol) 
#line 1681
{ 
#line 1682
return ::cudaGetSymbolSize(size, (const void *)(&symbol)); 
#line 1683
} 
#line 1728
template< class T> static __inline ::cudaError_t 
#line 1729
cudaFuncSetCacheConfig(T *
#line 1730
func, ::cudaFuncCache 
#line 1731
cacheConfig) 
#line 1733
{ 
#line 1734
return ::cudaFuncSetCacheConfig((const void *)func, cacheConfig); 
#line 1735
} 
#line 1737
template< class T> 
#line 1739
__declspec(deprecated) static __inline ::cudaError_t 
#line 1740
cudaFuncSetSharedMemConfig(T *
#line 1741
func, ::cudaSharedMemConfig 
#line 1742
config) 
#line 1744
{ 
#line 1749 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
#pragma warning(suppress: 4996)
#line 1751 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
return ::cudaFuncSetSharedMemConfig((const void *)func, config); 
#line 1755 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
} 
#line 1788 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
template< class T> __inline ::cudaError_t 
#line 1789
cudaOccupancyMaxActiveBlocksPerMultiprocessor(int *
#line 1790
numBlocks, T 
#line 1791
func, int 
#line 1792
blockSize, ::size_t 
#line 1793
dynamicSMemSize) 
#line 1794
{ 
#line 1795
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, 0); 
#line 1796
} 
#line 1841
template< class T> __inline ::cudaError_t 
#line 1842
cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *
#line 1843
numBlocks, T 
#line 1844
func, int 
#line 1845
blockSize, ::size_t 
#line 1846
dynamicSMemSize, unsigned 
#line 1847
flags) 
#line 1848
{ 
#line 1849
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, flags); 
#line 1850
} 
#line 1855
class __cudaOccupancyB2DHelper { 
#line 1856
size_t n; 
#line 1858
public: __cudaOccupancyB2DHelper(size_t n_) : n(n_) { } 
#line 1859
size_t operator()(int) 
#line 1860
{ 
#line 1861
return n; 
#line 1862
} 
#line 1863
}; 
#line 1911
template< class UnaryFunction, class T> static __inline ::cudaError_t 
#line 1912
cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(int *
#line 1913
minGridSize, int *
#line 1914
blockSize, T 
#line 1915
func, UnaryFunction 
#line 1916
blockSizeToDynamicSMemSize, int 
#line 1917
blockSizeLimit = 0, unsigned 
#line 1918
flags = 0) 
#line 1919
{ 
#line 1920
::cudaError_t status; 
#line 1923
int device; 
#line 1924
::cudaFuncAttributes attr; 
#line 1927
int maxThreadsPerMultiProcessor; 
#line 1928
int warpSize; 
#line 1929
int devMaxThreadsPerBlock; 
#line 1930
int multiProcessorCount; 
#line 1931
int funcMaxThreadsPerBlock; 
#line 1932
int occupancyLimit; 
#line 1933
int granularity; 
#line 1936
int maxBlockSize = 0; 
#line 1937
int numBlocks = 0; 
#line 1938
int maxOccupancy = 0; 
#line 1941
int blockSizeToTryAligned; 
#line 1942
int blockSizeToTry; 
#line 1943
int blockSizeLimitAligned; 
#line 1944
int occupancyInBlocks; 
#line 1945
int occupancyInThreads; 
#line 1946
::size_t dynamicSMemSize; 
#line 1952
if (((!minGridSize) || (!blockSize)) || (!func)) { 
#line 1953
return cudaErrorInvalidValue; 
#line 1954
}  
#line 1960
status = ::cudaGetDevice(&device); 
#line 1961
if (status != (cudaSuccess)) { 
#line 1962
return status; 
#line 1963
}  
#line 1965
status = cudaDeviceGetAttribute(&maxThreadsPerMultiProcessor, cudaDevAttrMaxThreadsPerMultiProcessor, device); 
#line 1969
if (status != (cudaSuccess)) { 
#line 1970
return status; 
#line 1971
}  
#line 1973
status = cudaDeviceGetAttribute(&warpSize, cudaDevAttrWarpSize, device); 
#line 1977
if (status != (cudaSuccess)) { 
#line 1978
return status; 
#line 1979
}  
#line 1981
status = cudaDeviceGetAttribute(&devMaxThreadsPerBlock, cudaDevAttrMaxThreadsPerBlock, device); 
#line 1985
if (status != (cudaSuccess)) { 
#line 1986
return status; 
#line 1987
}  
#line 1989
status = cudaDeviceGetAttribute(&multiProcessorCount, cudaDevAttrMultiProcessorCount, device); 
#line 1993
if (status != (cudaSuccess)) { 
#line 1994
return status; 
#line 1995
}  
#line 1997
status = cudaFuncGetAttributes(&attr, func); 
#line 1998
if (status != (cudaSuccess)) { 
#line 1999
return status; 
#line 2000
}  
#line 2002
funcMaxThreadsPerBlock = (attr.maxThreadsPerBlock); 
#line 2008
occupancyLimit = maxThreadsPerMultiProcessor; 
#line 2009
granularity = warpSize; 
#line 2011
if (blockSizeLimit == 0) { 
#line 2012
blockSizeLimit = devMaxThreadsPerBlock; 
#line 2013
}  
#line 2015
if (devMaxThreadsPerBlock < blockSizeLimit) { 
#line 2016
blockSizeLimit = devMaxThreadsPerBlock; 
#line 2017
}  
#line 2019
if (funcMaxThreadsPerBlock < blockSizeLimit) { 
#line 2020
blockSizeLimit = funcMaxThreadsPerBlock; 
#line 2021
}  
#line 2023
blockSizeLimitAligned = (((blockSizeLimit + (granularity - 1)) / granularity) * granularity); 
#line 2025
for (blockSizeToTryAligned = blockSizeLimitAligned; blockSizeToTryAligned > 0; blockSizeToTryAligned -= granularity) { 
#line 2029
if (blockSizeLimit < blockSizeToTryAligned) { 
#line 2030
blockSizeToTry = blockSizeLimit; 
#line 2031
} else { 
#line 2032
blockSizeToTry = blockSizeToTryAligned; 
#line 2033
}  
#line 2035
dynamicSMemSize = blockSizeToDynamicSMemSize(blockSizeToTry); 
#line 2037
status = cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(&occupancyInBlocks, func, blockSizeToTry, dynamicSMemSize, flags); 
#line 2044
if (status != (cudaSuccess)) { 
#line 2045
return status; 
#line 2046
}  
#line 2048
occupancyInThreads = (blockSizeToTry * occupancyInBlocks); 
#line 2050
if (occupancyInThreads > maxOccupancy) { 
#line 2051
maxBlockSize = blockSizeToTry; 
#line 2052
numBlocks = occupancyInBlocks; 
#line 2053
maxOccupancy = occupancyInThreads; 
#line 2054
}  
#line 2058
if (occupancyLimit == maxOccupancy) { 
#line 2059
break; 
#line 2060
}  
#line 2061
}  
#line 2069
(*minGridSize) = (numBlocks * multiProcessorCount); 
#line 2070
(*blockSize) = maxBlockSize; 
#line 2072
return status; 
#line 2073
} 
#line 2107
template< class UnaryFunction, class T> static __inline ::cudaError_t 
#line 2108
cudaOccupancyMaxPotentialBlockSizeVariableSMem(int *
#line 2109
minGridSize, int *
#line 2110
blockSize, T 
#line 2111
func, UnaryFunction 
#line 2112
blockSizeToDynamicSMemSize, int 
#line 2113
blockSizeLimit = 0) 
#line 2114
{ 
#line 2115
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, blockSizeLimit, 0); 
#line 2116
} 
#line 2153
template< class T> static __inline ::cudaError_t 
#line 2154
cudaOccupancyMaxPotentialBlockSize(int *
#line 2155
minGridSize, int *
#line 2156
blockSize, T 
#line 2157
func, ::size_t 
#line 2158
dynamicSMemSize = 0, int 
#line 2159
blockSizeLimit = 0) 
#line 2160
{ 
#line 2161
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((::__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, 0); 
#line 2162
} 
#line 2192
template< class T> static __inline ::cudaError_t 
#line 2193
cudaOccupancyAvailableDynamicSMemPerBlock(::size_t *
#line 2194
dynamicSmemSize, T *
#line 2195
func, int 
#line 2196
numBlocks, int 
#line 2197
blockSize) 
#line 2198
{ 
#line 2199
return ::cudaOccupancyAvailableDynamicSMemPerBlock(dynamicSmemSize, (const void *)func, numBlocks, blockSize); 
#line 2200
} 
#line 2251
template< class T> static __inline ::cudaError_t 
#line 2252
cudaOccupancyMaxPotentialBlockSizeWithFlags(int *
#line 2253
minGridSize, int *
#line 2254
blockSize, T 
#line 2255
func, ::size_t 
#line 2256
dynamicSMemSize = 0, int 
#line 2257
blockSizeLimit = 0, unsigned 
#line 2258
flags = 0) 
#line 2259
{ 
#line 2260
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((::__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, flags); 
#line 2261
} 
#line 2296
template< class T> static __inline ::cudaError_t 
#line 2297
cudaOccupancyMaxPotentialClusterSize(int *
#line 2298
clusterSize, T *
#line 2299
func, const ::cudaLaunchConfig_t *
#line 2300
config) 
#line 2301
{ 
#line 2302
return ::cudaOccupancyMaxPotentialClusterSize(clusterSize, (const void *)func, config); 
#line 2303
} 
#line 2340
template< class T> static __inline ::cudaError_t 
#line 2341
cudaOccupancyMaxActiveClusters(int *
#line 2342
numClusters, T *
#line 2343
func, const ::cudaLaunchConfig_t *
#line 2344
config) 
#line 2345
{ 
#line 2346
return ::cudaOccupancyMaxActiveClusters(numClusters, (const void *)func, config); 
#line 2347
} 
#line 2381
template< class T> __inline ::cudaError_t 
#line 2382
cudaFuncGetAttributes(::cudaFuncAttributes *
#line 2383
attr, T *
#line 2384
entry) 
#line 2386
{ 
#line 2387
return ::cudaFuncGetAttributes(attr, (const void *)entry); 
#line 2388
} 
#line 2447
template< class T> static __inline ::cudaError_t 
#line 2448
cudaFuncSetAttribute(T *
#line 2449
func, ::cudaFuncAttribute 
#line 2450
attr, int 
#line 2451
value) 
#line 2453
{ 
#line 2454
return ::cudaFuncSetAttribute((const void *)func, attr, value); 
#line 2455
} 
#line 2480
template< class T> static __inline ::cudaError_t __stdcall 
#line 2481
cudaFuncGetName(const char **
#line 2482
name, T *
#line 2483
func) 
#line 2485
{ 
#line 2486
return ::cudaFuncGetName(name, (const void *)func); 
#line 2487
} 
#line 2503
template< class T> static __inline ::cudaError_t 
#line 2504
cudaGetKernel(::cudaKernel_t *
#line 2505
kernelPtr, T *
#line 2506
func) 
#line 2508
{ 
#line 2509
return ::cudaGetKernel(kernelPtr, (const void *)func); 
#line 2510
} 
#line 2541
template< class T> static __inline ::cudaError_t 
#line 2542
cudaLibraryGetGlobal(T **dptr, ::size_t *bytes, ::cudaLibrary_t library, const char *name) 
#line 2543
{ 
#line 2544
return ::cudaLibraryGetGlobal((void **)((void *)dptr), bytes, library, name); 
#line 2545
} 
#line 2575
template< class T> static __inline ::cudaError_t 
#line 2576
cudaLibraryGetManaged(T **dptr, ::size_t *bytes, ::cudaLibrary_t library, const char *name) 
#line 2577
{ 
#line 2578
return ::cudaLibraryGetManaged((void **)((void *)dptr), bytes, library, name); 
#line 2579
} 
#line 2605
template< class T> static __inline ::cudaError_t 
#line 2606
cudaLibraryGetUnifiedFunction(T **fptr, ::cudaLibrary_t library, const char *symbol) 
#line 2607
{ 
#line 2608
return ::cudaLibraryGetUnifiedFunction((void **)((void *)fptr), library, symbol); 
#line 2609
} 
#line 2624 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0/bin/../include\\cuda_runtime.h"
#pragma warning(pop)
#line 492 "CMakeCUDACompilerId.cu"
const char *info_compiler = ("INFO:compiler[NVIDIA]"); 
#line 494
const char *info_simulate = ("INFO:simulate[MSVC]"); 
#line 819 "CMakeCUDACompilerId.cu"
const char info_version[] = {'I', 'N', 'F', 'O', ':', 'c', 'o', 'm', 'p', 'i', 'l', 'e', 'r', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n', '[', (('0') + ((13 / 10000000) % 10)), (('0') + ((13 / 1000000) % 10)), (('0') + ((13 / 100000) % 10)), (('0') + ((13 / 10000) % 10)), (('0') + ((13 / 1000) % 10)), (('0') + ((13 / 100) % 10)), (('0') + ((13 / 10) % 10)), (('0') + (13 % 10)), '.', (('0') + ((0 / 10000000) % 10)), (('0') + ((0 / 1000000) % 10)), (('0') + ((0 / 100000) % 10)), (('0') + ((0 / 10000) % 10)), (('0') + ((0 / 1000) % 10)), (('0') + ((0 / 100) % 10)), (('0') + ((0 / 10) % 10)), (('0') + (0 % 10)), '.', (('0') + ((88 / 10000000) % 10)), (('0') + ((88 / 1000000) % 10)), (('0') + ((88 / 100000) % 10)), (('0') + ((88 / 10000) % 10)), (('0') + ((88 / 1000) % 10)), (('0') + ((88 / 100) % 10)), (('0') + ((88 / 10) % 10)), (('0') + (88 % 10)), ']', '\000'}; 
#line 848 "CMakeCUDACompilerId.cu"
const char info_simulate_version[] = {'I', 'N', 'F', 'O', ':', 's', 'i', 'm', 'u', 'l', 'a', 't', 'e', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n', '[', (('0') + (((1944 / 100) / 10000000) % 10)), (('0') + (((1944 / 100) / 1000000) % 10)), (('0') + (((1944 / 100) / 100000) % 10)), (('0') + (((1944 / 100) / 10000) % 10)), (('0') + (((1944 / 100) / 1000) % 10)), (('0') + (((1944 / 100) / 100) % 10)), (('0') + (((1944 / 100) / 10) % 10)), (('0') + ((1944 / 100) % 10)), '.', (('0') + (((1944 % 100) / 10000000) % 10)), (('0') + (((1944 % 100) / 1000000) % 10)), (('0') + (((1944 % 100) / 100000) % 10)), (('0') + (((1944 % 100) / 10000) % 10)), (('0') + (((1944 % 100) / 1000) % 10)), (('0') + (((1944 % 100) / 100) % 10)), (('0') + (((1944 % 100) / 10) % 10)), (('0') + ((1944 % 100) % 10)), ']', '\000'}; 
#line 868 "CMakeCUDACompilerId.cu"
const char *info_platform = ("INFO:platform[Windows]"); 
#line 869
const char *info_arch = ("INFO:arch[x64]"); 
#line 874
const char *info_host_compiler = ("INFO:host_compiler[MSVC]"); 
#line 879 "CMakeCUDACompilerId.cu"
const char info_host_compiler_version[] = {'I', 'N', 'F', 'O', ':', 'h', 'o', 's', 't', '_', 'c', 'o', 'm', 'p', 'i', 'l', 'e', 'r', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n', '[', (('0') + (((1944 / 100) / 10000000) % 10)), (('0') + (((1944 / 100) / 1000000) % 10)), (('0') + (((1944 / 100) / 100000) % 10)), (('0') + (((1944 / 100) / 10000) % 10)), (('0') + (((1944 / 100) / 1000) % 10)), (('0') + (((1944 / 100) / 100) % 10)), (('0') + (((1944 / 100) / 10) % 10)), (('0') + ((1944 / 100) % 10)), '.', (('0') + (((1944 % 100) / 10000000) % 10)), (('0') + (((1944 % 100) / 1000000) % 10)), (('0') + (((1944 % 100) / 100000) % 10)), (('0') + (((1944 % 100) / 10000) % 10)), (('0') + (((1944 % 100) / 1000) % 10)), (('0') + (((1944 % 100) / 100) % 10)), (('0') + (((1944 % 100) / 10) % 10)), (('0') + ((1944 % 100) % 10)), '.', (('0') + (((194435219 % 100000) / 10000000) % 10)), (('0') + (((194435219 % 100000) / 1000000) % 10)), (('0') + (((194435219 % 100000) / 100000) % 10)), (('0') + (((194435219 % 100000) / 10000) % 10)), (('0') + (((194435219 % 100000) / 1000) % 10)), (('0') + (((194435219 % 100000) / 100) % 10)), (('0') + (((194435219 % 100000) / 10) % 10)), (('0') + ((194435219 % 100000) % 10)), '.', (('0') + ((0 / 10000000) % 10)), (('0') + ((0 / 1000000) % 10)), (('0') + ((0 / 100000) % 10)), (('0') + ((0 / 10000) % 10)), (('0') + ((0 / 1000) % 10)), (('0') + ((0 / 100) % 10)), (('0') + ((0 / 10) % 10)), (('0') + (0 % 10)), ']', '\000'}; 
#line 911 "CMakeCUDACompilerId.cu"
const char *info_language_standard_default = ("INFO:standard_default[14]"); 
#line 929 "CMakeCUDACompilerId.cu"
const char *info_language_extensions_default = ("INFO:extensions_default[OFF]"); 
#line 940 "CMakeCUDACompilerId.cu"
int main(int argc, char *argv[]) 
#line 941
{ 
#line 942
int require = 0; 
#line 943
require += (info_compiler[argc]); 
#line 944
require += (info_platform[argc]); 
#line 946
require += (info_version[argc]); 
#line 949 "CMakeCUDACompilerId.cu"
require += (info_simulate[argc]); 
#line 952 "CMakeCUDACompilerId.cu"
require += (info_simulate_version[argc]); 
#line 955 "CMakeCUDACompilerId.cu"
require += (info_host_compiler[argc]); 
#line 958 "CMakeCUDACompilerId.cu"
require += (info_host_compiler_version[argc]); 
#line 960 "CMakeCUDACompilerId.cu"
require += (info_language_standard_default[argc]); 
#line 961
require += (info_language_extensions_default[argc]); 
#line 962
(void)argv; 
#line 963
return require; 
#line 964
} 
#line 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#define _NV_ANON_NAMESPACE _GLOBAL__N__38d71efd_22_CMakeCUDACompilerId_cu_bd57c623
#ifdef _NV_ANON_NAMESPACE
#endif
#pragma pack()
#line 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#include "CMakeCUDACompilerId.cudafe1.stub.c"
#line 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#undef _NV_ANON_NAMESPACE
