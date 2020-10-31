typedef struct q{
    struct q *next;
    int data;
} qItem;

typedef struct {
    int numItems;
    qItem *head;
    qItem *tail;
} q;


void queueInit(q *queue);
void q_free(q *queue);
void q_enqueue(q *queue, int item);
int q_dequeue(q *queue);
void q_print(q *queue);