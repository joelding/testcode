#ifndef _STACK_H_
#define  _STACK_H_

/* USE_ARRAY: use array in the form of circular buffer
 */
#define USE_ARRAY	1

#ifdef __cplusplus
extern "C" 
{
#endif

#define BUFFER_SIZE	8
#define DATA_T	int

#if USE_ARRAY
	typedef struct {
		int top;
		DATA_T buf[BUFFER_SIZE];
	} stack_t;

	void stack_init(stack_t *thiz);
	void stack_dump(stack_t *thiz);
	void stack_push(stack_t *thiz, DATA_T); 
	void stack_pop(stack_t *thiz, DATA_T*); 
#endif /* USE_ARRAY */

#ifdef __cplusplus
}
#endif

#endif /* _STACK_H_ */

