#ifndef _SCE_BGFT_H_
#define _SCE_BGFT_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceBgftServiceDownloadQueryTask();
// Empty Comment
void sceBgftServiceDownloadStopTask();
// Empty Comment
int sceBgftInitialize(void* parameters);
// Empty Comment
int sceBgftFinalize();

#endif

#ifdef __cplusplus
}
#endif