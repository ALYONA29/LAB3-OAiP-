//---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>
using namespace std;
#pragma hdrstop

#include "main.h"
#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List list;
Node *s = list.getLast();
bool ed1 = true, ed2 = true, ed3 = true, ed4 = true, ed5 = true, ed6 = true, ed7 = true, ed8 = true, ed9 = true, ed10 = true;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	s = list.getLast();
	String sur, n, f, tab2, h2, t2;
	int tab, h;
    float t;
	double p;
	int checker = 0;
	sur = Edit1->Text;
	int len = sur.Length();
	n = Edit2->Text;
	f = Edit3->Text;
	tab2 = Edit4->Text;
	h2 = Edit5->Text;
	t2 = Edit6->Text;
	if (Edit1->Text == "" || Edit2->Text == "" || Edit3->Text == "" || Edit4->Text == "" || Edit5->Text == "" || Edit6->Text == "")
	{
	   ShowMessage("Введите данные");
	}
	else
	{
		tab = StrToInt(Edit4->Text);
		h = StrToInt(Edit5->Text);
		t = StrToFloat(Edit6->Text);
		if (h > 144)
		{
			p = ((h - 144) * 2 * t) + 144 * t;
		}
		else
		{
			p = h * t;
		}
		s = list.Add(sur, n, f, tab, h, t, p, s);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1->Clear();
	if (list.isEmpty())
	{
		Memo1->Lines->Add("Список пуст");
	}
	else
	{
		Node *p = list.getFirst();
		do
		{
			Memo1->Lines->Add("------------------------");
			Memo1->Lines->Add("Фамилия : " + list.getSurname(p));
			Memo1->Lines->Add("Имя : " + list.getName(p));
			Memo1->Lines->Add("Отчество : " + list.getFathername(p));
			Memo1->Lines->Add("Табельный номер : " + IntToStr(list.getValue(p)));
			Memo1->Lines->Add("Количество часов : " + IntToStr(list.getHours(p)));
			Memo1->Lines->Add("Тариф : " + FloatToStrF(list.getTarif(p), ffFixed, 7, 3));
			Memo1->Lines->Add("Зарплата : " + FloatToStrF(list.getPay(p), ffFixed, 7, 3));
			Memo1->Lines->Add("------------------------");
			p = list.Next(p);
		} while (p != NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if (list.isEmpty())
	{
		Memo1->Lines->Add("Список пуст");
	}
	else if (Edit7->Text == "")
	{
		ShowMessage("Введите запрос");
	}
	else
	{
		Node *p = list.getFirst();
		int checker = 0;
		int choice = StrToInt(Edit7->Text);
		do
		{
			if (list.getValue(p) == choice)
			{
				p = list.Delete(p);
				checker++;
				break;
			}
			else
			{
				p = list.Next(p);
			}
		} while (p != NULL);
		if (checker == 0)
		{
			ShowMessage("Такого человека нет");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Memo1->Clear();
    Memo1->ScrollBars = ssBoth;
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();
	Edit5->Clear();
	Edit6->Clear();
	Edit7->Clear();
	Edit8->Clear();
	Edit9->Clear();
	Edit10->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Clear();
    if (list.isEmpty())
	{
		Memo1->Lines->Add("Список пуст");
	}
    else if (Edit8->Text == "")
	{
		ShowMessage("Введите запрос");
	}
	else
	{
		Node *p = list.getFirst();
		int checker = 0;
		String choice = Edit8->Text;
		do
		{
			if (list.getSurname(p) == choice)
			{
				checker++;
				Memo1->Lines->Add("------------------------");
				Memo1->Lines->Add("Фамилия : " + list.getSurname(p));
				Memo1->Lines->Add("Имя : " + list.getName(p));
				Memo1->Lines->Add("Отчество : " + list.getFathername(p));
				Memo1->Lines->Add("Табельный номер : " + IntToStr(list.getValue(p)));
				Memo1->Lines->Add("Количество часов : " + IntToStr(list.getHours(p)));
				Memo1->Lines->Add("Тариф : " + FloatToStrF(list.getTarif(p), ffFixed, 7, 3));
				Memo1->Lines->Add("Зарплата : " + FloatToStrF(list.getPay(p), ffFixed, 7, 3));
				Memo1->Lines->Add("------------------------");
				p = list.Next(p);
			}
			else
			{
				p = list.Next(p);
			}
		} while (p != NULL);
		if (checker == 0)
		{
			ShowMessage("Такого человека нет");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Clear();
    if (list.isEmpty())
	{
		Memo1->Lines->Add("Список пуст");
	}
    else if (Edit9->Text == "")
	{
		ShowMessage("Введите запрос");
	}
	else
	{
		Node *p = list.getFirst();
		int checker = 0;
		int choice = StrToInt(Edit9->Text);
		do
		{
			if (list.getHours(p) >= choice)
			{
				checker++;
				Memo1->Lines->Add("------------------------");
				Memo1->Lines->Add("Фамилия : " + list.getSurname(p));
				Memo1->Lines->Add("Имя : " + list.getName(p));
				Memo1->Lines->Add("Отчество : " + list.getFathername(p));
				Memo1->Lines->Add("Табельный номер : " + IntToStr(list.getValue(p)));
				Memo1->Lines->Add("Количество часов : " + IntToStr(list.getHours(p)));
				Memo1->Lines->Add("Тариф : " + FloatToStrF(list.getTarif(p), ffFixed, 7, 3));
				Memo1->Lines->Add("Зарплата : " + FloatToStrF(list.getPay(p), ffFixed, 7, 3));
				Memo1->Lines->Add("------------------------");
				p = list.Next(p);
			}
			else
			{
				p = list.Next(p);
			}
		} while (p != NULL);
		if (checker == 0)
		{
			ShowMessage("Таких людей нет");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Clear();
    if (list.isEmpty())
	{
		Memo1->Lines->Add("Список пуст");
	}
	else
	{
		Node *p = list.getFirst();
		int checker = 0;
		int choice = 144;
		do
		{
			if (list.getHours(p) > choice)
			{
				checker++;
				Memo1->Lines->Add("------------------------");
				Memo1->Lines->Add("Фамилия : " + list.getSurname(p));
				Memo1->Lines->Add("Имя : " + list.getName(p));
				Memo1->Lines->Add("Отчество : " + list.getFathername(p));
				Memo1->Lines->Add("Табельный номер : " + IntToStr(list.getValue(p)));
				Memo1->Lines->Add("Количество часов : " + IntToStr(list.getHours(p)));
				Memo1->Lines->Add("Тариф : " + FloatToStrF(list.getTarif(p), ffFixed, 7, 3));
				Memo1->Lines->Add("Зарплата : " + FloatToStrF(list.getPay(p), ffFixed, 7, 3));
				Memo1->Lines->Add("------------------------");
				p = list.Next(p);
			}
			else
			{
				p = list.Next(p);
			}
		} while (p != NULL);
		if (checker == 0)
		{
			ShowMessage("Таких людей нет");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Memo1->Clear();
    if (list.isEmpty())
	{
		Memo1->Lines->Add("Список пуст");
	}
    else if (Edit10->Text == "")
	{
		ShowMessage("Введите запрос");
	}
	else
	{
		Node *p = list.getFirst();
		int checker = 0;
		float choice = StrToFloat(Edit10->Text);
		do
		{
			if (list.getPay(p) >= choice)
			{
				checker++;
				Memo1->Lines->Add("------------------------");
				Memo1->Lines->Add("Фамилия : " + list.getSurname(p));
				Memo1->Lines->Add("Имя : " + list.getName(p));
				Memo1->Lines->Add("Отчество : " + list.getFathername(p));
				Memo1->Lines->Add("Табельный номер : " + IntToStr(list.getValue(p)));
				Memo1->Lines->Add("Количество часов : " + IntToStr(list.getHours(p)));
				Memo1->Lines->Add("Тариф : " + FloatToStrF(list.getTarif(p), ffFixed, 7, 3));
		    	Memo1->Lines->Add("Зарплата : " + FloatToStrF(list.getPay(p), ffFixed, 7, 3));
				Memo1->Lines->Add("------------------------");
				p = list.Next(p);
			}
			else
			{
				p = list.Next(p);
			}
		} while (p != NULL);
		if (checker == 0)
		{
		   ShowMessage("Таких людей нет");
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyPress(TObject *Sender, System::WideChar &Key)
{
	 if((Key < '0' || Key > '9')&& Key != VK_BACK && Key != VK_DELETE && Key != 13)
	 {
		if(ed4)
		{
			ShowMessage("Недопустимый символ! Доступен ввод целых чисел. В дальнейшем это сообщение отображаться не будет.");
		}
		ed4 = false;
		Key = NULL;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5KeyPress(TObject *Sender, System::WideChar &Key)
{
	if((Key < '0' || Key > '9')&& Key != VK_BACK && Key != VK_DELETE && Key != 13)
	{
		if(ed5)
		{
			ShowMessage("Недопустимый символ! Доступен ввод целых чисел. В дальнейшем это сообщение отображаться не будет.");
		}
		ed5 = false;
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6KeyPress(TObject *Sender, System::WideChar &Key)
{
	 if(((Key < '0' || Key > '9') && Key != VK_BACK && Key != VK_DELETE && Key != 13 && Key != 44 && Key != 45) || Key == 46)
	 {
		if(ed6)
		{
			ShowMessage("Недопустимый символ! Доступен ввод целых или дробных чисел. В дальнейшем это сообщение отображаться не будет.");
		}
		ed6 = false;
		Key = NULL;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7KeyPress(TObject *Sender, System::WideChar &Key)
{
    if((Key < '0' || Key > '9')&& Key != VK_BACK && Key != VK_DELETE && Key != 13)
	{
		if(ed7)
		{
			ShowMessage("Недопустимый символ! Доступен ввод целых чисел. В дальнейшем это сообщение отображаться не будет.");
		}
		ed7 = false;
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit9KeyPress(TObject *Sender, System::WideChar &Key)
{
    if((Key < '0' || Key > '9')&& Key != VK_BACK && Key != VK_DELETE && Key != 13)
	{
		if(ed9)
		{
			ShowMessage("Недопустимый символ! Доступен ввод целых чисел. В дальнейшем это сообщение отображаться не будет.");
		}
		ed9 = false;
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit10KeyPress(TObject *Sender, System::WideChar &Key)
{
    if(((Key < '0' || Key > '9') && Key != VK_BACK && Key != VK_DELETE && Key != 13 && Key != 44 && Key != 45) || Key == 46)
	{
		if(ed10)
		{
			ShowMessage("Недопустимый символ! Доступен ввод целых или дробных чисел. В дальнейшем это сообщение отображаться не будет.");
		}
		ed10 = false;
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if(((Key < 97 && Key > 90) || Key > 122 || Key < 65) &&  Key != VK_BACK && Key != VK_DELETE && Key != 45)
	 {
		 if(ed1)
		 {
			 ShowMessage("Недопустимый символ! Доступен ввод английских прописных и строчных букв и знака -");
		 }
		 ed1 = false;
		 Key = NULL;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
    if(((Key < 97 && Key > 90) || Key > 122 || Key < 65) &&  Key != VK_BACK && Key != VK_DELETE && Key != 45)
	 {
		 if(ed2)
		 {
			 ShowMessage("Недопустимый символ! Доступен ввод английских прописных и строчных букв и знака -");
		 }
		 ed2 = false;
		 Key = NULL;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
    if(((Key < 97 && Key > 90) || Key > 122 || Key < 65) &&  Key != VK_BACK && Key != VK_DELETE && Key != 45)
	 {
		 if(ed3)
		 {
			 ShowMessage("Недопустимый символ! Доступен ввод английских прописных и строчных букв и знака -");
		 }
		 ed3 = false;
		 Key = NULL;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8KeyPress(TObject *Sender, System::WideChar &Key)
{
    if(((Key < 97 && Key > 90) || Key > 122 || Key < 65) &&  Key != VK_BACK && Key != VK_DELETE && Key != 45)
	 {
		 if(ed8)
		 {
			 ShowMessage("Недопустимый символ! Доступен ввод английских прописных и строчных букв и знака -");
		 }
		 ed8  = false;
		 Key = NULL;
	 }
}
//---------------------------------------------------------------------------

