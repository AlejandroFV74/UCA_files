import { Author } from "../models/author.model";

export const getAllAuthors = async (Author) => {
    let authors = [];
    try {
        for (let i = 0; i < Author.length; i++) {
            let existAuthor = book.authors.find(author => author.i.toString() === authorId);
            authors.push(authorId)
            
        }
        
    } catch (error) {
        throw new ServiceError('Error al añadir autores',
            AuthorErrorCodes.Author_Not_Found);
    }
}