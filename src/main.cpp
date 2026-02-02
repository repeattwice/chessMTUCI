#include "Autorization.h"

using namespace System;
using namespace::System::Windows::Forms;

[STAThread]
int main (array<String^>^ args){
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    chessMTUCI::Autorization^ form = gcnew chessMTUCI::Autorization();
    Application::Run(form);
    

    return 0;
}