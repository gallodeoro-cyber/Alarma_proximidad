from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def inicio():

    try:

        with open("estado.txt", "r") as archivo:
            estado = archivo.read()

    except:
        estado = "NORMAL"

    return render_template("index.html", estado=estado)

if __name__ == "__main__":
    app.run(debug=True)
