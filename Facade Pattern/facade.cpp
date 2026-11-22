#include<iostream>
using namespace std;

class PowerSupply {
    public:
        void providePower(){
            cout<<"Power supply : providing power "<<endl;
        }
};

class CoolingSystem{
    public:
        void startFans(){
            cout<<"Cooling System : fans started..."<<endl;
        }
};

class CPU {
    public:
        void initialize(){
            cout<<"CPU : initialization started..."<<endl;
        }
};

class Memory {
    public:
        void selfTest(){
            cout<<"Memory : self-test Passed..."<<endl;
        }
};

class HardDrive {
    public:
        void spinUp(){
            cout<<"Hard Drive : Spinning up..."<<endl;
        }
};

class Bios {
    public:
        void boot(CPU& cpu , Memory& memory){
            cout<< "BIOS : Booting CPU & Memory check.."<<endl;
            cpu.initialize();
            memory.selfTest();
        }
};

class OperatingSystem {
    public:
        void load(){
            cout<<"Operating System : Loading into memory..."<<endl;
        }
};

class ComputerFacade {
    private:
        PowerSupply power;
        CoolingSystem cool;
        CPU cpu;
        Memory memory;
        HardDrive drive;
        Bios bios;
        OperatingSystem os;

    public:
        void startComputer(){
            cout<<"Start Computer :::::::" << endl;
            power.providePower();
            cool.startFans();
            bios.boot(cpu,memory);
            drive.spinUp();
            os.load();
            cout<<endl<<"Computer booted Successfully..."<<endl;
        }
};

int main(){
    ComputerFacade comp;
    comp.startComputer();

    return 0;
}