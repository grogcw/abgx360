#if defined(__APPLE__)
typedef off_t off64_t;
#define fseeko64 fseeko
#define ftello64 ftello
#endif
        sprintf(topbinfilename, "%.*s.bin", (int)(strlen(topologytxtbuffer) - 11), topologytxtbuffer+5);
