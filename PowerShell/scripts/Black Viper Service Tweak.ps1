# This script applies all BlackViper "Desktop (Tweaked)" service configurations to your machine.  USE WITH CAUTION.
# http://www.blackviper.com/service-configurations/black-vipers-windows-10-service-configurations/
# Script requires admin privilegs.  Please make sure the admin function exists on your machine.
Restart-ScriptAsAdmin
Set-Service AJRouter -startuptype "disabled"
Set-Service ALG -startuptype "disabled"
Set-Service AppMgmt -startuptype "disabled"
Set-Service BthHFSrv -startuptype "disabled"
Set-Service BranchCache -startuptype "disabled"
Set-Service CertPropSvc -startuptype "disabled"
Set-Service dmwappushsvc -startuptype "disabled"
Set-Service MapsBroker -startuptype "disabled"
Set-Service Ifsvc -startuptype "disabled"
Set-Service HvHost -startuptype "disabled"
Set-Service vmickvpexchange -startuptype "disabled"
Set-Service vmicguestinterface -startuptype "disabled"
Set-Service vmicshutdown -startuptype "disabled"
Set-Service vmicheartbeat -startuptype "disabled"
Set-Service vmicvmsession -startuptype "disabled"
Set-Service vmicrdv -startuptype "disabled"
Set-Service vmictimesync -startuptype "disabled"
Set-Service vmicvss -startuptype "disabled"
Set-Service irmon -startuptype "disabled"
Set-Service SharedAccess -startuptype "disabled"
Set-Service iphlpsvc -startuptype "disabled"
Set-Service IpxlatCfgSvc -startuptype "disabled"
Set-Service wlpasvc -startuptype "disabled"
Set-Service SessionEnv -startuptype "disabled"
Set-Service TermService -startuptype "disabled"
Set-Service UmRdpService -startuptype "disabled"
Set-Service RpcLocator -startuptype "disabled"
Set-Service RetailDemo -startuptype "disabled"
Set-Service SensorDataService -startuptype "disabled"
Set-Service SensrSvc -startuptype "disabled"
Set-Service SensorService -startuptype "disabled"
Set-Service ScDeviceEnum -startuptype "disabled"
Set-Service SCPolicySvc -startuptype "disabled"
Set-Service SNMPTRAP -startuptype "disabled"
Set-Service TabletInputService -startuptype "disabled"
Set-Service WebClient -startuptype "disabled"
Set-Service WFDSConSvc -startuptype "disabled"
Set-Service FrameServer -startuptype "disabled"
Set-Service wcncsvc -startuptype "disabled"
Set-Service wisvc -startuptype "disabled"
Set-Service WMPNetworkSvc -startuptype "disabled"
Set-Service icssvc -startuptype "disabled"
Set-Service WinRM -startuptype "disabled"
Set-Service WwanSvc -startuptype "disabled"
