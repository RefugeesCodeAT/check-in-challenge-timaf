#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

typedef struct PARTICIPANT
{
    string name;
    bool checked_in;
    struct PARTICIPANT* next;
}
PARTICIPANT;

PARTICIPANT* participants = NULL;

#define CHECKED_IN true
#define CHECKED_OUT false

string get_user_input();
bool perform(string user_input);

// TODO: Functions to implement
void add_one(string participant_name);
void remove_one(string participant_name);
void check_one(string participant_name);
void display_participants();
void free_memory();

int main(void)
{
    bool working = true;

    while(working)
    {
        string user_input = get_user_input();
        working = perform(user_input);
    }

    free_memory();
}

string get_user_input()
{
    return get_string("Command: ");
}

// Performs the action from the "user_input"
bool perform(string user_input)
{
    // Read the string of user input into two variables
    string action_name = strtok(user_input, " ");
     string participant_name = strtok(NULL, " ");
     if(action_name == NULL)
     return false;

    if(strcmp(action_name, "add") == 0 )
    {
        add_one(participant_name);
        return true;
    }
    if(strcmp(action_name, "remove") == 0)
    {
        remove_one(participant_name);
        return true;
    }
    if(strcmp(action_name, "check") == 0)
    {
        check_one(participant_name);
        return true;
    }
    if(strcmp(action_name, "display") == 0 )
    {
       display_participants();
       return true;
    }
    if(strcmp(action_name, "exit") == 0)
    {
        return false;
    }

    return true;
}

/*
    Adds a participant to the beginning of the list
*/
void add_one(string participant_name)
{
    printf("add %s\n", participant_name);

    PARTICIPANT* newParticipant = malloc(sizeof( PARTICIPANT));

     newParticipant->name = participant_name;
     newParticipant->checked_in = CHECKED_IN;
     newParticipant->next = NULL;
     if(participants)
       {

            newParticipant->next = participants;

             participants =newParticipant;
       }
         else
        {
            participants = newParticipant;
        }
}

/*
    Search for a participant in the list and if it exists, remove it.
*/
void remove_one(string participant_name)
{
    printf("remove %s\n", participant_name);



     PARTICIPANT *temParticipant = participants;
      PARTICIPANT *prevParticipant =participants;
   while (temParticipant != NULL)
   {

       if (strcmp (temParticipant->name,participant_name) == 0)
          {
              if(prevParticipant == temParticipant)
              {
                participants = temParticipant->next;
                 free(temParticipant);
                 break;
              }
              else
              {
                prevParticipant->next =temParticipant->next;
                free(temParticipant);
               break;
              }
          }
    prevParticipant = temParticipant;
   temParticipant = temParticipant->next;

    }

}

/*
    Check a participant from the list in or out
*/
void check_one(string participant_name)
{
    printf("check %s\n", participant_name);

    for (PARTICIPANT *temParticipant = participants; temParticipant != NULL; temParticipant = temParticipant->next)
        {

                    if (strcmp (temParticipant->name,participant_name) == 0)
                    {
                    temParticipant->checked_in = !(temParticipant->checked_in);
                     printf(" status%i\n", temParticipant->checked_in);
                    }
        }
}

/*
    Display all participants and their status.
*/
void display_participants()
{
    printf("display\n");

    for ( PARTICIPANT *temParticipant = participants; temParticipant != NULL; temParticipant = temParticipant->next)
    {
        printf("%s\n", temParticipant-> name);
         printf(" status%i\n", temParticipant->checked_in);
    }

}

/*
    Free all memory used by participants in the list
*/
void free_memory()
{
    printf("freeing stuff.\n");

   PARTICIPANT *temParticipant = participants;
   while (temParticipant != NULL)
   {
    PARTICIPANT *theNextParticipant =temParticipant->next;
    free(temParticipant);
   temParticipant = theNextParticipant;

   }
}








