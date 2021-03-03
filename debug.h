#ifndef DEBUGH
#define DEBUGH


#define DEBUGON

#ifdef DEBUGON
#define DEBUG(msg) printf("DEBUG: %s\n", msg)
#else
#define DEBUG(msg)
#endif // DEBUGON

#endif // DEBUGH