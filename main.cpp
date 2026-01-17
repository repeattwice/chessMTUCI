#include "GUI.h"

using namespace::System;
using namespace::System::Windows::Forms;
using namespace chessMTUCI;


int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew GUI());
    

    return 0;
}