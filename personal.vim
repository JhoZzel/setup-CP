" PLUGINS
call plug#begin()
    Plug 'jiangmiao/auto-pairs'
    Plug 'joshdick/onedark.vim'         "tema
call plug#end()

" THEME SETTINGS
colorscheme onedark  
"set termguicolors             "activa el true color en la terminal

" BASIC SETTINGS
syntax on
set mouse=a
set number
set showcmd
set encoding=utf-8
set showmatch
set tabstop=4
set shiftwidth=4
set expandtab
set clipboard=unnamedplus " The copy is kept on the clipboard

" ===================== FUNCIONES UTILES =====================
function! RunExecutable()
  " Obtener el nombre del archivo fuente sin extensión
  let sourceFile = expand('%:t')
  let baseName = substitute(sourceFile, '\.cpp$', '', '')

  " Nombre del ejecutable basado en el nombre del archivo fuente
  let exeName = './' . baseName

  if filereadable(exeName)
    let cmd = "gnome-terminal -- bash -c '" . exeName . "; echo; read -p \"Presiona enter para salir...\"'"
    call system(cmd)
    redraw!
  else
    echohl ErrorMsg
    echomsg "No se encontró el ejecutable " . exeName
    echohl None
  endif
endfunction


function! RunInTXT()
  " Obtener el nombre del archivo fuente sin extensión
  let sourceFile = expand('%:t')
  let baseName = substitute(sourceFile, '\.cpp$', '', '')

  " Definir nombres de archivos
  let exeName = './' . baseName
  let inputFile = 'in'
  let outputFile = 'out'
  let dbgFile = 'dbg'

  " Verificar si el archivo ejecutable existe
  if filereadable(exeName)
    " Ejecutar el archivo si el ejecutable existe
    silent! execute '!rm ' . outputFile
    let runCmd = exeName . ' < ' . inputFile . ' > ' . outputFile . ' 2> ' . dbgFile
    call system(runCmd)
    redraw!
    echo 'Output file generated successfully'
  else
    " Mostrar mensaje de error si el ejecutable no existe
    echohl ErrorMsg
    echomsg exeName . ' was not found'
    echohl None
  endif
endfunction


" COMMANDS, MAPS AND SHORTCUTS
command! -range=% Cp <line1>,<line2>w !xclip -selection clipboard


map <F6> :call RunExecutable()<CR>
map <F7> :call RunInTXT()<CR>

nnoremap <F5> :w<CR>:!g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 -o %< %<.cpp<CR>
nnoremap <Tab> :tabnext<CR>
nnoremap <S-Tab> :tabprev<CR>

" Función para copiar plantilla al crear un nuevo archivo .cpp
"autocmd BufNewFile *.cpp 0r /home/jhozzel/Templates/template.cpp
