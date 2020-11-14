int main()
{
    int a =  1;
    int b = 3;

    const int *pA = &a;
    //*pA = 2; // does not compile, pA is pointer to constant integer. Pointer may be modified, integer it points to cannot.
    pA = &b; // ok, since the pointer is not const

    int * const pA2 = &a; 
    *pA2 = 2; // ok, since pA2 is a constant pointer to an integer. Pointer cannot be modified, but integer it points to can.
    // pA2 = &b; // does not compile as the pointer is constant.
    
    const int *const pA3 = &a;
    // pA3 = &b; // does not compile, pointer is read only
    // *pA3 = 4; // does not compile, pointer points to constant value
}