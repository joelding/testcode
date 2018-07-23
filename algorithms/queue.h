#ifndef _QUEUE_H_
#define  _QUEUE_H_

/* USE_ARRAY: use array in the form of circular buffer
 */
#define USE_ARRAY	1

#ifdef __cplusplus
extern "C" 
{
#endif

#define BUFFER_SIZE	8

#if USE_ARRAY
	typedef struct {
		unsigned int head;
		unsigned int tail;
		int buf[BUFFER_SIZE];
	} que_t;

	void que_init(que_t *thiz);
	void que_dump(que_t *thiz);
#endif /* USE_ARRAY */

#ifdef __cplusplus
}
#endif

#endif /* _QUEUE_H_ */

