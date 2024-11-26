import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import  'bootstrap/dist/css/bootstrap.min.css'
import { LoginPage } from './pages/LoginPage'
import { UserSignupPage } from './pages/UserSignupPage'

createRoot(document.getElementById('root')!).render(
  <StrictMode>
    <UserSignupPage />
    <LoginPage />
  </StrictMode>,
)
