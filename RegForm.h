#pragma once
#include "GUI.h"

namespace chessMTUCI {

	using namespace System;
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
	public ref class RegForm : public System::Windows::Forms::Form
	{
	public:
		RegForm(void)
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
		~RegForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ UsName;
	protected:
	private: System::Windows::Forms::Label^ Psword;
	private: System::Windows::Forms::TextBox^ UserName;
	private: System::Windows::Forms::TextBox^ Pasword;
	private: System::Windows::Forms::Label^ REG;
	private: System::Windows::Forms::Button^ ConfirmReg;


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
			this->Psword = (gcnew System::Windows::Forms::Label());
			this->UserName = (gcnew System::Windows::Forms::TextBox());
			this->Pasword = (gcnew System::Windows::Forms::TextBox());
			this->REG = (gcnew System::Windows::Forms::Label());
			this->ConfirmReg = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// UsName
			// 
			this->UsName->AutoSize = true;
			this->UsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UsName->Location = System::Drawing::Point(12, 62);
			this->UsName->Name = L"UsName";
			this->UsName->Size = System::Drawing::Size(100, 24);
			this->UsName->TabIndex = 1;
			this->UsName->Text = L"UserName";
			// 
			// Psword
			// 
			this->Psword->AutoSize = true;
			this->Psword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Psword->Location = System::Drawing::Point(12, 118);
			this->Psword->Name = L"Psword";
			this->Psword->Size = System::Drawing::Size(83, 24);
			this->Psword->TabIndex = 2;
			this->Psword->Text = L"Pasword";
			// 
			// UserName
			// 
			this->UserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UserName->Location = System::Drawing::Point(118, 65);
			this->UserName->Name = L"UserName";
			this->UserName->Size = System::Drawing::Size(262, 22);
			this->UserName->TabIndex = 3;
			// 
			// Pasword
			// 
			this->Pasword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Pasword->Location = System::Drawing::Point(118, 121);
			this->Pasword->Name = L"Pasword";
			this->Pasword->Size = System::Drawing::Size(262, 22);
			this->Pasword->TabIndex = 4;
			// 
			// REG
			// 
			this->REG->AutoSize = true;
			this->REG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->REG->Location = System::Drawing::Point(200, 9);
			this->REG->Name = L"REG";
			this->REG->Size = System::Drawing::Size(126, 24);
			this->REG->TabIndex = 5;
			this->REG->Text = L"Регистарция";
			// 
			// ConfirmReg
			// 
			this->ConfirmReg->BackColor = System::Drawing::Color::Plum;
			this->ConfirmReg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ConfirmReg->Location = System::Drawing::Point(279, 197);
			this->ConfirmReg->Name = L"ConfirmReg";
			this->ConfirmReg->Size = System::Drawing::Size(202, 81);
			this->ConfirmReg->TabIndex = 6;
			this->ConfirmReg->Text = L"Зарегестрироваться ";
			this->ConfirmReg->UseVisualStyleBackColor = false;
			this->ConfirmReg->Click += gcnew System::EventHandler(this, &RegForm::ConfirmReg_Click);
			// 
			// RegForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Thistle;
			this->ClientSize = System::Drawing::Size(504, 290);
			this->Controls->Add(this->ConfirmReg);
			this->Controls->Add(this->REG);
			this->Controls->Add(this->Pasword);
			this->Controls->Add(this->UserName);
			this->Controls->Add(this->Psword);
			this->Controls->Add(this->UsName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"RegForm";
			this->Text = L"RegForm";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		String^ SendHttpRequest(String^ url, String^ method, String^ jsonData) {
			try {
				HttpWebRequest^ request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(url));
				request->Method = method;
				request->ContentType = "application/json";
				request->Timeout = 5000;

				if (method->ToUpper() == "POST" && jsonData->Length > 0) {
					array<Byte>^ data = Encoding::UTF8->GetBytes(jsonData);
					request->ContentLength = data->Length;

					Stream^ stream = request->GetRequestStream();
					stream->Write(data, 0, data->Length);
					stream->Close();
				}
				HttpWebResponse^ response = dynamic_cast<HttpWebResponse^> (request->GetResponse());
				StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
				String^ result = reader->ReadToEnd();
				reader->Close();
				response->Close();
				return result;
			}
			catch (WebException^ ex) {
				if (ex->Response != nullptr) {
					HttpWebResponse^ errorResponse = dynamic_cast<HttpWebResponse^>(ex->Response);
					StreamReader^ reader = gcnew StreamReader(errorResponse->GetResponseStream());
					String^ errorText = reader->ReadToEnd();
					reader->Close();
					return "{\"success\":false,\"message\":\"HTTP Error:" + errorResponse->StatusCode.ToString() + "\",\"error\":\"" + errorText + "\"}";
				}
				return "{\"success\":false,\"message\":\"Network error: " + ex->Message + "\"}";
			}
			catch (Exception^ ex) {
				return "{\"success\":false,\"message\":\"Error: " + ex->Message + "\"}";
			}
		}

		bool ParseJsonResponse(String^ jsonResponse, [Runtime::InteropServices::Out] String^% message) {
			message = "";
			try {
				jsonResponse = jsonResponse->Trim();
				Console::WriteLine("Parsing json: " + jsonResponse);
				if (!jsonResponse->StartsWith("{") || !jsonResponse->EndsWith("}")) {
					message = "Invalid json format: " + jsonResponse;
					return false;
				}
				String^ cleanJson = jsonResponse->Replace(" ", "")->Replace("\t", "")->Replace("\n", "")->Replace("\r", "");
				int successIndex = cleanJson->IndexOf("\"success\":");
				if (successIndex == -1) {
					message = "No 'success' field founf in: " + jsonResponse;
					return false;
				}
				int valueStart = successIndex + 10;
				String^ successValue = cleanJson->Substring(valueStart, 4);

				bool isSuccess = false;
				if (successValue->StartsWith("true")) {
					isSuccess = true;
				}
				else if (successValue->StartsWith("false")) {
					isSuccess = false;
				}
				else {
					message = "Invalid success value: " + successValue;
					return false;
				}
				int messageIndex = cleanJson->IndexOf("\"message\":\"");
				if (messageIndex != -1) {
					int messageStart = messageIndex + 11;
					int messageEnd = cleanJson->IndexOf("\"", messageStart);
					if (messageEnd > messageStart) {
						message = cleanJson->Substring(messageStart, messageEnd - messageStart);
					}
					else {
						message = isSuccess ? "Operation successful" : "Operation failed";
					}
				}
				else {
					messageIndex = cleanJson->IndexOf("\"message\":");
					if (messageIndex != -1) {
						int messageStart = messageIndex + 10;
						int messageEnd = cleanJson->IndexOf(",", messageStart);
						if (messageEnd == -1) {
							messageEnd = cleanJson->IndexOf("}", messageStart);
						}
						if (messageEnd > messageStart) {
							message = cleanJson->Substring(messageStart, messageEnd - messageStart);
							message = message->Trim('\"');
						}
					}
					else {
						message = isSuccess ? "Success" : "Unknow error";
					}
				}
				return isSuccess;
			}
			catch (Exception^ ex) {
				message = "JSON parsing error: " + ex->Message + "\nResponse was: " + jsonResponse;
				return false;
			}

		}


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ConfirmReg_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = UserName->Text->Trim();
		String^ password = Pasword->Text->Trim();

		if (String::IsNullOrEmpty(username)) {
			MessageBox::Show("Введите username", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			UserName->Focus();
			return;
		}
		if (username->Length < 3) {
			MessageBox::Show("username должен состоять минимум из 3 символов ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			UserName->Focus();
			return;
		}
		if (password->Length < 6) {
			MessageBox::Show("Пароль дожлен состоять минимум из 6 символов", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			Pasword->Focus();
			return;
		}
		Cursor = Cursors::WaitCursor;
		ConfirmReg->Enabled = false;

		try {
			String^ jsonData = "{\"username\":\"" + username + "\",\"password\":\"" + password + "\"}";
			String^ serverUrl = "http://localhost:8000/api/register";
			MessageBox::Show("Отправляю запрос на: " + serverUrl + "\nДанные: " + jsonData, "Отладка", MessageBoxButtons::OK, MessageBoxIcon::Information);
			String^ response = SendHttpRequest(serverUrl, "POST", jsonData);
			MessageBox::Show("Ответ сервера:\n" + response, "Ответ", MessageBoxButtons::OK, MessageBoxIcon::Information);
			String^ message;
			bool success = ParseJsonResponse(response, message);
			if (success) {
				MessageBox::Show(message + "\n\nТеперь вы можете входить используя вашу учетные данные.", "Регистрация прошла успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Hide();
				GUI^ choose = gcnew GUI();
				choose->Show();
			}
			else {
				MessageBox::Show("Регистрация не удалась:\n" + message, "Ошибка регистрации", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка" + ex->Message, "Ошибка сети", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			Cursor = Cursors::Default;
			ConfirmReg->Enabled = true;
		}
	}
};
}
