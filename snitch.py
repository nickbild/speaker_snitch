import sys
import requests


# Note: This is surely an incomplete list of IPs, based on about 30 minutes of my own observations.
googleIPs = ("74.125.136.94", "173.194.219.147", "173.194.147.203", "173.194.60.135", "108.177.122.106")
snitch_host = "192.168.1.136"


for line in sys.stdin:
    for ip in googleIPs:
        if ip in line:
            requests.get("http://{}/on".format(snitch_host))
