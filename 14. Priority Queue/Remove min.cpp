/*

Code : Remove Min

Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum 
element present. 
Remove and return the minimum element.
Note : main function is given for your reference which we are using internally 
to test the code.

*/

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {

        if (isEmpty()) {
          return 0;
        }
        
        int min = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;

        while (parentIndex < pq.size()) 
        {
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        int minIndex;

        if (leftChildIndex < pq.size() && rightChildIndex < pq.size()) 
        {
            if (pq[leftChildIndex] <= pq[rightChildIndex]) 
            {
              minIndex = leftChildIndex;
            } 
            else
            {
              minIndex = rightChildIndex;
            }
        } 
        else if (leftChildIndex < pq.size()) 
        {
            minIndex = leftChildIndex;
        } 
        else 
        {
            break;
        }

        if (pq[minIndex] < pq[parentIndex]) 
        {
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
        }
        else 
        {
            break;
        }

          parentIndex = minIndex;
        }
        return min;
    }
};