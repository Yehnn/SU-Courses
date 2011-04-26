#include "UserInterface.h"

using namespace Client ;


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	EndPoint rep("127.0.0.1",2107);
	EndPoint sep("127.0.0.1",0311);

	// MsgSender_Proc is your sender's server message handling
	//   If you don't have sender server file handling don't 
	//   attach a file handler
	Communicator sndr(sep);
	sndr.setFileSource(".\\FilePostTest\\Sender\\");
	MsgHandler<MsgSender_Proc> smsgHandler;
	sndr.attachMsgHandler(&smsgHandler);
	sndr.listen();

	// The MsgReceiver_Proc and FileReceiver_Proc
	// should connect when they have a reply, so
	// don't connect the receiver - that's done
	// by your server code (see above)

	if(!sndr.connect("127.0.0.1",2107))
	{
		sout << "\n  failed to connect sndr\n\n";
		return 0;
	}


	sout<<"  start posting\n";

	// Create the main window and run it
	


	//_getche();


	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	UserInterface^ ui = gcnew UserInterface(&sndr);
	MessageHandler* mh = new MessageHandler(ui);
	ui->SetMessageHandler(mh);
	Ider::Message msg = mh->MessageForSending(Ider::MsgType::Login);
	sndr.postMessage(msg);

	//Application::Run(ui);
	Application::Run(ui);

	delete mh;
	return 0;
}