#pragma once

#include <ESP8266WiFi.h>
#include <FTPduino.h>

#define DEBUG_LecteurFTP false
#define FTP_FREQUENCE 55000
#define FTP_DEFAULT_PORT 21

class LecteurFTP {
	private:
	   FTPduino FTPclient;
	   bool          _udpSetup       = true;
	
	   char* _ftpSrv;
	   char* _ftpUsr;
	   char* _ftpPsw;
//	   char* _ftpFile;
//	   char* _ftpRep;
	   constexpr static const char* _ftpFile = "MonFichier.txt";
	   constexpr static const char* _ftpRep = "/";
	   unsigned int  _ftpPort = FTP_DEFAULT_PORT;
	   long          _timeOffset     = 0;
	
	   unsigned long _ftpFreq = FTP_FREQUENCE;  // In ms
	   unsigned long _lastUpdate     = 0;      // In ms
	   String		   _contenuLU;
	
	   void	contenuLU();
	   char*	fileSize;
	   long	fileTime;
	   bool	status = true;
	
	public:
		LecteurFTP(char* _ftpSrv, char* _ftpUsr, char* _ftpPsw, char* _ftpFile) : FTPclient() {}


    /**
     * Set time server name
     * @param poolServerName
     */
    void setftpSrv(const char* ftpSrv);
    void setftpPort(unsigned int ftpPort);

    /**
     * This should be called in the main loop of your application. By default an update from the NTP Server is only
     * made every 60 seconds. This can be configured in the LecteurFTP constructor.
     *
     * @return true on success, false on failure
     */
    bool update();
    /**
     * This will force the update from the NTP Server.
     *
     * @return true on success, false on failure
     */
    bool forceUpdate();

    /**
     * Définition des commandes accessibles à l'usager
     */
   bool Connexion();
	void setFreq(unsigned int ftpFreq);
	void setFrequency(unsigned int ftpFreq);
	void setServerName(char* ServerName);
	void setServerUser(char* ServerUser);
	void setServerPswd(char* ServerPassword);
	void setDirectory(char* ServerRep);
	void setFileName(char* FileName);
	void setPort(int ServPort);

    /**
     * Définition des valeurs retournées par l'objet
     */
    String getText();
    long getTime();
    int getSize();

    //Vérifions ici si la connexion Wifi est bien active
    bool getStatus();

    /**
     * Demande de déconnexion Wifi
     */
    void end();
};
