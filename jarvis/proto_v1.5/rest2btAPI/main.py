#!flask/bin/python
import json
import logging
import threading

import bluetooth
from flask import Flask, jsonify, request
from flask import Response
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

device_mac_addr = "00:1B:10:30:45:A3"
device_name = "ELET_SPP_3045A3"

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

readingflag=True

def init_loggin_conf():
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")


@app.route('/command', methods=['POST'])
def post_command():
    logging.info("Receive command:" + str(request.json))
    sock.send("$" + str(request.json) + "#")
    return Response("", status=200, mimetype='application/json')

@app.route('/init', methods=['POST'])
def post_init():
    logging.info("Init bluetooth connection:" + str(request.data))
    sock.connect((device_mac_addr, 3))
    reading_thread = threading.Thread(target=thread_read_intput)
    reading_thread.start()
    return Response("", status=200, mimetype='application/json')

@app.route('/close', methods=['POST'])
def post_close():
    logging.info("Close bluetooth connection:" + str(request.data))
    readingflag=False
    sock.close()
    return Response("", status=200, mimetype='application/json')

def thread_read_intput():
    while(readingflag):
        logging.info(sock.recv(1024))



def main():
    init_loggin_conf()
    logging.info("Laucch bluetooth app")
    logging.info(bluetooth.lookup_name(device_mac_addr))
    app.run(debug=True, port=5001, host='0.0.0.0')


if __name__ == '__main__':
    main()
