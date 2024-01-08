from flask import Flask, render_template, url_for

app = Flask(__name__)


@app.route('/sendForm.html')
def sendForm():
    return render_template('sendForm.html')


@app.route('/contacts.html')
def contacts():
    return render_template('contacts.html')


@app.route('/')
def index():
    return render_template('index.html')


if __name__ == '__main__':
    app.run(debug=True)