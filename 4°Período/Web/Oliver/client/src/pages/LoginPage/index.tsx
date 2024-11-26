import { ChangeEvent, useState } from 'react'
import './index.css'
import axios from 'axios'

export function LoginPage() {
  const [form, setForm] = useState({
    username: '',
    password: ''
  })

  const onChangeForm = (event: ChangeEvent<HTMLInputElement>) => {
    const { name, value } = event.target

    setForm((previousForm) => {
      return {
        ...previousForm,
        [name]: value
      }
    })
  }

  const onClickLogin = () => {
    console.log(`cadastro user com username ${form.username}, senha ${form.password}`)
    console.log(form)

    axios.post('http://localhost:8080/login', form)
      .then((response) => {
        console.log(response)
      }).catch((error) => {
        console.log(error)
      })
  }

  return (
    <main className="form-signin w-100 m-auto">
      <form>
        <div className="text-center">
          <h1 className="h3 mb-3 fw-normal">
            Login
          </h1>
        </div>
        <div className="form-floating">
          <input type="text" className="form-control" placeholder="Informe o seu username" name="username" id="username" onChange={onChangeForm} value={form.username} />
          <label htmlFor="username">Informe o seu username</label>
        </div>
        <div className="form-floating">
          <input type="password" className="form-control" placeholder="Informe a sua senha" name="password" id="password" onChange={onChangeForm} value={form.password} />
          <label htmlFor="password">Informe a sua senha</label>
        </div>
        <div>
          <div className="text-center">
            <button type="button" className="btn btn-primary" onClick={onClickLogin}>Login</button>
          </div>
        </div>
      </form>
    </main>
  )
}