#define HAVE_BYTESWAP_H 1
#define HAVE_CRYPTO_MD5 1
#define HAVE_CRYPTO_SHA256 1
#define HAVE_OPENIPMI_H 1
#define HAVE_PATHS_H 1
#define HAVE_PRAGMA_PACK 1
#define HAVE_READLINE 1
#define HAVE_TERMIOS_H 1

#define PATH_SEPARATOR "/"

#if __BYTE_ORDER == __BIG_ENDIAN
#define WORDS_BIGENDIAN 1
#endif

#define ENABLE_ALL_OPTIONS 1

#define IANADIR "/lib/ipmitool"
#define IANAUSERDIR ".local/lib/ipmitool"

#define DEFAULT_INTF "open"
#define IPMI_INTF_LAN 1
#define IPMI_INTF_LANPLUS 1
#define IPMI_INTF_OPEN 1
