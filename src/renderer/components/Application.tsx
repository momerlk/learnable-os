import React, { useEffect, useRef, useCallback , useState } from 'react';
import '@styles/app.scss';
import icons from '@components/icons';

import { RouterProvider , createBrowserRouter } from 'react-router-dom';
import { useLocation } from 'react-router-dom';





const Application: React.FC = () => {
  const [counter, setCounter] = useState(0);
  const [darkTheme, setDarkTheme] = useState(true);
  const [versions, setVersions] = useState<Record<string, string>>({});

  const openTerminal = () => {
    // Execute a command to open the Windows Command Prompt
  };

  /**
   * On component mount
   */
  useEffect(() => {
    const useDarkTheme = parseInt(localStorage.getItem('dark-mode'));
    if (isNaN(useDarkTheme)) {
      setDarkTheme(false);
    } else if (useDarkTheme == 1) {
      setDarkTheme(false);
    } else if (useDarkTheme == 0) {
      setDarkTheme(false);
    }

    // Apply verisons
    const app = document.getElementById('app');
    const versions = JSON.parse(app.getAttribute('data-versions'));
    setVersions(versions);
  }, []);

  /**
   * On Dark theme change
   */
  useEffect(() => {
    if (darkTheme) {
      localStorage.setItem('dark-mode', '1');
      document.body.classList.add('dark-mode');
    } else {
      localStorage.setItem('dark-mode', '0');
      document.body.classList.remove('dark-mode');
    }
  }, [darkTheme]);

  /**
   * Toggle Theme
   */
  function toggleTheme() {
    setDarkTheme(!darkTheme);
  }

  let onChange = (input : any) => {
    console.log("Input changed", input);
  }

  let onKeyPress = (button : any) => {
    console.log("Button pressed", button);
  }

  return (
    <div id='erwt'>
      <div className='header'>
        <div className='main-heading'>
          <h1 style={{color : "white"}}>WELCOME TO YOUR LEARNABLE!</h1>
        </div>

        <input></input>
        
        <button onClick={openTerminal}>Open Terminal</button>
        
        
      </div>

      
    </div>
  );
};

const router = createBrowserRouter([
  {
    path: "/app_window/",
    element: <Application />,
  },
  {
    path: "/app_window/hello",
    element: <div>Hello world!</div>,
  },
]);

function App() {

  return (
    <RouterProvider router={router}/>
  );
}
export default App;
