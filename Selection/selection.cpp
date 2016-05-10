/**Copyright [2016] [Lisa Rosenberg]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**/

#include <iostream>
#include "ControlSystemFE_main.hpp"

//like a boss

int main(){
/** Helper Function Prototypes **/
    int getExpression(){ //This is the implementation of this function
        //Do something here to get expression from GUI
    }
    int getMouth() { //This will be the implementation of what the mouth is doing - I think we should have each menu option
        //be correlated to top middle bottom, they can be displayed as 1 2 or 3 in the GUI.  We should have instructions for
        //the selection process pop up.
    }
    typedef struct{
        int happy = 0;
        int disgust = 1;
        int surprise = 2;
    } Expression;

    typedef struct{
        int top = 0;  // mouth signifier - yet to be determined
        int middle = 1; // mouth - yet to be determined
        int bottom = 2; // mouth signifier - yet to be determined
    } Mouth;

    Expression expressionTable;
    Mouth mouthTable;

    int expression;
    int mouth;

    expressionTable.happy; //This is how I would access the variables inside the expressionTable struct

    expression = getExpression();
    mouth = getMouth();
    
cin >> expression // this is the initial input of the expression 
    if(expression = expressionTable.happy){
        //Do something
        std::cout<<"I'm feeling happy about career life.  I'm feeling happy about family life. I'm feeling happy about my personal relationships. "<<std::endl;
        //These will each be output in to the GUI
        //Then based on mouth movements, the user will select options 1 2 or 3 and will continue on to the next menu - we can add in an "is this correct" loop as well to have the user be able to fix errors
        cin >> mouth //I left it with cin because I am not sure how we will be retrieving data from the mouth
        if(mouth = mouthTable.top){ //  Happy - Career Branch
            std::cout<<"You have selected 'I'm feeling happy about career life.' Please choose from the options below: I am happy with my current occupation.  I am happy about my new job.  I am happy about my future career."<<std::endl;
            // **** Insert a delay here before it takes the mouth movement?
            cin >> mouth
            if (mouth = mouthTable.top){
                    std::cout<<"You have selected 'I am happy with my current occupation.'  Please choose from the options below: My career is my main purpose in life.  My career takes up a lot of my time but I love it.  I maintain a balance between my career and my social life which keeps me happy."<<std::endl;
                    // delay??
                cin >> mouth 
                    if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'My career is my main purpose in life.' \nYou are feeling happy about your career life and you are happy with your current occupation as it is your main purpose in life. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'My career takes up a lot of time but I love it.' \nYou are feeling happy about your career life and you are happy with your current occupation. It takes up a lot of your time but you love it. \n Thank you for participating!"<<std::endl;
                    } 
                    else if (mouth = mouthTable.bottom) {
                        std::cout<<"You have selected 'I maintain a balance between my career and my social life which keeps me happy.' \nYou are feeling happy about your career life and you are happy with your current occupation. You are able to maintain a balance between your career and social life which keeps you happy. \n Thank you for participating!"<<std::endl;
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
              }
              
            else if (mouth = mouthTable.middle) {
                    std::cout<<"You have selected 'I am happy about my new job.' Please choose from the options below: I work close to home. I work with my friends. I work in a good environment. " <<std::endl;
            //delay???
                cin >> mouth
                    if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'I work close to home.' \nYou are feeling happy about your career life and you are happy about your new job as you now work close to home. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'I work with my friends.' \nYou are feeling happy about your career life and you are happy about your new job as you work with your friends. \n Thank you for participating!"<<std::endl;
                    } 
                    else if (mouth = mouthTable.bottom) {
                        std::cout<<"You have selected 'I work in a good environment.' \nYou are feeling happy about your career life and and you are happy about your new job as you work in a good environment. \n Thank you for participating!"<<std::endl;
                    }
                    else {
            std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                    }   
            } 
            else if (mouth = mouthTable.bottom) {
                 std::cout<<"You have selected 'I am happy about my future career.' Please choose from the options below: I have an interview coming up. I feel like I am on the right track. I took the right path in my education. " <<std::endl;
            //delay???
                cin >> mouth
                    if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'I have an interview coming up.' \nYou are feeling happy about your career life and you are happy about your future career as you have an interview coming up. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'I feel like I am on the right track.' \nYou are feeling happy about your career life and you are happy about your future career as you feel like you are on the track \n Thank you for participating!"<<std::endl;
                    } 
                    else if (mouth = mouthTable.bottom) {
                        std::cout<<"You have selected 'I took the right path in my education.' \nYou are feeling happy about your career life and you are happy about your future career due to taking the right path in your education. \n Thank you for participating!"<<std::endl;
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
                    } 
            else {
                std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                    }        
            }
        elseif(mouth = mouthTable.middle){
            std::cout<<"You have selected 'I'm feeling happy about family life.' Please choose from the options below: I am seeing my parent(s) and/or sibling(s) soon.  I am seeing my extended family soon.  I am speaking to a family member on the phone later."<<std::endl;
             // delay?
            cin >> mouth
            if (mouth = mouthTable.top){
                    std::cout<<"You have selected 'I am seeing my parent(s) and/or sibling(s) soon.'  Please choose from the options below: I will be going to their house. They will be coming over.  We will be going out to dinner."<<std::endl;
                    // delay??
                    cin >> mouth 
                    if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'I will be going to their house.' \nYou are feeling happy about your family life and you are seeing your parent(s) and/or sibling(s) soon and you will be going over to their house. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'My family will be coming over.' \nYou are feeling happy about your family life and you are seeing your parent(s) and/or sibling(s) soon and they will be coming over to your place. \n Thank you for participating!"<<std::endl;
                    }
                    else if (mouth = mouthTable.bottom) {
                        std::cout<<"You have selected 'I will be going out to dinner with my my family.' \nYou are feeling happy about your family life and you are seeing your parent(s) and/or sibling(s) soon and you will be going out to dinner soon together. \n Thank you for participating!"<<std::endl;
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
              
            }
              
            else if (mouth = mouthTable.middle) {
                    std::cout<<"You have selected 'I am seeing my extended family soon.' Please choose from the options below: I will be going to their house. They will be coming over.  We will be going out to dinner."<<std::endl;
            //delay???
                cin >> mouth
                       if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'I will be going to their house.' \nYou are feeling happy about your family life and you are seeing your extended family soon and you will be going over to their house. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'My family will be coming over.' \nYou are feeling happy about your family life and you are seeing your extended family soon and they will be coming over to your place. \n Thank you for participating!"<<std::endl;
                    }
                    else if (mouth = mouthTable.bottom) {
                        std::cout<<"You have selected 'I will be going out to dinner with my my family.' \nYou are feeling happy about your family life and you are seeing your extended family soon and you will be going out to dinner soon together. \n Thank you for participating!"<<std::endl;
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
            } 
            else if (mouth = mouthTable.bottom) {
                 std::cout<<"You have selected 'I am speaking to a family member on the phone later.' Please choose from the options below: I have good news for my family.  My family has good news to tell me.  I call my family often to stay in touch. " <<std::endl;
            //delay???
                cin >> mouth
                    if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'I have good news for my family.' \nYou are feeling happy about your family life and you are speaking to a family member on the phone later and you have good news to tell them. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'I have good news for my family.' \nYou are feeling happy about your family life and you are speaking to a family member on the phone later and they have good news to tell you. \n Thank you for participating!"<<std::endl;
                    } 
                    else if (mouth = mouthTable.bottom) {
                       std::cout<<"You have selected 'I have good news for my family.' \nYou are feeling happy about your family life and you are speaking to a family member on the phone later and you call them often to stay in touch. \n Thank you for participating!"<<std::endl;
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
                    } 
            else {
                std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                    }        
            }
                    
            
        else if(mouth = mouthTable.bottom){
                std::cout<<"You have selected 'I'm feeling happy about my personal relationships.' Please choose from the options below: I am happy with my significant other.  I am going on a date soon and I am looking forward to it.  I am single and enjoying it."<<std::endl;
              // delay?
            cin >> mouth
            if (mouth = mouthTable.top){
                    std::cout<<"You have selected 'I am happy with my significant other.'  Please choose from the options below: I will be going to their house soon. We're married.  We will be going out to dinner soon."<<std::endl;
                    // delay??
                    cin >> mouth 
                    if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'I will be going to their house soon.' \nYou are feeling happy about your personal relationships because you are happy with your significant other and you will be going over to their house soon. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'We're married.' \nYou are feeling happy about your personal relationships because you are happy with your significant other and you are married. \n Thank you for participating!"<<std::endl
                    }
                    else if (mouth = mouthTable.bottom) {
                         std::cout<<"You have selected 'I will be going out to dinner soon.' \nYou are feeling happy about your personal relationships because you are happy with your significant other and you will be going out to dinner soon. \n Thank you for participating!"<<std::endl
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
              }
              
            else if (mouth = mouthTable.middle) {
                    std::cout<<"You have selected 'I am going on a date soon and I am looking forward to it.' Please choose from the options below: It is a first date.  It is a blind date.  It is someone I have been dating for some time."<<std::endl;
            //delay???
                cin >> mouth
                       if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'It is a first date.' \nYou are feeling happy about your personal relationships and you are going on a date soon.  It will be the first date. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'It is a blind date.' \nYou are feeling happy about your personal relationships and you are going on a date soon.  It will be a blind date. \n Thank you for participating!"<<std::endl;
                    }
                    else if (mouth = mouthTable.bottom) {
                        std::cout<<"You have selected 'It is someone I have been dating for some time.' \nYou are feeling happy about your personal relationships and you are with someone you have been dating with for some time. \n Thank you for participating!"<<std::endl;
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
            } 
            else if (mouth = mouthTable.bottom) {
                 std::cout<<"You have selected 'I am single and enjoying it.' Please choose from the options below: I recently got out of a relationship.  I am still waiting for the right person. I do not want to be in a relationship. " <<std::endl;
            //delay???
                cin >> mouth
                    if (mouth = mouthTable.top) {
                       std::cout<<"You have selected 'I recently got out of a relationship.' \nYou are feeling happy about your personal relationships and you are currently single and enjoying it because you recently got out of a relationship. \n Thank you for participating!"<<std::endl;
                     }
                    else if (mouth = mouthTable.middle) {
                        std::cout<<"You have selected 'I have good news for my family.' \nYou are feeling happy about your personal relationships and you are currently single and enjoying it because you are still waiting for the right person. \n Thank you for participating!"<<std::endl;
                    } 
                    else if (mouth = mouthTable.bottom) {
                       std::cout<<"You have selected 'I have good news for my family.' \nYou are feeling happy about your personal relationships and you are currently single and enjoying it because do not want to be in a relationship. \n Thank you for participating!"<<std::endl;
                    }
                    else {
                        std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                        }
                    } 
            else {
                std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
                    }        
            }

    
        else {
            std::cout<<"Please make an indication with your mouth as to what thought is most appropriate."<<std::endl;
        }
            
            
    }
    

    else if(expression = expressionTable.disgust){

    }
    else if(expression = expressionTable.surprise){

    }


    else {
    std::cout<<"How are you feeling today?"<<std::endl; 
        }
            

return 0;
}

