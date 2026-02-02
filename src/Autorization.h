#pragma once
#include "GUI.h"
#include "RegForm.h"

namespace chessMTUCI {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Text;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class Autorization : public System::Windows::Forms::Form
	{
	public:
		Autorization(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Autorization()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ UsName;
	private: System::Windows::Forms::Label^ Pswrd;
	private: System::Windows::Forms::Label^ Autrization;
	private: System::Windows::Forms::TextBox^ EnterUsName;
	private: System::Windows::Forms::TextBox^ EnterPasword;
	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::Button^ registration;


	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->UsName = (gcnew System::Windows::Forms::Label());
			this->Pswrd = (gcnew System::Windows::Forms::Label());
			this->Autrization = (gcnew System::Windows::Forms::Label());
			this->EnterUsName = (gcnew System::Windows::Forms::TextBox());
			this->EnterPasword = (gcnew System::Windows::Forms::TextBox());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->registration = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// UsName
			// 
			this->UsName->AutoSize = true;
			this->UsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UsName->Location = System::Drawing::Point(12, 83);
			this->UsName->Name = L"UsName";
			this->UsName->Size = System::Drawing::Size(100, 24);
			this->UsName->TabIndex = 0;
			this->UsName->Text = L"UserName";
			// 
			// Pswrd
			// 
			this->Pswrd->AutoSize = true;
			this->Pswrd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Pswrd->Location = System::Drawing::Point(12, 121);
			this->Pswrd->Name = L"Pswrd";
			this->Pswrd->Size = System::Drawing::Size(83, 24);
			this->Pswrd->TabIndex = 1;
			this->Pswrd->Text = L"Pasword";
			// 
			// Autrization
			// 
			this->Autrization->AutoSize = true;
			this->Autrization->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Autrization->Location = System::Drawing::Point(214, 9);
			this->Autrization->Name = L"Autrization";
			this->Autrization->Size = System::Drawing::Size(129, 24);
			this->Autrization->TabIndex = 2;
			this->Autrization->Text = L"Авторизация";
			this->Autrization->Click += gcnew System::EventHandler(this, &Autorization::Autrization_Click);
			// 
			// EnterUsName
			// 
			this->EnterUsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterUsName->Location = System::Drawing::Point(140, 86);
			this->EnterUsName->Name = L"EnterUsName";
			this->EnterUsName->Size = System::Drawing::Size(327, 22);
			this->EnterUsName->TabIndex = 3;
			this->EnterUsName->TextChanged += gcnew System::EventHandler(this, &Autorization::EnterUsName_TextChanged);
			// 
			// EnterPasword
			// 
			this->EnterPasword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterPasword->Location = System::Drawing::Point(140, 125);
			this->EnterPasword->Name = L"EnterPasword";
			this->EnterPasword->Size = System::Drawing::Size(327, 22);
			this->EnterPasword->TabIndex = 4;
			this->EnterPasword->TextChanged += gcnew System::EventHandler(this, &Autorization::EnterPasword_TextChanged);
			// 
			// Enter
			// 
			this->Enter->BackColor = System::Drawing::Color::Plum;
			this->Enter->Location = System::Drawing::Point(384, 199);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(156, 79);
			this->Enter->TabIndex = 5;
			this->Enter->Text = L"Войти";
			this->Enter->UseVisualStyleBackColor = false;
			this->Enter->Click += gcnew System::EventHandler(this, &Autorization::Enter_Click);
			// 
			// registration
			// 
			this->registration->BackColor = System::Drawing::Color::SlateBlue;
			this->registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->registration->Location = System::Drawing::Point(16, 242);
			this->registration->Name = L"registration";
			this->registration->Size = System::Drawing::Size(111, 29);
			this->registration->TabIndex = 6;
			this->registration->Text = L"Регистрация";
			this->registration->UseVisualStyleBackColor = false;
			this->registration->Click += gcnew System::EventHandler(this, &Autorization::registration_Click);
			// 
			// Autorization
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Thistle;
			this->ClientSize = System::Drawing::Size(552, 290);
			this->Controls->Add(this->registration);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->EnterPasword);
			this->Controls->Add(this->EnterUsName);
			this->Controls->Add(this->Autrization);
			this->Controls->Add(this->Pswrd);
			this->Controls->Add(this->UsName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Autorization";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Autrization_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: String^ SendHTTPRequest(String^ url, String^ method, String^ jsonData) {
	try {
		Uri^ uri = gcnew Uri(url);

		HttpWebRequest^ request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(uri));
		request->Method = method;
		request->ContentType = "application/json";
		request->Timeout = 5000;
		request->UserAgent = "ChessClient/1.0";

		if (method->ToUpper() == "POST" && jsonData->Length > 0) {
			array<Byte>^ data = Encoding::UTF8->GetBytes(jsonData);
			request->ContentLength = data->Length;

			Stream^ stream = request->GetRequestStream();
			stream->Write(data, 0, data->Length);
			stream->Close();
		}
		HttpWebResponse^ response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
		StreamReader^ reader = gcnew StreamReader(response->GetResponseStream(), Encoding::UTF8);
		String^ result = reader->ReadToEnd();

		reader->Close();
		response->Close();
		return result;
	}
	catch (WebException^ ex) {
		if (ex->Response != nullptr) {
			HttpWebResponse^ errorResponse = dynamic_cast<HttpWebResponse^>(ex->Response);
			StreamReader^ reader = gcnew StreamReader(errorResponse->GetResponseStream(), Encoding::UTF8);
			String^ errorText = reader->ReadToEnd();
			reader->Close();
			return "{\"success\":false,\"message\":\"HTTP Error: " + errorResponse->StatusCode.ToString() + "\",\"error\":\"" + errorText->Replace("\"", "\\\"") + "\"}";
		}
	}
	catch (Exception^ ex) {
		return "{\"success\":false,\"message\":\"Error: " + ex->Message->Replace("\"", "\\\"") + "\"}";
	}
}
	   bool parseLoginResp(String^ jsonResponse, [Runtime::InteropServices::Out] String^% message) {
		   try {
			   String^ cleanJson = jsonResponse->Replace(" ", "")->Replace("\n", "")->Replace("\r", "")->Replace("\t", "");
			   if (!cleanJson->Contains("\"success\":")) {
				   message = "Invalid server response";
				   return false;
			   }
			   int successIndex = cleanJson->IndexOf("\"success\":");
			   int valueStart = successIndex + 10;
			   String^ successValue = "";

			   for (int i = valueStart; i < cleanJson->Length && i < valueStart + 5; i++) {
				   if (cleanJson[i] == ',' || cleanJson[i] == '}') {
					   break;
				   }
				   successValue += cleanJson[i];
			   }
			   bool isSuccess = successValue->StartsWith("true");
			   int messageIndex = cleanJson->IndexOf("\"message\":\"");
			   if (messageIndex != -1) {
				   int msgStart = messageIndex + 11;
				   int msgEnd = cleanJson->IndexOf("\"", msgStart);

				   if (msgEnd > msgStart) {
					   message = cleanJson->Substring(msgStart, msgEnd - msgStart);
				   }
				   else {
					   message = isSuccess ? "Login successful" : "Login failed";
				   }
			   }
			   else {
				   message = isSuccess ? "Login successful" : "Login failed";
			   }
			   return isSuccess;
		   }
		   catch (Exception^ ex) {
			   message = "Parse error: " + ex->Message;
			   return false;
		   }
	   }





private: System::Void Enter_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ username = EnterUsName->Text->Trim();
	String^ password = EnterPasword->Text;

	if (String::IsNullOrEmpty(username)) {
		MessageBox::Show("Вввдите username", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		EnterUsName->Focus();
		return;
	}
	if (String::IsNullOrEmpty(password)) {
		MessageBox::Show("Вввдите password", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		EnterPasword->Focus();
		return;
	}
	this->Cursor = Cursors::WaitCursor;
	Enter->Enabled = false;
	registration->Enabled = false;

	try {
		String^ jsonData = "{\"username\":\"" + username + "\",\"password\":\"" + password + "\"}";
		String^ ServerUrl = "http://localhost:8000/api/login";
		String^ response = SendHTTPRequest(ServerUrl, "POST", jsonData);
		String^ message;
		bool success = parseLoginResp(response, message);
		if (success) {
			MessageBox::Show(message + "\n\nДобро пожаловать, " + username + "!", "Успешный вход", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Hide();
			GUI^ mainform = gcnew GUI();
			mainform->Show();
		}
		else {
			if (message->Contains("not found") || message->Contains("User not found"))
			{
				MessageBox::Show("Пользователь не найден\n\nПроверьте имя пользователя или зарегистрируйтесь", "Ошибка входа", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else if (message->Contains("password") || message->Contains("Invalid password"))
			{
				MessageBox::Show("Неверный пароль\n\nПопробуйте еще раз", "Ошибка входа", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				EnterPasword->Clear();
				EnterPasword->Focus();
			}
			else
			{
				MessageBox::Show(message, "Ошибка входа", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	catch (UriFormatException^ ex) {
		MessageBox::Show("❌ Неправильный адрес сервера\n\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (WebException^ ex) {
		MessageBox::Show("Сервер недоступен\n\nУбедитесь что сервер запущен : \n1.Откройте командную строку\n2.Перейдите в папку с сервером\n3.Выполните: python server.py", "Ошибка сети", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		this->Cursor = Cursors::Default;
		Enter->Enabled = true;
		registration->Enabled = true;
	}
}
private: System::Void EnterUsName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EnterPasword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void registration_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	RegForm^ choose = gcnew RegForm();
	choose->Show();
}
};
}
