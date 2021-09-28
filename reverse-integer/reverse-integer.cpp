class Solution {
public:
    int reverse(int x) {
      long y = (long) x;
        int temp;
        long sum = 0;
        bool flag = true;
        if(y<0){
         flag = false ;
          y =(y*-1);  
        }
        
        while(y>0){
            temp = y%10;
            y=y/10;
            sum = sum*10+temp;
            
           
        }
        
         if(sum <=INT_MAX and sum >=INT_MIN){
              if(flag == false) 
              return sum =(sum*-1);
              
             else return sum;
         }
        
          
            
            return 0;
   
 
        
    }
};