#include <iostream>
#include <unistd.h>
#include "../src/Process.h"

int main() {
    Process p = Process(getpid());
    p.sendSignal(15); // Send a TERM signal

    std::cout << "Process exiting naturally" << std::endl;
    return 0;
}
