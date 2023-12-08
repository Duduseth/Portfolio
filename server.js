const express = require('express');
const bodyParser = require('body-parser');
const mysql = require('mysql');

const app = express();
//const PORT = process.env.PORT || 3000;
const PORT = process.env.PORT || 21148;

// view engine setup
app.set('views', __dirname);
app.set('view engine', 'ejs');

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());


/*
// Configuração do MySQL
const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'chuveiro',
  port: 3306
});
*/



// Configuração do MySQL
const db = mysql.createConnection({
  host: 'mysql.chuveirointeligente.kinghost.net',
  user: 'chuveirointeli',
  password: 'putzgr1l4',
  database: 'chuveirointeli',
  port: 3306
});



db.connect((err) => {
  if (err) {
    console.error('Erro ao conectar ao banco de dados MySQL:', err);
  } else {
    console.log('Conexão bem-sucedida ao banco de dados MySQL');
  }
});



app.get('/', (req, res) => {
  if (!global.usuariocodigo || global.usuariocodigo == 0)
  {
    res.redirect('/login');
  }
  else
  {
    res.redirect('/eventos');
  }
});


app.get('/sair', function(req, res){
  global.usuariocodigo = 0
  res.redirect('/')
})

app.get('/login', function(req, res){
  res.render('login')
})


app.post('/login', async function(req, res){
  const usuario = req.body.edtUsuario 
  const senha   = req.body.edtSenha
  
  if (usuario == "eduardo" && senha == "teste")
  {
    global.usuariocodigo = 1;
    global.usuariologin  = usuario;
    res.redirect('/eventos');
  }
  else
  {
    res.redirect('/login');
  }
})



app.get('/eventos', (req, res) => {
  if (!global.usuariocodigo || global.usuariocodigo == 0)
  {
    res.redirect('/login')
  }

  db.query("SELECT * FROM users", (err, registros) => {
    if (err) {
      console.error(err);
      // Trate o erro de alguma forma
      return;
    }

    console.log(registros);
    res.render("index", { registros });
  });
});



app.get('/apagar/:id', (req, res) => {
  if (!global.usuariocodigo || global.usuariocodigo == 0)
  {
    res.redirect('/login')
  }
  
  const codigo = parseInt(req.params.id);
  db.query("delete from users where id=?", [codigo], (err,result) => {
    if (err) {
      console.error('Erro ao apagar usuário no banco de dados:', err);
      res.status(500).send('Erro ao apagar usuário no banco de dados');
    } 
  });
  res.redirect('/')
});



app.post('/api/cadastrar-usuario', (req, res) => {
  if (!global.usuariocodigo || global.usuariocodigo == 0)
  {
    res.redirect('/login')
  }

  const nome = req.body.nome;
  const banhos = !req.body.banhos ? null : parseInt(req.body.banhos)
  const minutos = !req.body.minutos ? null : parseInt(req.body.minutos)

  // Adiciona o novo usuário ao banco de dados MySQL
  const query = 'INSERT INTO users (nome, banhos, minutos) VALUES (?, ?, ?)';
  db.query(query, [nome, banhos, minutos], (err, result) => {
    if (err) {
      console.error('Erro ao cadastrar usuário no banco de dados:', err);
      res.status(500).send('Erro ao cadastrar usuário no banco de dados');
    } 
    /*
    else {
      console.log(`Usuário cadastrado - ID: ${result.insertId}, Nome: ${nome}, Banhos por Dia: ${banhos}, Minutos por Banho: ${minutos}`);
      res.send('Usuário cadastrado com sucesso.');
    } */

    res.redirect('/');
  });


});



app.listen(PORT, () => {
  console.log(`Servidor rodando em http://localhost:${PORT}`);
});
