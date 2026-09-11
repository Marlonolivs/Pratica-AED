int maxSubArray(int* nums, int numsSize) {
    
    int max_soma = nums[0];
    int guarda_soma = nums[0];

    for(int i = 1; i < numsSize;i++){

        if(guarda_soma < 0){

            guarda_soma = nums[i];
        }else{

            guarda_soma += nums[i];
        }

        if(guarda_soma > max_soma){

            max_soma = guarda_soma;
        }
    }

    return max_soma;
}