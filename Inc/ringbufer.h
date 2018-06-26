#ifndef _RINGBUFER_H_
#define _RINGBUFER_H_

#include <stdint.h>

#define SER_RING_BUF_SIZE 512
#define SER_RING_BUF_RESET(serRingBuf)					(serRingBuf.rdIdx = serRingBuf.wrIdx = 0)
#define SER_RING_BUF_WR(serRingBuf, dataIn)			(serRingBuf.data[(SER_RING_BUF_SIZE - 1) & serRingBuf.wrIdx++] = (dataIn))
#define SER_RING_BUF_RD(serRingBuf)							(serRingBuf.data[(SER_RING_BUF_SIZE - 1) & serRingBuf.rdIdx++])
#define SER_RING_BUF_EMPTY(serRingBuf)					(serRingBuf.rdIdx == serRingBuf.wrIdx)
#define SER_RING_BUF_FULL(serRingBuf)						(serRingBuf.wrIdx == ((serRingBuf.rdIdx + SER_RING_BUF_SIZE) & 0x0FFFF))
#define SER_RING_BUF_RQ_WR(serRingBuf, dataIn)	(serRingBuf.data[(RING_BUF_SIZE - 1) & serRingBuf.wrIdx] = (dataIn))


typedef struct 
{
	uint8_t data[SER_RING_BUF_SIZE];
	uint16_t wrIdx;
	uint16_t rdIdx;
} SER_RING_BUF_T;






#endif
