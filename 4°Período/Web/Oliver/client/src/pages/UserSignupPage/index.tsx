import { ChangeEvent, useState } from 'react';
import './index.css'
import axios from 'axios';

export function UserSignupPage() {
  const [form, setForm] = useState({
    displayName: '',
    username: '',
    password: ''
  })

  const [errors, setErrors] = useState({
    displayName: '',
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

    setErrors((previousForm) => {
      return {
        ...previousForm,
        [name]: undefined
      }
    })
  }
  

  const onClickSignup = () => {
    console.log(`cadastro user com nome ${form.displayName}, username ${form.username}, senha ${form.password}`)
    console.log(form)

    axios.post('http://localhost:8080/users', form)
      .then((response) => {
        console.log(response)
      }).catch((error) => {
        console.log(error)
        if (error.response.data.validationErrors) {
          setErrors(error.response.data.validationErrors)
        }
      })
  }

  return (
    <main className="form-signup w-100 m-auto">
      <form>
        <div className="text-center">
          <h1 className="h3 mb-3 fw-normal">
            Novo Usuário - {form.displayName}
          </h1>
        </div>
        <div className="form-floating">
          <input type="text" className={errors.displayName ? "form-control is-invalid": "form-control"} placeholder="Informe o seu nome" name="displayName" id="displayName" onChange={onChangeForm} value={form.displayName} />
          <label htmlFor="displayName">Informe o seu nome</label>
          {errors.displayName && (<div className="invalid-feedback">{errors.displayName}</div>)}
        </div>
        <div className="form-floating">
          <input type="text" className={errors.username ? "form-control is-invalid": "form-control"} placeholder="Informe o seu username" name="username" id="username" onChange={onChangeForm} value={form.username} />
          <label htmlFor="username">Informe o seu username</label>
          {errors.username && (<div className="invalid-feedback">{errors.username}</div>)}
        </div>
        <div className="form-floating">
          <input type="password" className={errors.password ? "form-control is-invalid": "form-control"} placeholder="Informe a sua senha" name="password" id="password" onChange={onChangeForm} value={form.password} />
          <label htmlFor="password">Informe a sua senha</label>
          {errors.password && (<div className="invalid-feedback">{errors.password}</div>)}
        </div>
        <div>
          <div className="text-center">
            <button type="button" className="btn btn-primary" onClick={onClickSignup}>Cadastrar</button>
          </div>
        </div>
      </form>
    </main>
  )
}