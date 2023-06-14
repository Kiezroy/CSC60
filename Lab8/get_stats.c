/*-------------------------------------------------------------------*/
/* Kyle Nguyen                                                         */ 
/* Ruthann Biel                                                      */
/* get_stats_me is a function to do figure the best throw for each   */
/* thrower, compute the all-over average of the best throws, and     */
/* find the longest throw  on the track and each thrower's deviation */
/* from the winning throw                                            */

#include "lab8.h"

void get_stats(thrower_t throw_list[NCOMPETITORS], /* in & out */
               stats_t *throw_stats)      	   /* output   */
{ 
  throw_stats->average_of_best_throws = 0; //struct points to member of stats_t which is avgofbest and sets to zero
  throw_stats->winning_throw = 0;

  //For loop that goes through all the competitors
  int r;
  for(r = 0; r < NCOMPETITORS; r++){
     
      throw_list[r].best_throw = throw_list[r].tries[0]; //Sets best throw to 1st throw

      //For loop that goes throw all the tries of that specific player
      int c;
      for(c = 1; c < N_TRIES; c++){
            //If statement compares if that try was better than their best throw(which was set to the first throw of index starting 0)
            if(throw_list[r].tries[c] > throw_list[r].best_throw){
                //If that throw is larger, it becomes the new best throw
                throw_list[r].best_throw = throw_list[r].tries[c];  
              } 
      }

      //access avgofbest throw pointer throw_stats to the struct of stats_t
      throw_stats->average_of_best_throws += throw_list[r].best_throw;

      if(throw_list[r].best_throw > throw_stats->winning_throw){
            //If best throw greater than winning throw, swap
            throw_stats->winning_throw = throw_list[r].best_throw;    
      }

      throw_stats->average_of_best_throws /= NCOMPETITORS; //computes the average
      
      //Calculate deviation
      int r;
      for(r = 0; r < NCOMPETITORS; r++){
        throw_list[r].deviation = throw_stats->winning_throw - throw_list[r].best_throw;    
      }
  }
}

/*--------------------------------------------------------*/
