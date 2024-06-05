" PLUGINS
call plug#begin('~/.vim/plugged')
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
function! CompileCPP()
  let fileName = expand('%:t') " Get the file name with extension
  if fileName =~ '\.cpp$'
    let exeName = 'a.out'
    execute 'w | !g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 -o ' . exeName . ' ' . fileName
    if v:shell_error == 0
      echo "Compilation successful: " . exeName
    else
      echo "Compilation failed"
    endif
  else
    echo 'Not a C++ file'
  endif
endfunction


function! RunExecutable()
  let exeName = './a.out'
  if filereadable(exeName)
    let cmd = "gnome-terminal -- bash -c '" . exeName . "; echo; read -p \"Press enter to exit...\"'"
    call system(cmd)
    redraw!
  else
    echo "Executable " . exeName . " not found"
  endif
endfunction


function! RunInTXT()
  let exeName = './a.out'
  let inputFile = 'in' 
  let outputFile = 'out' 
  let dbgFile = 'dbg'

  if filereadable(exeName)
    silent! execute '!rm ' . outputFile
    let runCmd = exeName . ' < ' . inputFile . ' > ' . outputFile . ' 2> ' . dbgFile
    call system(runCmd)
    redraw! 
    echo 'Archivo de salida generado correctamente'
  else
    echohl ErrorMsg
    echomsg 'Error: No se encontró el ejecutable ' . exeName
    echohl None
  endif
endfunction


" COMMANDS, MAPS AND SHORTCUTS
command! -range=% Cp <line1>,<line2>w !xclip -selection clipboard

map <F5> :call CompileCPP()<CR>
map <F6> :call RunExecutable()<CR>
map <F7> :call RunInTXT()<CR>

nnoremap <Tab> :tabnext<CR>
nnoremap <S-Tab> :tabprev<CR>

