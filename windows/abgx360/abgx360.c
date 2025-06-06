#if defined(__APPLE__)
/* macOS doesn't provide off64_t or the 64-bit seek helpers. Map them
 * to the regular 64-bit aware versions so the code can always use the
 * same names. */
#ifndef off64_t
typedef off_t off64_t;
#endif
#ifndef fseeko64
#define fseeko64 fseeko
#endif
#ifndef ftello64
#define ftello64 ftello
#endif
#endif
=======
typedef off_t off64_t;
#define fseeko64 fseeko
#define ftello64 ftello
#endif
sprintf(topbinfilename, "%.*s.bin", (int)(strlen(topologytxtbuffer) - 11), topologytxtbuffer+5);
