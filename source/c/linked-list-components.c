/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int numComponents(struct ListNode* head, int* nums, int numsSize){
    
    //sort the array
    int arr[numsSize];
    int i, j;
    int consecutive_pair=0, count_ll=0;
    for(i=0; i<numsSize; i++){
        arr[i]=*(nums+i);
    }
    
    //sorting
    for(i=0; i<numsSize-1; i++){
        for(j=0; j<numsSize-i-1; j++){
            if(arr[j+1]<arr[j]){
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    //check consecutive
    struct ListNode *ptr = head;
    while(ptr){
        count_ll++;
        ptr = ptr->next;
    }
    
    //store sequence array
    int seq[count_ll+1];  
    for(i=0; i<count_ll; i++){
        seq[i]=0;
    }
    
    for(i=0; i<numsSize; i++){
        ptr = head;
        for(j=0; j<count_ll; j++){
            if(arr[i] == ptr->val) 
                seq[j]=1;
            ptr=ptr->next;
        }
    }
    
    //count consecutive 1's
    int flag=0;
    for(i=0; i<count_ll; i++){
        if(seq[i]==1){
            if(flag==1) 
                continue;
            consecutive_pair++;
            flag=1;
        }   
        else
            flag=0;
    }
    
    return consecutive_pair;
}