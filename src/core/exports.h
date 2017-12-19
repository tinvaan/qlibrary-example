#ifdef Q_OS_WIN
#define COMPUTE_EXPORT __declspec(dllexport)
#else
#define COMPUTE_EXPORT
#endif
