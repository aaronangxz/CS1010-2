import os
import time
from subprocess import Popen, PIPE, STDOUT, run
# from applescript import tell
from applescript import tell
#set what command you want to run here

# yourCommand = 'cd hungrylehbot'
# tell.app( 'Terminal', 'do script "' + yourCommand + '"') 
# time.sleep(2)
# tell.app('System Events').keystroke('\r')
# Popen('gnome-terminal')
# p1 = Popen(['open', '-a', 'Terminal', '-n'], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
# # p1.communicate('hungrylehbot')
# def run_commands(*commands):
#     run(' ;'.join(commands),shell = True)
# run_commands('cd hungrylehbot', 'ls')

os.system("gnome-terminal -e 'bash -c \"cd hungrylehbot\" '")

# subprocess.Popen(["gnome-terminal", "-c", "'cd hungrylehbot; herokulogs -n 5'"])
# def subprocess_cmd(command):
#     process = subprocess.Popen(command,stdout=subprocess.PIPE, shell=True)

# subprocess_cmd('hungrylehbot; echo b')

# command= "python3 --version"
# Popen(["gnome-terminal","python3 --version"])
# os.system("gnome-terminal -e ""python3 --version""")

# os.system("gnome-terminal -e 'bash -c \""+command+";bash\"'")
