#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class WalkableRobot{
    public:
        virtual void walk()=0; // pure virtual function
        virtual ~WalkableRobot(){} // virtual destructor
};

class NormalWalk : public WalkableRobot{
    public:
        void walk() override{
            cout << "Walking normally..." << endl;
        }
};

class NoWalk : public WalkableRobot{
    public:
        void walk() override{
            cout << "I cannot walk!" << endl;
        }
};

class TalkableRobot{
    public:
        virtual void talk()=0; // pure virtual function
        virtual ~TalkableRobot(){} // virtual destructor
};

class NormalTalk : public TalkableRobot{
    public:
        void talk() override{
            cout << "Talking normally..." << endl;
        }
};

class NoTalk : public TalkableRobot{
    public:
        void talk() override{
            cout << "I cannot talk!" << endl;
        }
};

class FlyableRobot{
    public:
        virtual void fly()=0; // pure virtual function
        virtual ~FlyableRobot(){} // virtual destructor
};

class NormalFly : public FlyableRobot{
    public:
        void fly() override{
            cout << "Flying normally..." << endl;
        }
};  

class NoFly : public FlyableRobot{
    public:
        void fly() override{
            cout << "I cannot fly!" << endl;
        }
};

class Robot{
    protected:
        WalkableRobot* walkBehavior;
        TalkableRobot* talkBehavior;
        FlyableRobot* flyBehavior;
    public:
        Robot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly){
            this->walkBehavior=walk;
            this->talkBehavior=talk;
            this->flyBehavior=fly;
        }
        void performWalk(){
            walkBehavior->walk();
        }
        void performTalk(){
            talkBehavior->talk();
        }
        void performFly(){
            flyBehavior->fly();
        }
        virtual void projection()=0; // pure virtual function
};

class WorkerRobot : public Robot{
    public:
        WorkerRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly) : Robot(walk, talk, fly){}
        void projection() override{
            cout << "Displaying worker efficiency stats..." << endl;
        }
};

class CompanionRobot : public Robot{
    public:
        CompanionRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly) : Robot(walk, talk, fly){}
        void projection() override{
            cout << "Displaying companion's mood and health stats..." << endl;
        }
};

int main(){
    Robot* robot1=new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->performWalk();
    robot1->performTalk();
    robot1->performFly();
    robot1->projection();
    cout << "-----------------------------" << endl;
    Robot* robot2=new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->performWalk();
    robot2->performTalk();
    robot2->performFly();
    robot2->projection();
    return 0;
}